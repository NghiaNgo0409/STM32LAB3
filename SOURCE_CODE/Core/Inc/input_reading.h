/*
 * input_reading.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

void button_reading(void);

void init_buffer();
int is_button_pressed(int index);
int is_button_pressed_1s(int index);
int is_button_held(int index);
void reset_flagForButtonHold(int index);

#endif /* INC_INPUT_READING_H_ */
