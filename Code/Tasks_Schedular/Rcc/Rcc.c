/**
 * Rcc.c
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Abdullah Darwish
 */

#include "Rcc.h"

#include "Bit_Operations.h"
#include "Rcc_Private.h"
#include "Std_Types.h"

void Rcc_Init(void) {
	SET_BIT(RCC_CR, 0);
}

void Rcc_Enable(Rcc_PeripheralIdType PeripheralId) {
  uint8 BusId = PeripheralId / 32;
  uint8 PeripheralBitPosition = PeripheralId % 32;
  switch (BusId) {
    case RCC_AHB1:
      SET_BIT(RCC_AHB1ENR, PeripheralBitPosition);
      break;
    case RCC_AHB2:
      SET_BIT(RCC_AHB2ENR, PeripheralBitPosition);
      break;
    case RCC_APB1:
      SET_BIT(RCC_APB1ENR, PeripheralBitPosition);
      break;
    case RCC_APB2:
      SET_BIT(RCC_APB2ENR, PeripheralBitPosition);
      break;
    default:
      break;
  }
}

void Rcc_Disable(Rcc_PeripheralIdType PeripheralId) {
     uint8 BusId = PeripheralId / 32;
  uint8 PeripheralBitPosition = PeripheralId % 32;
  switch (BusId) {
    case RCC_AHB1:
      SET_BIT(RCC_AHB1RSTR, PeripheralBitPosition);
      break;
    case RCC_AHB2:
      SET_BIT(RCC_AHB2RSTR, PeripheralBitPosition);
      break;
    case RCC_APB1:
      SET_BIT(RCC_APB1RSTR, PeripheralBitPosition);
      break;
    case RCC_APB2:
      SET_BIT(RCC_APB2RSTR, PeripheralBitPosition);
      break;
    default:
      break;
  }
}
