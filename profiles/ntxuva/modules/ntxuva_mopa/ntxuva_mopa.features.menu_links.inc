<?php
/**
 * @file
 * ntxuva_mopa.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ntxuva_mopa_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_report-issue:node/add/report
  $menu_links['main-menu_report-issue:node/add/report'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/report',
    'router_path' => 'node/add',
    'link_title' => 'Reportar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_report-issue:node/add/report',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Reportar');


  return $menu_links;
}
