/***************************************************************************
* Description        : This file provides all Software Interface for I2C .
*****************************************************************************/
#include "App_Include.h"

/*************************************************************************
 * Function Name: Delay_100us
 * Parameters: Int32U Dly
 * Return: none
 * Description: Delay Dly * 10us
 *************************************************************************/
void Delay_1us(unsigned int Dly)
{
  while(Dly--)
  {
    for(volatile int i = LOOP_DLY_1US; i; i--);
   }
}

/*************************************************************************
 * Function Name: INIT_SW_I2C
 * Parameters: none
 *
 * Return: none
 *
 * Description: Initialize Software I2C Pins
 *
 *************************************************************************/

void INIT_SW_I2C(void)
 {

  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure for Output */
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
  //SCL Control
  GPIO_InitStructure.GPIO_Pin = PIN_SCL;GPIO_Init(PORT_SCL, &GPIO_InitStructure);
  /* Configure for Input */
  //SDA Control
  GPIO_InitStructure.GPIO_Pin = PIN_SDA;GPIO_Init(PORT_SDA, &GPIO_InitStructure);

  // Relase both SCL & SDA line
  GP_Counter = 0;SET_SDA;
  while(GPIO_ReadInputDataBit(PORT_SDA,PIN_SDA) == RESET && GP_Counter < 8)
   {
     RST_SCL;Delay_1us(1);SET_SCL;
     GP_Counter++;
   };
  /* Confogure SDA for Output */

  GPIO_SetBits(PORT_SDA,PIN_SDA);
  GPIO_SetBits(PORT_SCL,PIN_SCL);

 }



/*************************************************************************
 * Function Name: I2C Start
 * Parameters: none
 *
 * Return: none
 *
 * Description: Generate Start Sequence for I2C Pins
 *
 *************************************************************************/

void I2C_START(void)
 {
  SET_SDA;             // SDA Going low While SCL is High
  SET_SCL;
  Delay_1us(1);
  RST_SDA;
  Delay_1us(1);
  RST_SCL;
  }


/*************************************************************************
 * Function Name: I2C STOP
 * Parameters: none
 *
 * Return: none
 *
 * Description: Generate STOP Sequence for I2C Pins
 *
 *************************************************************************/

void I2C_STOP(void)
 {
  Delay_1us(1); // SDA Going High While SCL is Low
  SET_SCL;
  Delay_1us(1);
  SET_SDA;
 }

/*************************************************************************
 * Function Name: I2C_ACK
 * Parameters: none
 *
 * Return: none
 *
 * Description: Generate Acknowledge Sequence for I2C Pins
 *
 *************************************************************************/

void I2C_ACK(void)
 {
  SET_SCL;
  Delay_1us(1);
  RST_SCL;
  Delay_1us(1);
  //SET_SCL;
 }

/*************************************************************************
 * Function Name: Serial_Out
 * Parameters: Data to be output
 *
 * Return: none
 *
 * Description: Send Data over I2C Pins
 *
 *************************************************************************/

void Serial_Out(unsigned char Dat_Out)
{
unsigned char Clk, Bit_Mult = 0x80;

for(Clk = 0;Clk<=7; Clk++)
   {
     RST_SCL;
     Delay_1us(1);
     if (Dat_Out & Bit_Mult)SET_SDA;else RST_SDA;
     Delay_1us(1);
     SET_SCL;
     Delay_1us(1);
     Bit_Mult = Bit_Mult >> 1;
   };
 RST_SCL;
 Delay_1us(1);

}

/*************************************************************************
 * Function Name: Serial_In
 * Parameters: None
 *
 * Return: Data Recieved
 *
 * Description: Recieve Data over I2C Pins
 *
 *************************************************************************/

unsigned char Serial_In(void)
{
unsigned char Clk,Data_In,Bit_Mult = 0x80;


// Configure SDA as Input

 SET_SDA;
 Data_In=0;

 for(Clk =0; Clk <= 7;Clk++){
                           RST_SCL;
                           Delay_1us(1);
                           SET_SCL;
			   Delay_1us(1);
                           if(GPIO_ReadInputDataBit(PORT_SDA,PIN_SDA) == SET)
			     Data_In |= Bit_Mult;
			   Delay_1us(1);
			   Bit_Mult = Bit_Mult >>1;
                          };
  RST_SCL;
  Delay_1us(1);
  return(Data_In);

}
