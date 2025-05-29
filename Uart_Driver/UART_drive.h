﻿/*
 * UART_drive.h
 *
 * Created: 11/01/2018 11:38:54 ص
 *  Author: DELL
 */ 


#ifndef UART_DRIVE_H_
#define UART_DRIVE_H_
#include <avr/io.h>
#include <util/delay.h>

enum BAUD_RATE_E{
	BAUD_RATE_2400,
	BAUD_RATE_4800,
	BAUD_RATE_9600
};

enum DATA_SIZE_E{
	DATA_SIZE_7,
	DATA_SIZE_8,
	DATA_SIZE_9
};

enum STOP_BITS_E{
	STOP_BITS_1,
	STOP_BITS_2
};

enum PARITY_MODE_E{
	PARITY_MODE_OFF,
	PARITY_MODE_ODD,
	PARITY_MODE_EVEN
};

enum ERROR_FLAG_E{
	NO_ERROR,
	ERROR
	};

enum TRANSMITTER_STATUS_E{
	BUSY,
	OK
};

enum RECEIVER_STATUS_E{
	EMPTY,
	FULL,
};

struct UART_RX_DATA_S{
	enum ERROR_FLAG_E ERROR_STATUS;
	enum RECEIVER_STATUS_E RECEIVER_STATUS;
	unsigned short DATA_RECEIVED ;
	};
	

struct UART_CONFIG_S{
	enum BAUD_RATE_E BAUD_RATE_VALUE;
	enum DATA_SIZE_E DATA_SIZE_VALUE;
	enum STOP_BITS_E STOP_BTS_VALUE;
	enum PARITY_MODE_E PARITY_MODE_VALUE;		
	};

enum ERROR_FLAG_E UART_INIT(struct UART_CONFIG_S uart_conf);
enum TRANSMITTER_STATUS_E UART_Transmitter(unsigned short DATA);
struct UART_RX_DATA_S UART_Receive();



#endif /* UART_DRIVE_H_ */