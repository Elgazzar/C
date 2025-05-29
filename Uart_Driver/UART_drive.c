/*
 * UART_drive.c
 *
 * Created: 11/01/2018 11:38:38 ص
 *  Author: DELL
 */ 

#include "UART_drive.h"

/* USARTn I/O Data Register – UDRn */

typedef union UDR_U
{
	struct{
			unsigned char data;
		}B;
		unsigned char R;
	}UDR_T;

/* USART Control and Status Register A – UCSRnA */

typedef union UCSRnA_U
{
	struct{
			unsigned char MPCMn	: 1; //LSB
			unsigned char U2Xn	: 1;
			unsigned char UPEn	: 1;
			unsigned char DORn	: 1;
			unsigned char FEn	: 1;
			unsigned char UDREn	: 1;
			unsigned char TXCn	: 1;
			unsigned char RXCn	: 1; //MSB
		}B;
		unsigned char R;
	}UCSRnA_T;

/* USARTn Control and Status Register B – UCSRnB */
	
typedef union UCSRnB_U
{
	struct{
		unsigned char TXB8n		: 1;
		unsigned char RXB8n		: 1;
		unsigned char UCSZn2	: 1;
		unsigned char TXENn		: 1;
		unsigned char RXENn		: 1;
		unsigned char UDRIEn	: 1;
		unsigned char TXCIEn	: 1;
		unsigned char RXCIEn	: 1;
	}B;
	unsigned char R;
}UCSRnB_T;

/*USART Control and Status Register C – UCSRnC */

typedef union UCSRnC_U
{
	struct{
		unsigned char UCPOLn	: 1;
		unsigned char UCSZn0	: 1;
		unsigned char UCSZn1	: 1;
		unsigned char USBSn		: 1;
		unsigned char UPMn0		: 1;
		unsigned char UPMn1		: 1;
		unsigned char UMSELn	: 1;
		unsigned char 			: 1;
	}B;
	unsigned char R;
}UCSRnC_T;

/* USART Baud Rate Registers – UBRRnL and UBRRnH */
typedef union UBRRnH_U
{
	struct {
		unsigned char UBRRn :4;
		unsigned char		:4;
		}B;
		unsigned char R;
	}UBRRnH_T;

typedef union UBRRnL_U
{
	struct {
		unsigned char UBRRn;		
	}B;
	unsigned char R;
}UBRRnL_T;


volatile UDR_T * UDRn_0 = (UDR_T *)0x2C;
volatile UCSRnA_T * UCSRnA_0 = (UCSRnA_T * )0x2B;
volatile UCSRnB_T * UCSRnB_0 = (UCSRnB_T *)0x2A;
volatile UCSRnC_T * UCSRnC_0 = (UCSRnC_T *)0x95;
volatile UBRRnH_T * UBRRnH_0 = (UBRRnH_T *)0x90;
volatile UBRRnL_T * UBRRnL_0 = (UBRRnL_T *)0x29; 
UBRR0L
struct UART_CONFIG_S local_config ; // global value to copy user configurations
enum ERROR_FLAG_E UART_INIT(struct UART_CONFIG_S uart_conf){

	enum ERROR_FLAG_E init_status = NO_ERROR;
	local_config = uart_conf;	
	/* set baud rate */
	switch(uart_conf.BAUD_RATE_VALUE)
	{
		case BAUD_RATE_2400:
				UCSRnA_0->B.U2Xn = 1;
				UBRRnL_0->R = (unsigned char)416;
				UBRRnH_0->B.UBRRn = 416>>8;	
				break;
		case BAUD_RATE_4800:
				UCSRnA_0->B.U2Xn = 0;
				UBRRnL_0->R = (unsigned char)103;
				UBRRnH_0->R = 0;
				break;
		case BAUD_RATE_9600:
				UCSRnA_0->B.U2Xn = 0;
				UBRRnL_0->R = (unsigned char)51;
				UBRRnH_0->B.UBRRn = 0;
				break;
		default:
		init_status = ERROR;
		return (init_status); 
	}
	
	/* set data size value [ 7 - 8 - 9 bits ]*/
	if(uart_conf.DATA_SIZE_VALUE == DATA_SIZE_7){
		UCSRnC_0->B.UCSZn0 = 0;
		UCSRnC_0->B.UCSZn1 = 1;
		UCSRnB_0->B.UCSZn2 = 0;		
	}
	else if(uart_conf.DATA_SIZE_VALUE == DATA_SIZE_8){
		UCSRnC_0->B.UCSZn0 = 1;
		UCSRnC_0->B.UCSZn1 = 1;
		UCSRnB_0->B.UCSZn2 = 0;
	}
	else if(uart_conf.DATA_SIZE_VALUE == DATA_SIZE_9){
		UCSRnC_0->B.UCSZn0 = 1;
		UCSRnC_0->B.UCSZn1 = 1;
		UCSRnB_0->B.UCSZn2 = 1;
	}
	
	else{
		init_status = ERROR;
		return (init_status);
	}
	/* set number of stop bits [ one - two stop bits ]*/
	if(uart_conf.STOP_BTS_VALUE == STOP_BITS_1){
		UCSRnC_0->B.USBSn = 0;
	}
	else if(uart_conf.STOP_BTS_VALUE == STOP_BITS_2){
		UCSRnC_0->B.USBSn = 1;
	}
	else{
		init_status = ERROR;
		return (init_status);
	}
	/* set parity mode */
	if(uart_conf.PARITY_MODE_VALUE == PARITY_MODE_OFF){
		UCSRnC_0->B.UPMn0 = 0;
		UCSRnC_0->B.UPMn1 = 0;
	}
	else if(uart_conf.PARITY_MODE_VALUE == PARITY_MODE_ODD){
		UCSRnC_0->B.UPMn0 = 1;
		UCSRnC_0->B.UPMn1 = 1;
	}
	else if(uart_conf.PARITY_MODE_VALUE == PARITY_MODE_EVEN){
		UCSRnC_0->B.UPMn0 = 0;
		UCSRnC_0->B.UPMn1 = 1;
	}
	else{
		init_status = ERROR;
		return (init_status);
	}
	/* enable Tx and Rx */
	UCSRnB_0->B.TXENn = 1;
	UCSRnB_0->B.RXENn = 1;
	/* set Asynchronous operation mode */
	UCSRnC_0->B.UMSELn = 0;
	/* return no error */
	return (init_status);	
	
}	
/* Transmit function */
enum TRANSMITTER_STATUS_E UART_Transmitter(unsigned short DATA) //data must be short because short is fixed 16 bits ,but integer machine Dependant
{
	enum TRANSMITTER_STATUS_E transmitter_status = OK;
	if (UCSRnA_0->B.UDREn == 0)
	{
		transmitter_status = BUSY;
		return (transmitter_status);
	}
	else if (UCSRnA_0->B.UDREn == 1)
	{
		if(local_config.DATA_SIZE_VALUE == DATA_SIZE_9){
			UCSRnB_0->B.TXB8n = DATA >> 8;
			UDRn_0->R = (unsigned char) DATA;
		}
		else{
			UDRn_0->R = (unsigned char) DATA;
		}
	}
	else{}
	return (transmitter_status);
}

/* receive function */
struct UART_RX_DATA_S UART_Receive(){
	struct UART_RX_DATA_S receiver_status;
	if(UCSRnA_0->B.RXCn == 0){
		receiver_status.RECEIVER_STATUS = EMPTY;		
	}
	else{
		receiver_status.RECEIVER_STATUS = FULL;
		if( (UCSRnA_0->B.FEn == 1) || (UCSRnA_0->B.UPEn == 1) ){
			receiver_status.ERROR_STATUS = ERROR;
			return (receiver_status);	
		}
		else{
			receiver_status.ERROR_STATUS = NO_ERROR;
			if(local_config.DATA_SIZE_VALUE == DATA_SIZE_9){
				receiver_status.DATA_RECEIVED = 0;
				receiver_status.DATA_RECEIVED = UCSRnB_0->B.RXB8n << 8;
				receiver_status.DATA_RECEIVED |= UDRn_0->R;
			}
			else{
				receiver_status.DATA_RECEIVED = 0;
				receiver_status.DATA_RECEIVED = UDRn_0->R;
			}
		}		
	}
	return (receiver_status);	
	
}
