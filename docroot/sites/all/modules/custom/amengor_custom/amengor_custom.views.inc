<?php

/**
 * Implements hook_query_TAG_alter().
 */
function amengor_custom_query_ka_products_alter(QueryAlterableInterface $query) {
  $query->groupBy('node.nid');
}
