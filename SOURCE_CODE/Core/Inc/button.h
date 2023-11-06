/*
 * button.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */

#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_flag[4];

int isButtonPressed(int key);
void getKeyInput(int key);

#endif /* INC_BUTTON_H_ */
