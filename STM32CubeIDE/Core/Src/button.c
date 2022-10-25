/*
 * button.c
 *
 *  Created on: Oct 25, 2022
 *      Author: khuon
 */
#include "button.h"

int button1_flag = 0;

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg3 = NORMAL_STATE;
int timerForKeyPress = 100;

int isButton1Pressed() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess() {
	button1_flag = 1;
}

void getKeyInput() {
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	if ((keyReg0 == keyReg1) && (keyReg1 == keyReg2)) {
		if (keyReg3 != keyReg2) {
			keyReg3 = keyReg2;
			if (keyReg3 == PRESSED_STATE) {
				timerForKeyPress = 100;
				subKeyProcess();
			}
		} else {
			timerForKeyPress--;
			if (timerForKeyPress == 0) {
				keyReg3 = NORMAL_STATE;
			}
		}
	}
}

