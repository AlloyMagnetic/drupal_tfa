<?php

class TfaTestFallback extends TfaBasePlugin implements TfaValidationPlugin {

  public function __construct(array $context = array()) {
    parent::__construct($context);
    $this->code = 'FAILSAFE';
  }

  public function getForm($form) {
    $form['recover'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter recovery code'),
      '#required' => TRUE,
    );
    $form['login'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
    return $form;
  }

  public function validateForm(&$form_state) {
    if (!parent::validate($form_state['values']['recover'])) {
      $this->errorMessages['code'] = t('Invalid recovery code');
      return FALSE;
    }
    else {
      return TRUE;
    }
  }
}