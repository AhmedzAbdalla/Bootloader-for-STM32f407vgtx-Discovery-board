/**
 ******************************************************************************
 * @file           : Bootloader.h
 * @author         : Ahmed Abdalla
 * @brief          : Contains APIs declaration, data types and macros for Bootloader Application 
 * @date		   		 : 23 Dec 2023 
 ******************************************************************************
 */
 
 
 #ifndef BOOTLOADER_H
 #define BOOTLOADER_H
 

 
/******************** Include Start **********************/
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	#include "usart.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/
#define BL_DEBUG_USART						(&huart2)
#define BL_ENABLE_DEBUG_USART_MSG
#define BL_HOST_BUFFER_LEN 				 200UL

#define CBL_GET_VER_CMD              0x10
#define CBL_GET_HELP_CMD             0x11
#define CBL_GET_CID_CMD              0x12
/* Get Read Protection Status */
#define CBL_GET_RDP_STATUS_CMD       0x13
#define CBL_GO_TO_ADDR_CMD           0x14
#define CBL_FLASH_ERASE_CMD          0x15
#define CBL_MEM_WRITE_CMD            0x16
/* Enable/Disable Write Protection */
#define CBL_ED_W_PROTECT_CMD         0x17
#define CBL_MEM_READ_CMD             0x18
/* Get Sector Read/Write Protection Status */
#define CBL_READ_SECTOR_STATUS_CMD   0x19
#define CBL_OTP_READ_CMD             0x20
/* Change Read Out Protection Level */
#define CBL_CHANGE_ROP_Level_CMD     0x21

/******************** Macro Declarations End   **********************/
/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/
typedef enum
{
	E_NOK = 0,
	R_OK
}BL_Status_T;
/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
void BL_Print_Message(char * format, ...);
BL_Status_T BL_Uart_Fetch_Host_Command(void);
/******************** Software Interfaces Declarations End **********************/
 
 
 
 
 
 
 
 #endif //BOOTLOADER_H