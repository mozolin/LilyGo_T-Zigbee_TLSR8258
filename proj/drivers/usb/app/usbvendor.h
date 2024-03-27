/********************************************************************************************************
 * @file	usbvendor.h
 *
 * @brief	This is the header file for usbvendor
 *
 * @author	Driver & Zigbee Group
 * @date	2019
 *
 * @par     Copyright (c) 2019, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *
 *          Redistribution and use in source and binary forms, with or without
 *          modification, are permitted provided that the following conditions are met:
 *
 *              1. Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *
 *              2. Unless for usage inside a TELINK integrated circuit, redistributions
 *              in binary form must reproduce the above copyright notice, this list of
 *              conditions and the following disclaimer in the documentation and/or other
 *              materials provided with the distribution.
 *
 *              3. Neither the name of TELINK, nor the names of its contributors may be
 *              used to endorse or promote products derived from this software without
 *              specific prior written permission.
 *
 *              4. This software, with or without modification, must only be used with a
 *              TELINK integrated circuit. All other usages are subject to written permission
 *              from TELINK and different commercial license may apply.
 *
 *              5. Licensee shall be solely responsible for any claim to the extent arising out of or
 *              relating to such deletion(s), modification(s) or alteration(s).
 *
 *          THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *          ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *          WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *          DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
 *          DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *          (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *          LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *          ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *          (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *          SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************************************/
#pragma once

#include "usbvendor_i.h"

/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
    extern "C" {
#endif


typedef void (*hidvendor_handlerFn_t)(u8 *pData);

typedef struct {
    u16 len;
    u8  data[1];
} hidvendor_txBuf_t;

typedef struct {
    u8 *rxBuf;
    hidvendor_txBuf_t *txBuf;

	/* Following variables are used in the RX more than CDC_TXRX_EPSIZE */
    ev_timer_event_t *timer;

	hidvendor_handlerFn_t rxCb;
	hidvendor_handlerFn_t txCb;

	u16 lenToSend;
	u16 lastSendIndex;
	u8  lastIndex;
} hidvendor_ctrl_t;

typedef enum hidvendor_sts_e {
	HID_VENDOR_SUCCESS  = 0,
	HID_VENDOR_BUSY 	= 1,
	HID_VENDOR_MULTIBLOCK,
} hidvendor_sts_t;

/**
 * @brief This function used to send or receive data as the USB vendor device
 * @param   none
 * @return  none
 */
void hidvendor_dataHandler(void);

/**
 * @brief This function initializes the USB vendor device
 * @param   none
 * @return none
 */
void hidvendor_init(void);

/**
 * @brief This function sets the USB vendor tx and rx callback function
 * @param[in]   rxFunc rx callback function
 * @param[in]   txCb tx callback function
 * @return none
 */
void hidvendor_setCb(hidvendor_handlerFn_t rxFunc, hidvendor_handlerFn_t txCb);

/**
 * @brief This function sets the USB vendor rx buffer
 * @param[in]   buf pointer to the rx buffer
 * @return none
 */
void hidvendor_setRxBuf(u8 *buf);

/**
 * @brief This function sends data to host as the USB vendor device
 * @param[in]   buf pointer to the data need to send
 * @param[in]   len length in byte of the data need to send
 * @return none
 */
hidvendor_sts_t hidvendor_reportData(hidvendor_txBuf_t *txBuf);

/**
 * @brief This function determines whether the USB interface is available
 * @param   none
 * @return 1: the USB interface is available 0: the USB interface is busy
 */
u8 hidvendor_isAvailable(void);

/**
 * @brief This function used to check whether the Tx of the control endpoint is busy
 * @param   none
 * @return 1: the control endpoint is busy 0: the control endpoint is idle
 */
u8 hidvendor_isTxBusy(void);

/* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
    }
#endif
