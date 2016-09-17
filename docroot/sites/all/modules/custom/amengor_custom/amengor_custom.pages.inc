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