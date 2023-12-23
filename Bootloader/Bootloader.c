/**
 ******************************************************************************
 * @file           : Bootloader.c
 * @author         : Ahmed Abdalla
 * @brief          : Contains Implementation of Bootloader Application
 * @date		   		 : 23 Dec 2023 
 ******************************************************************************
 */
 

 /******************** Include Start **********************/
 #include "Bootloader.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/

/******************** Macro Declarations End   **********************/

/******************** Macro Function Declarations Start **********************/

/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/

/******************** Data Type Declarations End   **********************/

/* ****************** Static Functions Decleration Start ******************/
static void Bootloader_Get_Version(uint8_t *Host_Buffer);
static void Bootloader_Get_Help(uint8_t *Host_Buffer);
static void Bootloader_Get_Chip_Identification_Number(uint8_t *Host_Buffer);
static void Bootloader_Read_Protection_Level(uint8_t *Host_Buffer);
static void Bootloader_Jump_To_Address(uint8_t *Host_Buffer);
static void Bootloader_Erase_Flash(uint8_t *Host_Buffer);
static void Bootloader_Memory_Write(uint8_t *Host_Buffer);
static void Bootloader_Enable_RW_Protection(uint8_t *Host_Buffer);
static void Bootloader_Memory_Read(uint8_t *Host_Buffer);
static void Bootloader_Get_Sector_Protection_Status(uint8_t *Host_Buffer);
static void Bootloader_Read_OTP(uint8_t *Host_Buffer);
static void Bootloader_Change_Read_Protection_Level(uint8_t *Host_Buffer);

/* ****************** Static Functions Decleration End ******************/

/******************** Global Variable Defintion Start **********************/
static uint8_t BL_Host_Buffer[BL_HOST_BUFFER_LEN] = {0}; 
/******************** Global Variable Defintion End   **********************/
/******************** Software Interfaces Declarations Start **********************/
void BL_Print_Message(char * format, ...)
{
	char msg[100] = {0};
	va_list args;
	/* Enable access the the variable arguments*/
	va_start(args , format);
	
	/* Write Formatted data  from variable argument list to string*/
	vsprintf(msg , format , args );
	#ifdef BL_ENABLE_DEBUG_USART_MSG
	/* Transmit formatted data through the defined  UART*/
	HAL_UART_Transmit(BL_DEBUG_USART, (uint8_t*)msg, sizeof(msg), HAL_MAX_DELAY);
	#endif
	/* Perform Cleanup for an object initialized by  a call to va_start*/
	va_end(args);

}

BL_Status_T BL_Uart_Fetch_Host_Command(void)
{
	BL_Status_T ret = E_NOK;
	HAL_StatusTypeDef HAL_Status = HAL_ERROR;
	uint8_t data_len = 0;
	
	memset(BL_Host_Buffer, 0, BL_HOST_BUFFER_LEN);
	
	HAL_Status = HAL_UART_Receive(BL_DEBUG_USART, BL_Host_Buffer, 1, HAL_MAX_DELAY);
	
	if(HAL_Status != HAL_OK)
	{
	
	}
	else
	{
		data_len = BL_Host_Buffer[0];
	
		HAL_Status = HAL_UART_Receive(BL_DEBUG_USART, &(BL_Host_Buffer[1]), data_len, HAL_MAX_DELAY);
		if(HAL_Status != HAL_OK)
		{
	
		}
		else
		{
			switch(BL_Host_Buffer[1])
			{
				case CBL_GET_VER_CMD:
					
					HAL_Status = HAL_OK;
				break;
				case CBL_GET_HELP_CMD:
					
				
					HAL_Status = HAL_OK;
					
				break;
				case CBL_GET_CID_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_GET_RDP_STATUS_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_GO_TO_ADDR_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_FLASH_ERASE_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_MEM_WRITE_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_ED_W_PROTECT_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_MEM_READ_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_READ_SECTOR_STATUS_CMD:
					HAL_Status = HAL_OK;
				break;
				case CBL_OTP_READ_CMD:
					HAL_Status = HAL_OK;
					
				break;
				case CBL_CHANGE_ROP_Level_CMD:
					HAL_Status = HAL_OK;
					
				break;
			
			}
		}
	}


	return ret;
}

/******************** Software Interfaces Declarations End **********************/
 