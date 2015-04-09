<?php
/**
 * @file
 * mopa_distritos.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mopa_distritos_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in distrito_bairro'.
  $permissions['delete terms in distrito_bairro'] = array(
    'name' => 'delete terms in distrito_bairro',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in distrito_bairro'.
  $permissions['edit terms in distrito_bairro'] = array(
    'name' => 'edit terms in distrito_bairro',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
