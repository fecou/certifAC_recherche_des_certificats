<?php
/**
 * @file
 * recherche_des_certificats.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function recherche_des_certificats_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function recherche_des_certificats_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function recherche_des_certificats_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_page_page_recherche_certificats'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_page_page_recherche_certificats",
    "name" : "page recherche certificats",
    "index_id" : "recherche_certificats",
    "type" : "search_api_page",
    "enabled" : "1",
    "options" : {
      "custom" : { "page_id" : "page_recherche_certificats" },
      "result count" : true,
      "fields" : [],
      "results" : 0,
      "min_length" : "3"
    },
    "rdf_mapping" : []
  }');
  $items['search_api_views_cert'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_cert",
    "name" : "cert",
    "index_id" : "recherche_certificats",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "result count" : true,
      "fields" : [],
      "results" : 0,
      "min_length" : "3",
      "custom" : { "display" : "page" }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function recherche_des_certificats_default_search_api_index() {
  $items = array();
  $items['recherche_certificats'] = entity_import('search_api_index', '{
    "name" : "recherche_certificats",
    "machine_name" : "recherche_certificats",
    "description" : "Recherche de certificats",
    "server" : "fecou_dr_database_serveur",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "created" : { "type" : "date" },
        "field_code_postal" : { "type" : "integer" },
        "field_num_ro_op_rateur" : { "type" : "integer" },
        "field_raison_sociale" : { "type" : "string" },
        "field_ressource:file" : { "type" : "integer", "entity_type" : "file" },
        "field_ville" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "certificat" : "certificat" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "raison sociale",
                "type" : "fulltext",
                "fields" : [ "field_raison_sociale" ],
                "description" : "A Fulltext aggregation of the following fields: raison sociale."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_code_postal" : true,
              "field_num_ro_op_rateur" : true,
              "field_raison_sociale" : true,
              "field_ville" : true,
              "field_ressource:file" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "field_code_postal" : true,
              "field_num_ro_op_rateur" : true,
              "field_raison_sociale" : true,
              "field_ville" : true,
              "field_ressource:file" : true
            },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "search_api_viewed" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027 ]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_raison_sociale" : true, "field_ville" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function recherche_des_certificats_default_search_api_page() {
  $items = array();
  $items['page_recherche_certificats'] = entity_import('search_api_page', '{
    "index_id" : "recherche_certificats",
    "path" : "recherche\\/certificats",
    "name" : "page recherche certificats",
    "machine_name" : "page_recherche_certificats",
    "description" : "Une page pour chercher les certificats",
    "options" : {
      "mode" : "single",
      "fields" : [],
      "per_page" : "5",
      "result_page_search_form" : 1,
      "get_per_page" : 1,
      "view_mode" : "full"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function recherche_des_certificats_default_search_api_server() {
  $items = array();
  $items['fecou_dr_database_serveur'] = entity_import('search_api_server', '{
    "name" : "fecou dr database serveur",
    "machine_name" : "fecou_dr_database_serveur",
    "description" : "fecou dr database serveur",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 1,
      "indexes" : { "recherche_certificats" : {
          "nid" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_code_postal" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "field_code_postal",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_num_ro_op_rateur" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "field_num_ro_op_rateur",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_raison_sociale" : {
            "table" : "search_api_db_recherche_certificats",
            "type" : "string",
            "boost" : "1.0",
            "column" : "field_raison_sociale"
          },
          "field_ville" : {
            "table" : "search_api_db_recherche_certificats",
            "type" : "string",
            "boost" : "1.0",
            "column" : "field_ville"
          },
          "search_api_language" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_ressource:file" : {
            "table" : "search_api_db_recherche_certificats",
            "column" : "field_ressource_file",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_recherche_certificats_text_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_recherche_certificats_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
