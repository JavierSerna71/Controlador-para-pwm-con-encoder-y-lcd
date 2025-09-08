/*
 * LCD.c
 *
 *  Created on: Sep 6, 2025
 *      Author: javier-serna
 */
#include "LCD.h"

LCD_Structura LCD_Create(
		LCD_PortType port[],  LCD_PinType pin[],
		LCD_PortType rs_port, LCD_PinType rs_pin,
		LCD_PortType en_port, LCD_PinType en_pin
)
{
	LCD_Structura LCD;
	LCD.EN_pin   = en_pin;
	LCD.EN_port  = en_port;
	LCD.RS_pin   = rs_pin;
	LCD.RS_port  = rs_port;
	LCD.datapin  = pin;
	LCD.dataport = port;


	LCD_Init(&LCD);
	return LCD;
}


void LCD_Init(LCD_Structura *LCD){
	HAL_Delay(100);
	LCD_Command(LCD,0x30);
	HAL_Delay(5);
	LCD_Command(LCD,0x30);
	HAL_Delay(1);
	LCD_Command(LCD,0x32);
	LCD_Command(LCD,0x28);
	LCD_Command(LCD,0x0C);
	LCD_Command(LCD,0x01);
	LCD_Command(LCD,0x06);
}

void LCD_Command(LCD_Structura *LCD, char cmd){

	char comando = 0;
	HAL_GPIO_WritePin(LCD->RS_port, LCD->RS_pin, GPIO_PIN_RESET);
	comando = (cmd>>4) & 0x0F;
	for(uint8_t i=0; i<4; i++){

		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (comando>>i) & 0x01);
	}
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_RESET);

	comando = cmd & 0x0F;
	for(uint8_t i=0; i<4; i++){
		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (comando>>i) & 0x01);
	}
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_RESET);

}

void LCD_texto(LCD_Structura *LCD,char data){

	char datos = 0;
	HAL_GPIO_WritePin(LCD->RS_port, LCD->RS_pin, GPIO_PIN_SET);
	datos = (data>>4) & 0x0F;
	for(uint8_t i=0; i<4; i++){

		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (datos>>i) & 0x01);
	}
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_RESET);

	datos = data & 0x0F;
	for(uint8_t i=0; i<4; i++){
		HAL_GPIO_WritePin(LCD->dataport[i], LCD->datapin[i], (datos>>i) & 0x01);
	}
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD->EN_port, LCD->EN_pin,GPIO_PIN_RESET);

}

void LCD_cadena(LCD_Structura *LCD,char *cadena){
	for(uint8_t i=0; i <strlen(cadena); i++){
		LCD_texto(LCD, cadena[i]);
	}
}

void LCD_xy(LCD_Structura *LCD, char x, char y){
	if(y>0){
		LCD_Command(LCD,0xC0 + x );
	}
	else{
		LCD_Command(LCD,0x80 + x );
	}
}

void LCD_clear(LCD_Structura *LCD){
	LCD_xy(LCD, 0, 0);
	LCD_cadena(LCD, "                ");
	LCD_xy(LCD, 0, 1);
	LCD_cadena(LCD, "                ");
}


void LCD_entero(LCD_Structura *LCD, int numero) {
    char buffer[12];
    sprintf(buffer, "%d", numero);
    LCD_cadena(LCD, buffer);
}


void pintarplantilla(LCD_Structura *LCD){
	LCD_clear(LCD);
	LCD_xy(LCD, 0, 0);
	LCD_cadena(LCD,"Frecuencia:");
	LCD_xy(LCD, 0, 1);
	LCD_cadena(LCD,"Dutty:");
	HAL_Delay(200);
}






