/*
 * fsm_manual.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Nghia
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "global.h"

extern int red_manual_duration;
extern int yellow_manual_duration;
extern int green_manual_duration;

void fsm_manual_run();
void initializeValue();

#endif /* INC_FSM_MANUAL_H_ */
