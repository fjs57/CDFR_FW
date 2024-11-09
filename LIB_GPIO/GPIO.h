/*
 * GPIO.h
 *
 *  Created on: Nov 9, 2024
 *      Author: francois
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "main.h"
#include <stdbool.h>
#include <string.h>

typedef struct
{
	GPIO_TypeDef *port;
	uint32_t pin;
}
GPIO_Pin_t;

#endif /* GPIO_H_ */
