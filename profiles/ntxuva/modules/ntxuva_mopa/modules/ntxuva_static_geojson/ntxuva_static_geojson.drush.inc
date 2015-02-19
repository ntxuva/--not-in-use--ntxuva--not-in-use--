<?php
/**
 * @file
 * Ntxuva-Mopa static geojson drush command file.
 */

/**
 * Implements hook_drush_command().
 */
function ntxuva_static_geojson_drush_command() {
  return array(
    'static-geojson-save-file' => array(
      'description' => dt('Creates static geoJSON file for Ntxuva-Mopa'),
      'alias' => array('geojson'),
    ),
  );
}


/**
 * Creates Static file
 */

function drush_ntxuva_static_geojson_static_geojson_save_file() {
  global $base_url;
  $json = drupal_http_request($base_url . base_path() . 'reports/geojson/map');
  $dir = 'public://geojson';
  file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
  if(isset($json->data)){
    $file = file_save_data($json->data, 'public://geojson/reports.json', FILE_EXISTS_REPLACE);
  } else {
    $message = t('GeoJSON could not be retrieved' . $json->error);
  }
  if ($file == FALSE) {
    $message = t('GeoJSON could not be written');
  }
  global $_domain;
  drush_log($message);
  watchdog('Ntxuva-Mopa', $message);
}