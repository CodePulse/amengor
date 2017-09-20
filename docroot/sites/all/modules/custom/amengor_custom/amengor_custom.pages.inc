<?php

/**
 * @return mixed
 * @throws \Exception
 */
function amengor_custom_pre_checkout() {
  $form['new_user'] = array(
    '#type' => 'markup',
    '#markup' => theme('amengor_custom_register', array(
      'login' => array(
        'url' => url('user/register'),
        'title' => t('Register an account')
      )
    )),
  );


  $form['go_to_login'] = array(
    '#type' => 'markup',
    '#markup' => theme('amengor_custom_register', array(
      'login' => array(
        'url' => url('user/login'),
        'title' => t('Login to checkout')
      )
    )),
  );

  return $form;
}

function amengor_custom_upsell_products($form, &$form_state) {
  $form['product_one'] = array(
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('product'),
    '#default_value' => variable_get('product_one'),
    '#title' => t('Upsell Product one'),
    '#required' => TRUE,
  );

  $form['product_two'] = array(
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('product'),
    '#title' => t('Upsell Product two'),
    '#default_value' => variable_get('product_two'),
    '#required' => TRUE,
  );

  $form['product_three'] = array(
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('product'),
    '#title' => t('Upsell Product three'),
    '#default_value' => variable_get('product_three'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
function amengor_custom_resend_order_confirmation($form, &$form_state) {
  $form['order_number'] = array(
    '#type' => 'textfield',
    '#default_value' => 33,
    '#title' => t('Order number'),
  );
  $form['#submit'][] = 'amengor_custom_resend_order_confirmation_submit';

  return system_settings_form($form);
}
function amengor_custom_resend_order_confirmation_submit($form, &$form_state) {
  $order = commerce_order_load($form_state['values']['order_number']);

  $params = _amengor_custom_order_details(array($order));


  $params['subject'] = 'work...please...';
//  $params['body'] = check_markup('<h1 style="color:green">testing this works! </h1>', 'full_html');
//  $params['key'] = 'order_confirmation';
//  $params['body'] = 'testing this works again!!!!';
  drupal_mail('amengor_custom', 'order_confirmation', 'ben@codepulse.co.uk', language_default(), $params);
}