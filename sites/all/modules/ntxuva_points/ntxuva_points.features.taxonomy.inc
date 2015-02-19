<?php
/**
 * @file
 * ntxuva_points.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ntxuva_points_taxonomy_default_vocabularies() {
  return array(
    'points' => array(
      'name' => 'Points',
      'machine_name' => 'points',
      'description' => 'Location of Waste Collection points',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
