/**
 * @file
 * Javascript for editing the bbox.
 */

(function ($) {
  $(document).ready(function(){
    var mopa = Drupal.settings.mopa;
    var tileUrl = 'http://{s}.tile.osm.org/{z}/{x}/{y}.png',
      osm = new L.TileLayer(tileUrl, {maxZoom: 18}),
      map = new L.Map('settings-map', {layers: [osm], center: new L.LatLng(mopa.ntxuva_ini_lat, mopa.ntxuva_ini_lng), zoom: 15 });

    var drawnItems = new L.FeatureGroup();
    map.addLayer(drawnItems);

    var drawControl = new L.Control.Draw({
      draw: {
        position: 'topleft',

        polyline: false,
        polygon: false,
        marker: false,
        circle: false

      },
      edit: {
        featureGroup: drawnItems
      }
    });
    map.addControl(drawControl);
    L.control.locate().addTo(map);

    map.on('draw:edited', function (e) {
      var layers = e.layers;
      layers.eachLayer(function (layer) {
        var bbox = layer.getBounds();
        setBbox(bbox);
      });
    });

    map.on('draw:created', function (e) {
        var layer = e.layer;
        var bbox = layer.getBounds();
        setBbox(bbox);
        drawnItems.addLayer(layer);
    });
    function setBbox(bbox){
      $('#edit-ntxuva-logic-bbox-nw-lat').val(bbox.getNorthWest().lat);
      $('#edit-ntxuva-logic-bbox-nw-lng').val(bbox.getNorthWest().lng);

      $('#edit-ntxuva-logic-bbox-se-lat').val(bbox.getSouthEast().lat);
      $('#edit-ntxuva-logic-bbox-se-lng').val(bbox.getSouthEast().lng);

    }
  });
})(jQuery);
