/*
 * button.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */

#include "button.h"

#define DURATION_FOR_AUTO_INCREASING 200;

int button_flag[4] = {0};

int KeyReg[4][4] = {
				   {0, 0, 0, 0},
		           {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
				   {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
				   {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}
};

int timeForKeyPress = 100;

int button_ports[4] = {0, BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port};
int button_pins[4] = {0, BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

int counterForButtonPress1s[4] = {0};

int isButtonPressed(int key){
	if(button_flag[key] == 1){
		button_flag[key] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int key){
	button_flag[key] = 1;
}
void getKeyInput(int key){
	KeyReg[key][0] = KeyReg[key][1];
	KeyReg[key][1] = KeyReg[key][2];
	KeyReg[key][2] = HAL_GPIO_ReadPin(button_ports[key],button_pins[key]);
	if((KeyReg[key][0] == KeyReg[key][1]) && (KeyReg[key][1] == KeyReg[key][2])){
		if(KeyReg[key][3] != KeyReg[key][2]){
			KeyReg[key][3] = KeyReg[key][2];
			if(KeyReg[key][2] == PRESSED_STATE){
				subKeyProcess(key);
				timeForKeyPress = 100;
			}
		}else{
			timeForKeyPress--;
			if(timeForKeyPress == 0){
				KeyReg[key][3] = NORMAL_STATE;
			}
		}
	}
}
