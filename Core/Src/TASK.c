#include "task.h"
#include "stm32f1xx_hal_gpio.h"
#include"stm32f103xb.h"

void Task1_RED_BLINK(void)
{
	HAL_GPIO_TogglePin(GPIOA,  GPIO_PIN_1);


}


void Task2_YELLOW_BLINK(void)
{
	HAL_GPIO_TogglePin(GPIOC,  GPIO_PIN_13);
}


void Task3_GREEN_BLINK(void)
{
	HAL_GPIO_TogglePin(GPIOC,  GPIO_PIN_15);
}

