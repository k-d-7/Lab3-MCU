/*
 * button.h
 *
 *  Created on: Oct 25, 2022
 *      Author: khuon
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

extern int button1_flag;

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput();

#endif /* INC_BUTTON_H_ */
