/* Copyright (c) 2023 MCCI Corporation. All rights reserved.
 *
 * EU433 433MHz frequency plan
 * Based on LoRaWAN Regional Parameters v1.0.3
 */

#pragma once

#ifndef _lorabase_eu433_h_
#define _lorabase_eu433_h_

// EU433 frequency bands (MHz)
enum {
    EU433_F1 = 433175000,  // Default channel 1
    EU433_F2 = 433375000,  // Default channel 2
    EU433_F3 = 433575000,  // Default channel 3
    EU433_F4 = 433775000,  // g4  433.775 MHz
    EU433_F5 = 433975000,  // g5  433.975 MHz
    EU433_F6 = 434175000,  // g6  434.175 MHz
    EU433_F7 = 434375000,  // g7  434.375 MHz
    EU433_F8 = 434575000,  // g8  434.575 MHz
    EU433_F9 = 434775000,  // g9  434.775 MHz
    EU433_F10 = 434975000, // g10 434.975 MHz
    EU433_F11 = 435175000, // g11 435.175 MHz
    EU433_F12 = 435375000, // g12 435.375 MHz
    EU433_FREQ_BCN_DEFAULT = 434665000  // Beacon/RX2 default
};

// Default frequency limits for listen before talk
#define EU433_LBT_FREQ_MIN      433050000
#define EU433_LBT_FREQ_MAX      434790000  // Matches spec 433.05-434.79MHz

// Duty cycle limitations - 1% (100ms/h) for most channels
#define EU433_DUTY_CYCLE_ENABLED 1

// Data rates (LoRaWAN Regional Parameters v1.0.3)
enum {
    EU433_DR_SF12 = 0,
    EU433_DR_SF11,
    EU433_DR_SF10,
    EU433_DR_SF9,
    EU433_DR_SF8,
    EU433_DR_SF7,
    EU433_DR_SF7B,  // FSK
    EU433_DR_NONE,
    EU433_DR_FSK = EU433_DR_SF7B,
    
    // Datarate bounds
    EU433_DR_MIN = EU433_DR_SF12,
    EU433_DR_MAX = EU433_DR_SF7,
    
    // Defaults
    EU433_DR_DNW2 = EU433_DR_SF12,
    EU433_DR_BCN = EU433_DR_SF9,
    EU433_DR_PING = EU433_DR_SF9,
    
    // Page identifiers
    DR_PAGE_EU433 = 0x10
};

// Maximum EIRP (dBm)
enum {
    EU433_LMIC_REGION_EIRP = 1215  // Represent 12.15dBm in centi-dBm
};

// Beacon uses CR 4/5 as per spec
#define EU433_BEACON_CR    CR_4_5

// Based on Table 30/31
enum {
    EU433_MAX_PAYLOAD_LEN_REPEATER = 230,
    EU433_MAX_PAYLOAD_LEN_NO_REPEATER = 250,
    EU433_MAX_PAYLOAD_LEN_JOIN = 59  // For join requests
};

// Add to lorabase_eu433.h
enum {
    EU433_SYNCWORD_LORA = 0x34,
    EU433_SYNCWORD_FSK  = 0xC194C1
};

#endif /* _lorabase_eu433_h_ */
