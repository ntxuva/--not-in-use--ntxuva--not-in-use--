<?php
/**
 * @file
 * ntxuva_mopa_default_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ntxuva_mopa_default_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
