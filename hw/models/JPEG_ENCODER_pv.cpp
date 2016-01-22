
/**************************************************************/
/*                                                            */
/*      Copyright Mentor Graphics Corporation 2006 - 2015     */
/*                  All Rights Reserved                       */
/*                                                            */
/*       THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY      */
/*         INFORMATION WHICH IS THE PROPERTY OF MENTOR        */
/*         GRAPHICS CORPORATION OR ITS LICENSORS AND IS       */
/*                 SUBJECT TO LICENSE TERMS.                  */
/*                                                            */
/**************************************************************/

//*<
//* Generated By Model Builder, Mentor Graphics Computer Systems, Inc.
//*
//* This file contains the PV class for JPEG_ENCODER.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 4.2alpha1
//* Generated on: Jan. 22, 2016 08:40:43 AM, (user: jon)
//* Automatically merged on: Jan. 22, 2016 08:51:39 AM, (user: jon)
//*>



#include "JPEG_ENCODER_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
JPEG_ENCODER_pv::JPEG_ENCODER_pv(sc_module_name module_name) 
  : JPEG_ENCODER_pv_base(module_name) {
  irq.initialize (false);
}   

/////////////////////////////////////////////////////////////////////////////////
// Use these functions to define the behavior of your model when there is a 
// write event on one of the registers as defined in the Model Builder form.
// These functions are called before the write callbacks on the port.
///////////////////////////////////////////////////////////////////////////////// 

// Write callback for start register.
// The newValue has been already assigned to the start register.
void JPEG_ENCODER_pv::cb_write_start(unsigned long long newValue) {
  unsigned char d;

  cout << sc_time_stamp() <<": "<< name() <<"cb_write_start received "<< start << endl;

  if (start == 0) {
   irq.write(false); 
  } else {
   master_read(inputaddr, &d, 1);
   d++;
   master_write(outputaddr, d);
   irq.write(true); 
  }
}
    

// Read callback for slave port.
// Returns true when successful.
bool JPEG_ENCODER_pv::slave_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}

// Write callback for slave port.
// Returns true when successful.
bool JPEG_ENCODER_pv::slave_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
} 




unsigned JPEG_ENCODER_pv::slave_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned JPEG_ENCODER_pv::slave_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool JPEG_ENCODER_pv::slave_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}

 
void JPEG_ENCODER_pv::cb_transport_dbg_start(tlm::tlm_generic_payload& trans) {}
