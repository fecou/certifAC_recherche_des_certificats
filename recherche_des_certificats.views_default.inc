<?php
/**
 * @file
 * recherche_des_certificats.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function recherche_des_certificats_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cert';
  $view->description = 'Permet l\'affichage d\'un formulaire de recherche et des résultats pour les certificats';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_recherche_certificats';
  $view->human_name = 'Recherche de certificats';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recherche de certificats';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Plus de résultats';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'single';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Nombre d\'éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['tags']['first'] = '« Premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ Précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Dernier »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_raison_sociale' => 'field_raison_sociale',
    'field_num_ro_op_rateur' => 'field_num_ro_op_rateur',
    'field_code_postal' => 'field_code_postal',
    'field_ville' => 'field_ville',
    'field_ressource' => 'field_ressource',
  );
  $handler->display->display_options['style_options']['default'] = 'field_raison_sociale';
  $handler->display->display_options['style_options']['info'] = array(
    'field_raison_sociale' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_num_ro_op_rateur' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_code_postal' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ville' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ressource' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Indexed Node: raison sociale */
  $handler->display->display_options['fields']['field_raison_sociale']['id'] = 'field_raison_sociale';
  $handler->display->display_options['fields']['field_raison_sociale']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['fields']['field_raison_sociale']['field'] = 'field_raison_sociale';
  /* Field: Indexed Node: numéro opérateur */
  $handler->display->display_options['fields']['field_num_ro_op_rateur']['id'] = 'field_num_ro_op_rateur';
  $handler->display->display_options['fields']['field_num_ro_op_rateur']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['fields']['field_num_ro_op_rateur']['field'] = 'field_num_ro_op_rateur';
  $handler->display->display_options['fields']['field_num_ro_op_rateur']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_num_ro_op_rateur']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: code postal */
  $handler->display->display_options['fields']['field_code_postal']['id'] = 'field_code_postal';
  $handler->display->display_options['fields']['field_code_postal']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['fields']['field_code_postal']['field'] = 'field_code_postal';
  $handler->display->display_options['fields']['field_code_postal']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_code_postal']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: ville */
  $handler->display->display_options['fields']['field_ville']['id'] = 'field_ville';
  $handler->display->display_options['fields']['field_ville']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['fields']['field_ville']['field'] = 'field_ville';
  /* Field: Indexed Node: certificat pdf */
  $handler->display->display_options['fields']['field_ressource']['id'] = 'field_ressource';
  $handler->display->display_options['fields']['field_ressource']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['fields']['field_ressource']['field'] = 'field_ressource';
  $handler->display->display_options['fields']['field_ressource']['click_sort_column'] = 'fid';
  /* Sort criterion: Indexed Node: raison sociale */
  $handler->display->display_options['sorts']['field_raison_sociale']['id'] = 'field_raison_sociale';
  $handler->display->display_options['sorts']['field_raison_sociale']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['sorts']['field_raison_sociale']['field'] = 'field_raison_sociale';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'certificat' => 'certificat',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_recherche_certificats';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Recherche de certificats';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'Saisissez une raison sociale, un numéro d\'opérateur, un code postal ou une ville';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Raison sociale',
      'operator' => 'OR',
      'value' => 'raison_sociale',
    ),
    2 => array(
      'title' => 'Ville',
      'operator' => 'OR',
      'value' => 'ville',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'certificats';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Certificats';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['cert'] = array(
    t('Master'),
    t('Recherche de certificats'),
    t('Plus de résultats'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Nombre d\'éléments par page'),
    t('- All -'),
    t('Offset'),
    t('« Premier'),
    t('‹ Précédent'),
    t('Suivant ›'),
    t('Dernier »'),
    t('raison sociale'),
    t('numéro opérateur'),
    t('code postal'),
    t('ville'),
    t('certificat pdf'),
    t('Saisissez une raison sociale, un numéro d\'opérateur, un code postal ou une ville'),
    t('Fulltext search'),
    t('Page'),
    t('more'),
  );
  $export['cert'] = $view;

  return $export;
}
