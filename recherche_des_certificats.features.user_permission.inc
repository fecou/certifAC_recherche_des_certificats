<?php
/**
 * @file
 * recherche_des_certificats.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function recherche_des_certificats_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access page_recherche_certificats search_api_page'.
  $permissions['access page_recherche_certificats search_api_page'] = array(
    'name' => 'access page_recherche_certificats search_api_page',
    'roles' => array(),
    'module' => 'search_api_page',
  );

  // Exported permission: 'access search_api_page'.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_page_page_recherche_certificats'.
  $permissions['use search_api_autocomplete for search_api_page_page_recherche_certificats'] = array(
    'name' => 'use search_api_autocomplete for search_api_page_page_recherche_certificats',
    'roles' => array(),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_cert'.
  $permissions['use search_api_autocomplete for search_api_views_cert'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_cert',
    'roles' => array(),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}
