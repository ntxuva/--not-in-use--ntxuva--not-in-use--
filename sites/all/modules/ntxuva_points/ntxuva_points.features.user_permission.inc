<?php
/**
 * @file
 * ntxuva_points.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ntxuva_points_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in points'.
  $permissions['delete terms in points'] = array(
    'name' => 'delete terms in points',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in points'.
  $permissions['edit terms in points'] = array(
    'name' => 'edit terms in points',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
