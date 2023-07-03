/**
 * Bit_Operations.h
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Abdullah Darwish
 */
#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#define SET_BIT(X, BIT)            (X |=  (1 << (BIT)))
#define SET_2_BITS(X, BIT)         (X |=  (0x3 << (BIT)))

#define CLEAR_BIT(X, BIT)          (X &= ~(1 << (BIT))) 
#define CLEAR_2_BITS(X, BIT)       (X &= ~(0x3 << (BIT)))

#define READ_BIT(X, BIT)           (((X) >> (BIT)) & 1)
#define TOGGLE_BIT(X, BIT)         (X ^= (1 << (BIT)))

#endif /* BIT_OPERATIONS_H */
