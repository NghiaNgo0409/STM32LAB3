/*
 * input_reading.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */


#include "input_reading.h"

#define NO_OF_BUTTONS 3

#define DURATION_FOR_AUTO_INCREASING 200
#define DURATION_FOR_HOLD 50

#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

static GPIO_PinState debounceButtonBufer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBufer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBufer3[NO_OF_BUTTONS];

static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint8_t flagForButtonHold[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonHold[NO_OF_BUTTONS];

static int button_ports[3] = {BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port};
static int button_pins[3] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

void init_buffer() {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
			buttonBuffer[i] = BUTTON_IS_RELEASED;
			debounceButtonBufer1[i] = BUTTON_IS_RELEASED;
			debounceButtonBufer2[i] = BUTTON_IS_RELEASED;
			debounceButtonBufer3[i] = BUTTON_IS_RELEASED;
			flagForButtonPress1s[i] = 0;
			flagForButtonHold[i] = 0;
			counterForButtonPress1s[i] = 0;
			counterForButtonHold[i] = 0;
	}
}

void button_reading(void) {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBufer3[i] = debounceButtonBufer2[i];
		debounceButtonBufer2[i] = debounceButtonBufer1[i];
		debounceButtonBufer1[i] = HAL_GPIO_ReadPin(button_ports[i], button_pins[i]);

		if (debounceButtonBufer1[i] == debounceButtonBufer2[i] && debounceButtonBufer3[i] == debounceButtonBufer2[i])
			buttonBuffer[i] = debounceButtonBufer1[i];

		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i]++;
			}
			else {
				flagForButtonPress1s[i] = 1;
				//TO DO
				if (counterForButtonHold[i] < DURATION_FOR_HOLD) {
					counterForButtonHold[i]++;
					if (counterForButtonHold[i] >= DURATION_FOR_HOLD) {
						counterForButtonHold[i] = 0;
						flagForButtonHold[i] = 1;
					}
				}
			}
		}
		else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
			counterForButtonHold[i] = 0;
			flagForButtonHold[i] = 0;
		}
	}
}

int is_button_pressed(int index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

int is_button_pressed_1s(int index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}

int is_button_held(int index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonHold[index] == 1);
}

void reset_flagForButtonHold(int index) {
	flagForButtonHold[index] = 0;
}
