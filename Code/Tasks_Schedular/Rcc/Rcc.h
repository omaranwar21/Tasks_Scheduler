/**
 * Rcc.h
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Abdullah Darwish
 */
#ifndef RCC_H
#define RCC_H
#include "Std_Types.h"
typedef uint8 Rcc_PeripheralIdType;
#define RCC_AHB1 0UL 
#define RCC_AHB2 1UL
#define RCC_APB1 2UL
#define RCC_APB2 3UL
#define RCC_GPIOA           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 0UL)
#define RCC_GPIOB           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 1UL)
#define RCC_GPIOC           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 2UL)
#define RCC_GPIOD           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 3UL)
#define RCC_GPIOE           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 4UL)
#define RCC_GPIOH           (Rcc_PeripheralIdType)(RCC_AHB1*32 + 7UL)
#define RCC_CRC             (Rcc_PeripheralIdType)(RCC_AHB1*32 + 2UL)
#define RCC_DMA1            (Rcc_PeripheralIdType)(RCC_AHB1*32 + 21UL)
#define RCC_DMA2            (Rcc_PeripheralIdType)(RCC_AHB1*32 + 22UL)
#define RCC_OTGFS           (Rcc_PeripheralIdType)(RCC_AHB2*32 + 7UL)
#define RCC_TIM2            (Rcc_PeripheralIdType)(RCC_APB1*32 + 0UL)
#define RCC_TIM3            (Rcc_PeripheralIdType)(RCC_APB1*32 + 1UL)
#define RCC_TIM4            (Rcc_PeripheralIdType)(RCC_APB1*32 + 2UL)
#define RCC_TIM5            (Rcc_PeripheralIdType)(RCC_APB1*32 + 3UL)
#define RCC_WWDG            (Rcc_PeripheralIdType)(RCC_APB1*32 + 11UL)
#define RCC_SPI2            (Rcc_PeripheralIdType)(RCC_APB1*32 + 14UL)
#define RCC_SPI3            (Rcc_PeripheralIdType)(RCC_APB1*32 + 15UL)
#define RCC_USART2          (Rcc_PeripheralIdType)(RCC_APB1*32 + 16UL)
#define RCC_I2C1            (Rcc_PeripheralIdType)(RCC_APB1*32 + 21UL)
#define RCC_I2C2            (Rcc_PeripheralIdType)(RCC_APB1*32 + 22UL)
#define RCC_I2C3            (Rcc_PeripheralIdType)(RCC_APB1*32 + 23UL)
#define RCC_PWR             (Rcc_PeripheralIdType)(RCC_APB1*32 + 28UL)
#define RCC_TIM1            (Rcc_PeripheralIdType)(RCC_APB2*32 + 0UL)
#define RCC_USART1          (Rcc_PeripheralIdType)(RCC_APB2*32 + 4UL)
#define RCC_USART6          (Rcc_PeripheralIdType)(RCC_APB2*32 + 5UL)
#define RCC_ADC1            (Rcc_PeripheralIdType)(RCC_APB2*32 + 8UL)
#define RCC_SDIO            (Rcc_PeripheralIdType)(RCC_APB2*32 + 11UL)
#define RCC_SPI1            (Rcc_PeripheralIdType)(RCC_APB2*32 + 12UL)
#define RCC_SPI4            (Rcc_PeripheralIdType)(RCC_APB2*32 + 13UL)
#define RCC_SYSCFG          (Rcc_PeripheralIdType)(RCC_APB2*32 + 14UL)
#define RCC_TIM9            (Rcc_PeripheralIdType)(RCC_APB2*32 + 16UL)
#define RCC_TIM10           (Rcc_PeripheralIdType)(RCC_APB2*32 + 17UL)
#define RCC_TIM11           (Rcc_PeripheralIdType)(RCC_APB2*32 + 18UL)
void Rcc_Init(void);
void Rcc_Enable(Rcc_PeripheralIdType PeripheralId);
void Rcc_Disable(Rcc_PeripheralIdType PeripheralId);
#endif /* RCC_H */
