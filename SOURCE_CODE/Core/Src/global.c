/*
 * global.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */

#include "global.h"

int status = 0;
int horizontal_duration = 0;
int vertical_duration = 0;
int led_buffer[4] = {0};

void display7SEG(int num) {
	switch(num) {
				case 0:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
					  break;
				case 1:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
					  break;
				case 2:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
				case 3:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
				case 4:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
				case 5:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
				case 6:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
				case 7:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
					  break;
				case 8:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
				case 9:
					  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
					  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
					  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
					  break;
	}
}

void update7SEG(int index) {
	display7SEG(led_buffer[index]);
	switch(index) {
		  case 0:
			  HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
			  break;
		  case 1:
			  HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
		  	  break;
		  case 2:
			  HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
		  	  break;
		  case 3:
			  HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
			  HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
		  	  break;
		  default:
		  	  break;
	}
}

void updateClockBuffer() {
	led_buffer[0] = horizontal_duration / 10;
	led_buffer[1] = horizontal_duration % 10;
	led_buffer[2] = vertical_duration / 10;
	led_buffer[3] = vertical_duration % 10;
}

void countDown() {
	horizontal_duration--;
	vertical_duration--;
}

void setInitialValue(int horizontal_value, int vertical_value) {
	horizontal_duration = horizontal_value;
	vertical_duration = vertical_value;
}

void setHorizontalLeds(int red, int green, int yellow) {
	HAL_GPIO_WritePin(RED_HORIZONTAL_GPIO_Port, RED_HORIZONTAL_Pin, red);
	HAL_GPIO_WritePin(GREEN_HORIZONTAL_GPIO_Port, GREEN_HORIZONTAL_Pin, green);
	HAL_GPIO_WritePin(YELLOW_HORIZONTAL_GPIO_Port, YELLOW_HORIZONTAL_Pin, yellow);
}

void setVerticalLeds(int red, int green, int yellow) {
	HAL_GPIO_WritePin(RED_VERTICAL_GPIO_Port, RED_VERTICAL_Pin, red);
	HAL_GPIO_WritePin(GREEN_VERTICAL_GPIO_Port, GREEN_VERTICAL_Pin, green);
	HAL_GPIO_WritePin(YELLOW_VERTICAL_GPIO_Port, YELLOW_VERTICAL_Pin, yellow);
}
