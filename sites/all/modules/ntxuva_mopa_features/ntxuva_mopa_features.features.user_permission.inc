<?php
/**
 * @file
 * ntxuva_mopa_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ntxuva_mopa_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'Management' => 'Management',
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print_ui',
  );

  return $permissions;
}
