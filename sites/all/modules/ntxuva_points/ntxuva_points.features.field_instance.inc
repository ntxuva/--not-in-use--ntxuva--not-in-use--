<?php
/**
 * @file
 * ntxuva_points.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ntxuva_points_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-points-field_address_string'
  $field_instances['taxonomy_term-points-field_address_string'] = array(
    'bundle' => 'points',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_address_string',
    'label' => 'Address String',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-points-field_geo'
  $field_instances['taxonomy_term-points-field_geo'] = array(
    'bundle' => 'points',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'geolocation_osm',
        'settings' => array(
          'field_formatter_class' => '',
          'leafletImagePath' => '/profiles/ntxuva/libraries/leaflet/images/',
          'map_dimensions' => '300x300',
          'map_scrollwheel' => FALSE,
          'map_zoomlevel' => 15,
          'marker_icon' => '/profiles/ntxuva/libraries/leaflet/images/marker-icon.png',
          'tile_server_dynamic' => 'http://{s}.tile.osm.org/{z}/{x}/{y}.png',
        ),
        'type' => 'geolocation_osm_dynamic',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_geo',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'geolocation',
      'settings' => array(),
      'type' => 'geolocation_text',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-points-field_lat'
  $field_instances['taxonomy_term-points-field_lat'] = array(
    'bundle' => 'points',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_lat',
    'label' => 'Lat',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-points-field_long'
  $field_instances['taxonomy_term-points-field_long'] = array(
    'bundle' => 'points',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_long',
    'label' => 'Long',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-points-field_points_icon'
  $field_instances['taxonomy_term-points-field_points_icon'] = array(
    'bundle' => 'points',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_points_icon',
    'label' => 'Points icon',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'taxonomy_term-points-field_points_id'
  $field_instances['taxonomy_term-points-field_points_id'] = array(
    'bundle' => 'points',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_points_id',
    'label' => 'points Id',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address String');
  t('Lat');
  t('Location');
  t('Long');
  t('Points icon');
  t('points Id');

  return $field_instances;
}
