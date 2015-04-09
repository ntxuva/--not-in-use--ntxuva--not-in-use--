<?php
/**
 * @file
 * mopa_distritos.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mopa_distritos_taxonomy_default_vocabularies() {
  return array(
    'distrito_bairro' => array(
      'name' => 'Distrito/Bairro',
      'machine_name' => 'distrito_bairro',
      'description' => 'Maputo está dividida em sete distritos municipais, que se encontram, por sua vez, divididos em bairros e povoações',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
