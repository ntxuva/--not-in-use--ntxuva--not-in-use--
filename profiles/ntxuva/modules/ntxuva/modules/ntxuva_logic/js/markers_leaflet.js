/**
 * Ntxuva marker_leaflet.js
 *
 * Main Map-Application File with Leaflet Maps api
 *
 */
(function ($) {
  Drupal.behaviors.Ntxuva = {
    attach: function () {

      Drupal.settings.mopa = Drupal.settings.mopa || {};
      var mopa = Drupal.settings.mopa;
      Drupal.Ntxuva = {};
      Drupal.Ntxuva.maps = [];
      Drupal.Ntxuva.markers = [];
      var mapType = mopa.ntxuva_map_type;
      var pathId = mopa.params.q.split('/');

      var scrollwheelzoom =  (pathId[0] != 'list') ? 'true' : 'false';

      Drupal.Ntxuva.maps[0] = new L.Map('map', {scrollWheelZoom: scrollwheelzoom});

      // Get Data from static json module
      if (Drupal.ntxuva.static_enable() == true) {
        data = Drupal.ntxuva_static_geojson.getData();
      }

      var attribution, layer, tiles;
      switch (mapType) {
        case '0':
          attribution = mopa.osm_custom_attribution;
          layer = new L.Google('ROADMAP');
          break;
        case '1':
          tiles = 'https://{s}.tiles.mapbox.com/v3/' + mopa.mapbox_map_id + '/{z}/{x}/{y}.png';
          attribution = '<a href="http://www.mapbox.com/about/maps/" target="_blank">Terms &amp; Feedback</a>';
          layer = new L.TileLayer(tiles, {
            maxZoom: 18,
            attribution: attribution
          });
          break;
        case '2':
          tiles = mopa.osm_custom_tile_url;
          attribution = mopa.osm_custom_attribution;
          layer = new L.TileLayer(tiles, {
            maxZoom: 18,
            attribution: attribution
          });
      }
      Drupal.Ntxuva.maps[0].setView(new L.LatLng(mopa.ntxuva_ini_lat, mopa.ntxuva_ini_lng), 15).addLayer(layer);

      switch (pathId[0]) {
        case "map":
          if (Drupal.ntxuva.static_enable() != true) {
            Drupal.ntxuva.parse(1, "All", "All", false);
          } else {
            Drupal.ntxuva.parse(1, "All", "All", true);
          }

          // Add a report button
          L.easyButton('fa fa-navicon', 'topright',
            function () {
              var m = $(".leaflet-control a i.fa-navicon");
              var s = $(".leaflet-control a i.fa-times");

              if (m.hasClass('fa-navicon')) {
                m
                  .removeClass('fa-navicon')
                  .addClass('fa-times');
              } else if (s.hasClass('fa-times')) {
                s
                  .removeClass('fa-times')
                  .addClass('fa-navicon');
              }

              $('#block-ntxuva-logic-taxonomy-category, #block-ntxuva-logic-taxonomy-status').fadeToggle('fast');
            },
            Drupal.t('Report at map center'),
            Drupal.Ntxuva.maps[0]
          );


          break;
        case "list":
          Drupal.ntxuva.parse(2, "All", "All", false);
          break;
        case "node":
          Drupal.ntxuva.parse(1, "All", "All", false);
          break;

        case "admin":
          return;
      }
      $("#block-ntxuva-logic-taxonomy-category .map-menue").click(function (e) {
        e.preventDefault();
        Drupal.ntxuva.hideMarkers();
        if (Drupal.ntxuva.static_enable() != true) {
          Drupal.ntxuva.parse(1, Drupal.ntxuva.getTaxId(this.id), "All", false);
        } else {
          Drupal.ntxuva.parse(1, Drupal.ntxuva.getTaxHex($(this).attr('class')), "All", true);
        }
        return false;
      });
      $("#block-ntxuva-logic-taxonomy-status .map-menue").click(function (e) {
        e.preventDefault();
        Drupal.ntxuva.hideMarkers();
        if (Drupal.ntxuva.static_enable() != true) {
          Drupal.ntxuva.parse(2, "All", Drupal.ntxuva.getTaxId(this.id), false);
        } else {
          Drupal.ntxuva.parse(2, "All", Drupal.ntxuva.getTaxHex($(this).attr('class')), true);
        }
        return false;
      });
      $("#block-ntxuva-logic-taxonomy-category .map-menue-all").click(function (e) {
        e.preventDefault();
        Drupal.ntxuva.hideMarkers();
        if (Drupal.ntxuva.static_enable() != true) {
          Drupal.ntxuva.parse(1, "All", "All", false);
        } else {
          Drupal.ntxuva.parse(1, "All", "All", true);
        }
        return false;
      });
      $("#block-ntxuva-logic-taxonomy-status .map-menue-all").click(function (e) {
        e.preventDefault();
        Drupal.ntxuva.hideMarkers();
        if (Drupal.ntxuva.static_enable() != true) {
          Drupal.ntxuva.parse(2, "All", "All", false);
        } else {
          Drupal.ntxuva.parse(2, "All", "All", true);
        }
        return false;
      });
    }
  };


  Drupal.ntxuva = {

    /*
     * Hide Layers
     */
    hideMarkers: function () {
      Drupal.Ntxuva.maps[0].closePopup();
      Drupal.Ntxuva.maps[0].removeLayer(markerLayer);
    },

    /*
     * Actions on Marker Click and Hover
     */
    markerClickFn: function (latlon, html, id) {
      return function () {
        var target = document.getElementById('map');
        var spinner = new Spinner().spin(target);
        var map = Drupal.Ntxuva.maps[0];
        map.closePopup();
        var report_url = Drupal.settings.basePath + 'georeport/v2/requests/' + id + '.json';
        $.getJSON(report_url).success(function (data) {
          var description = data[0].description ? data[0].description : "";
          var request = data[0].media_url ? '<img style="height: 80px; margin: 10px 10px 10px 0" src="' + data[0].media_url + '" class="map img-thumbnail pull-left"><p class="report-detail">' + description + '</p>' : '<p class="report-detail">' + description + '</p>';
          request += '<div><a class="infowindow-link" href="' + Drupal.settings.basePath + 'reports/' + id + '">' + Drupal.t('read more') + '</a></div>';

          L.popup({autoPanPadding: new L.Point(10, 150)})
            .setLatLng(latlon)
            .setContent(html + request + '</div>')
            .openOn(map);
          spinner.stop();
        }).fail(function () {
          spinner.stop();
        });

        map.on('popupopen', function () {
          if ($(window).width() >= 1000) {
            $('.map.img-thumbnail').popover({
              html: true,
              trigger: 'hover',
              placement: 'left',
              content: function () {
                return '<img class="img-thumbnail" style="float:right;width:320px;max-width:320px;" src="' + $(this)[0].src + '" />';
              }
            });
          }
        });
      };
    },

    /*
     * Show Data out of filtered dataset
     */
    showData: function (getToggle, dataset) {

      var mopa = Drupal.settings.mopa;

      markerLayer = new L.MarkerClusterGroup({
        disableClusteringAtZoom: 16,
        maxClusterRadius: 20,
        animateAddingMarkers: true
      });

      var initialLatLng = new L.LatLng(mopa.ntxuva_ini_lat, mopa.ntxuva_ini_lng);
      if (dataset.length == 0) {
        bootbox.alert(Drupal.t('No reports found for this category/status'));
        return false;
      }

      $.each(dataset, function (markers, item) {
        var latlon = new L.LatLng(item.geometry.coordinates[1],item.geometry.coordinates[0]);
        item = item.properties;

        var html = '<div class="popover-report"><div class="marker-title"><h4>' + item.name + '</h4><span class="meta-info date">' + item.created + '</span><p>' + item.description + '</p></div>';
        if (item.address) {
          html += '<div class="marker-address"><p><i class="icon-li icon-location "></i> ' + item.address + '</p></div>';
        }

        var colorswitch, colors;
        colors = [{
          "color": "red", "hex": "#FF0000"
        }, {
          "color": "darkred", "hex": "#8B0000"
        }, {
          "color": "orange", "hex": "#FFA500", "iconColor": "dark-red"
        }, {
          "color": "green", "hex": "#008000"
        }, {
          "color": "darkgreen", "hex": "#006400"
        }, {
          "color": "blue", "hex": "#0000FF"
        }, {
          "color": "darkblue", "hex": "#00008B"
        }, {
          "color": "purple", "hex": "#A020F0"
        }, {
          "color": "darkpurple", "hex": "#871F78"
        }, {
          "color": "cadetblue", "hex": "#5F9EA0"
        }, {
          "color": "lightblue", "hex": "#ADD8E6", "iconColor": "#000000"
        }, {
          "color": "lightgray", "hex": "#D3D3D3", "iconColor": "#000000"
        }, {
          "color": "gray", "hex": "#808080"
        }, {
          "color": "black", "hex": "#000000"
        }, {
          "color": "beige", "hex": "#F5F5DC", "iconColor": "darkred"
        }, {
          "color": "white", "hex": "#FFFFFF", "iconColor": "#000000"
        }];
        if (getToggle == 1) {
          colorswitch = item.category_hex;
        }
        if (getToggle == 2) {
          colorswitch = item.status_hex;
        }
        $.each(colors, function (key, element) {
          if (colorswitch == element.hex) {
            var awesomeColor = element.color;
            var awesomeIcon = (getToggle == 1) ? item.category_icon : item.status_icon;
            var iconColor = element.iconColor ? element.iconColor : "#ffffff";

            var icon = L.AwesomeMarkers.icon({
              icon: awesomeIcon,
              prefix: awesomeIcon,
              markerColor: awesomeColor,
              iconColor: iconColor
            });

            var marker = new L.Marker(latlon, {
              icon:icon
            });

            markerLayer.addLayer(marker);

            // Handling waypoints.
            $('#node-' + item.nid).waypoint(function(direction) {
              if (direction === 'down') {
                Drupal.ntxuva.onScrollEvent(this, latlon, marker, icon)
              }
            },{
              offset: '40%'
            });
            $('#node-' + item.nid).waypoint(function(direction) {
              if (direction === 'up') {
                Drupal.ntxuva.onScrollEvent(this, latlon, marker, icon)
              }
            },{
              offset: '15%'
            });
            marker.on('click', Drupal.ntxuva.markerClickFn(latlon, html, item.uuid));
          }
        });

        Drupal.ntxuva.markerClickFn(latlon, html, item.uuid);

        size = markerLayer.getLayers().length;
        Drupal.Ntxuva.maps[0].addLayer(markerLayer);
      });
      if (size >= 1) {
        Drupal.Ntxuva.maps[0].fitBounds(markerLayer.getBounds());
      }
    },

    onScrollEvent: function(object, latlon, marker, icon){
      var mopa = Drupal.settings.mopa;

      var activeIcon = L.AwesomeMarkers.icon({
        icon: 'location',
        prefix: 'icon',
        markerColor: mopa.ntxuva_locate_marker_color,
        iconColor:  mopa.ntxuva_locate_icon_color
      });

      var previousWaypoint = object.previous();
      var nextWaypoint = object.next();
      if (previousWaypoint) {
        $(previousWaypoint.element).removeClass('focus');
      }
      if (nextWaypoint) {
        $(nextWaypoint.element).removeClass('focus');
      }
      $(object.element).addClass('focus');

      var map = Drupal.Ntxuva.maps[0];
      map.setZoom(mopa.ntxuva_locate_zoom).panTo(latlon);
      marker.setIcon(activeIcon);

      // Turn marker to default state.
      setTimeout(function(){
        marker.setIcon(icon);
      },1500 );

      // Move map more left on list.
      if (map.getSize().x <= 968) {
        var offset = map.getSize().x * 0.4;
        map.panBy(new L.Point(+offset, 0), {animate: true});
      } else {
        offset = map.getSize().x * 0.08;
        map.panBy(new L.Point(+offset, 0), {animate: true});
      }
    },

    /*
     * Parse data out of static or dynamic geojson
     */
    parse: function (getToggle, categoryCond, statusCond, moduleStatic) {

      var mopa = Drupal.settings.mopa;

      var target = document.getElementById('map');
      var spinner = new Spinner().spin(target);

      //Ntxuva Static Module detected, get all data via JSON in sites/default/files/geojson.
      if (moduleStatic) {

        if (categoryCond == "All" && statusCond == "All") {
          var dataset = data.features;
          Drupal.ntxuva.showData(getToggle, dataset);
        }
        if (categoryCond != "All") {
          var filter = data.features.filter(function (i) {
            return i.properties.category_hex == '#' + categoryCond;
          });
          Drupal.ntxuva.showData(getToggle, filter);
        } else if (statusCond != "All") {
          filter = data.features.filter(function (i) {
            return i.properties.status_hex == '#' + statusCond;
          });
          Drupal.ntxuva.showData(getToggle, filter);
        }
      } else {
        //No Static module detected, get all data via Drupal geojson display.
        uri = mopa.uri.split('?');
        if (uri[0].search('map') != -1 || uri[0].search('home') != -1) {
          // map view
          url = Drupal.settings.basePath + 'reports/geojson/map?' + 'category=' + categoryCond + '&status=' + statusCond;
        } else {
          url = Drupal.settings.basePath + 'reports/geojson?' + uri[1];
        }
        $.getJSON(url).done(function (data) {
          var dataset = data.features;
          Drupal.ntxuva.showData(getToggle, dataset);
        });
      }
      setTimeout(function () {
        spinner.stop();
      }, 200);

    },
    static_enable: function () {
      return (Drupal.settings.ntxuva_static_geojson) ? Drupal.settings.ntxuva_static_geojson.enable : false;
    },

    getTaxHex: function (id) {
      id = id.split(" ");
      id = id[2].split("-");
      return id[1];
    },
    getTaxId: function (id) {
      id = id.split("-");
      return id[1];
    }

  }
})(jQuery);