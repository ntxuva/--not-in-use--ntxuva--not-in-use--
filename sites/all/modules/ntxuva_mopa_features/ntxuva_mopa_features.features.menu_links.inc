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

  // Exported menu link: management_printer-email-and-pdf-versions:admin/config/user-interface/print
  $menu_links['management_printer-email-and-pdf-versions:admin/config/user-interface/print'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/print',
    'router_path' => 'admin/config/user-interface/print',
    'link_title' => 'Printer, email and PDF versions',
    'options' => array(
      'attributes' => array(
        'title' => 'Adds a printer-friendly version link to content and administrative pages.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_printer-email-and-pdf-versions:admin/config/user-interface/print',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_user-interface:admin/config/user-interface',
  );
  // Exported menu link: user-menu_processos:processos
  $menu_links['user-menu_processos:processos'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'processos',
    'router_path' => 'processos',
    'link_title' => 'Processos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_processos:processos',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Printer, email and PDF versions');
  t('Processos');


  return $menu_links;
}
