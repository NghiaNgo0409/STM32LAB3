/*
 * fsm_manual.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */

#include "fsm_manual.h"

int red_manual_duration;
int yellow_manual_duration;
int green_manual_duration;

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};

void initializeValue() {
	red_manual_duration = red_duration;
	yellow_manual_duration = yellow_duration;
	green_manual_duration = green_duration;
}

void fsm_manual_run() {
	switch(status) {
		case MAN_RED:
			setInitialValue(red_manual_duration, 2);
			if (timer_flag[3] == 1) {
				HAL_GPIO_TogglePin(RED_HORIZONTAL_GPIO_Port, RED_HORIZONTAL_Pin);
				HAL_GPIO_TogglePin(RED_VERTICAL_GPIO_Port, RED_VERTICAL_Pin);
				setTimer(100, 3);
			}
			if (isButtonPressed(1)) {
				setHorizontalLeds(SET, SET, SET);
				setVerticalLeds(SET, SET, SET);
				setTimer(100, 3);
				status = MAN_YELLOW;
			}
//			if (isButtonPressed(2)) {
//				red_manual_duration++;
//				if (red_manual_duration > 99) red_manual_duration = red_duration;
//			}
//			if (isButtonPressed(3)) {
//				red_duration = red_manual_duration;
//				green_duration = red_manual_duration - yellow_duration;
//			}
			UpdateDurationValue();
			break;
		case MAN_YELLOW:
			setInitialValue(yellow_manual_duration, 3);
			if (timer_flag[3] == 1) {
				HAL_GPIO_TogglePin(YELLOW_HORIZONTAL_GPIO_Port, YELLOW_HORIZONTAL_Pin);
				HAL_GPIO_TogglePin(YELLOW_VERTICAL_GPIO_Port, YELLOW_VERTICAL_Pin);
				setTimer(100, 3);
			}
			if (isButtonPressed(1)) {
				setHorizontalLeds(SET, SET, SET);
				setVerticalLeds(SET, SET, SET);
				setTimer(100, 3);
				status = MAN_GREEN;
			}
//			if (isButtonPressed(2)) {
//				yellow_manual_duration++;
//				if (yellow_manual_duration > 99) yellow_manual_duration = yellow_duration;
//			}
//			if (isButtonPressed(3)) {
//				yellow_duration = yellow_manual_duration;
//				red_duration = green_duration + yellow_duration;
//			}
			UpdateDurationValue();
			break;
		case MAN_GREEN:
			setInitialValue(green_manual_duration, 4);
			if (timer_flag[3] == 1) {
				HAL_GPIO_TogglePin(GREEN_HORIZONTAL_GPIO_Port, GREEN_HORIZONTAL_Pin);
				HAL_GPIO_TogglePin(GREEN_VERTICAL_GPIO_Port, GREEN_VERTICAL_Pin);
				setTimer(100, 3);
			}
			if (isButtonPressed(1)) {
				setHorizontalLeds(SET, SET, SET);
				setVerticalLeds(SET, SET, SET);
				setTimer(100, 3);
				status = INIT;
			}
//			if (isButtonPressed(2)) {
//				green_manual_duration++;
//				if (green_manual_duration > 99) green_manual_duration = green_duration;
//			}
//			if (isButtonPressed(3)) {
//				green_duration = green_manual_duration;
//				red_duration = green_duration + yellow_duration;
//			}
			UpdateDurationValue();
			break;
		default:
			initializeValue();
			break;
	}
}

static void increaseDraftValue() {
	switch (status) {
		case MAN_RED:
			red_manual_duration++;
			if (red_manual_duration > 99) red_manual_duration = 0;
			break;
		case MAN_YELLOW:
			yellow_manual_duration++;
			if (yellow_manual_duration > 99) yellow_manual_duration = 0;
			break;
		case MAN_GREEN:
			green_manual_duration++;
			if (green_manual_duration > 99) green_manual_duration = 0;
			break;
		default:
			break;
	}
}

static void setDurationValue() {
	int diff = 0;
	switch (status) {
		case MAN_RED:
			diff = red_manual_duration - red_duration;
			red_duration = red_manual_duration;
			green_duration += diff;
			green_manual_duration += diff;
			break;
		case MAN_YELLOW:
			diff = yellow_manual_duration - yellow_duration;
			yellow_duration = yellow_manual_duration;
			red_duration += diff;
			red_manual_duration += diff;
			break;
		case MAN_GREEN:
			diff = green_manual_duration - green_duration;
			green_duration = green_manual_duration;
			green_duration += diff;
			green_manual_duration += diff;
			break;
		default:
			break;
	}
}

void UpdateDurationValue() {
	switch (buttonState[1]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1)) {
				buttonState[1] = BUTTON_PRESSED;
				increaseDraftValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_pressed_1s(1)) {
				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				increaseDraftValue();
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_held(1)) {
				reset_flagForButtonHold(1);
				increaseDraftValue();
			}
			break;
		default:
			break;
	}

	switch (buttonState[2]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2)) {
				buttonState[2] = BUTTON_PRESSED;
				setDurationValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2)) {
				buttonState[2] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}
