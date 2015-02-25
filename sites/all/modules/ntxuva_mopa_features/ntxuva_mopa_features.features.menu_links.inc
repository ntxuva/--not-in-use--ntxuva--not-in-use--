<?php
/**
 * @file
 * ntxuva_mopa_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ntxuva_mopa_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_gesto:gestao
  $menu_links['user-menu_gesto:gestao'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'gestao',
    'router_path' => 'gestao',
    'link_title' => 'Gestão',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_gesto:gestao',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Gestão');


  return $menu_links;
}
