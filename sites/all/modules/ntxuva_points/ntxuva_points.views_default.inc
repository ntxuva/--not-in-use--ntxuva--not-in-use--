<?php
/**
 * @file
 * ntxuva_points.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ntxuva_points_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'points_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Points View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'google_map';
  $handler->display->display_options['style_options']['map_height'] = '600px';
  $handler->display->display_options['style_options']['map_zoom'] = '7';
  $handler->display->display_options['style_options']['map_min_zoom'] = '1';
  $handler->display->display_options['style_options']['map_max_zoom'] = '19';
  $handler->display->display_options['style_options']['marker_title_field'] = 'name';
  $handler->display->display_options['style_options']['use_marker_clusterer'] = 0;
  $handler->display->display_options['style_options']['marker_clusterer'] = array(
    'grid_size' => '',
    'max_zoom' => '',
    'icon_url' => '',
    'icon_size' => '',
  );
  $handler->display->display_options['style_options']['map_auto_center_and_zoom'] = 1;
  $handler->display->display_options['style_options']['map_disable_scroll_wheel'] = 0;
  $handler->display->display_options['style_options']['map_disable_double_click_zoom'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Address String */
  $handler->display->display_options['fields']['field_address_string']['id'] = 'field_address_string';
  $handler->display->display_options['fields']['field_address_string']['table'] = 'field_data_field_address_string';
  $handler->display->display_options['fields']['field_address_string']['field'] = 'field_address_string';
  $handler->display->display_options['fields']['field_address_string']['label'] = '';
  $handler->display->display_options['fields']['field_address_string']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_string']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Código';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_geo']['id'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo']['table'] = 'field_data_field_geo';
  $handler->display->display_options['fields']['field_geo']['field'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo']['label'] = '';
  $handler->display->display_options['fields']['field_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geo']['click_sort_column'] = 'lat';
  $handler->display->display_options['fields']['field_geo']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_geo_1']['id'] = 'field_geo_1';
  $handler->display->display_options['fields']['field_geo_1']['table'] = 'field_data_field_geo';
  $handler->display->display_options['fields']['field_geo_1']['field'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo_1']['label'] = '';
  $handler->display->display_options['fields']['field_geo_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geo_1']['click_sort_column'] = 'lat';
  $handler->display->display_options['fields']['field_geo_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'points' => 'points',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'points-view';
  $translatables['points_view'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Código'),
    t('Page'),
  );
  $export['points_view'] = $view;

  return $export;
}
