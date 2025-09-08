/*
 * LCD.h
 *
 *  Created on: Sep 6, 2025
 *      Author: javier-serna
 */

#ifndef LIBRERIAS_LCD_H_
#define LIBRERIAS_LCD_H_
#include "main.h"

#define LCD_PinType uint16_t
#define LCD_PortType GPIO_TypeDef*



typedef struct
{
	LCD_PortType *dataport; // d4 d5 d6 d7 puertos de datos del lcd
	LCD_PinType *datapin; //pines de datos del lcd
	LCD_PortType RS_port;
	LCD_PinType  RS_pin;
	LCD_PortType EN_port;
	LCD_PinType  EN_pin;

}LCD_Structura;

LCD_Structura LCD_Create(
		LCD_PortType port[],  LCD_PinType pin[],
		LCD_PortType rs_port, LCD_PinType rs_pin,
		LCD_PortType en_port, LCD_PinType en_pin
);


void LCD_Init(LCD_Structura *LCD);

void LCD_Command(LCD_Structura *LCD,char cmd);

void LCD_texto(LCD_Structura *LCD,char data);

void LCD_cadena(LCD_Structura *LCD,char *cadena);

void LCD_xy(LCD_Structura *LCD, char x, char y);

void LCD_clear(LCD_Structura *LCD);

void LCD_entero(LCD_Structura *LCD, int numero);

void pintarplantilla(LCD_Structura *LCD);

#endif /* LIBRERIAS_LCD_H_ */
