/**
 * Std_Types.h
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Abdullah Darwish
 */
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef signed char         sint8;          /*        -128 .. +127            */
typedef unsigned char       uint8;          /*           0 .. 255             */
typedef signed short        sint16;         /*      -32768 .. +32767          */
typedef unsigned short      uint16;         /*           0 .. 65535           */
typedef signed long         sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long       uint32;         /*           0 .. 4294967295      */
typedef unsigned long long  uint64;         /*       0..18446744073709551615  */
typedef signed long long    sint64;         /*       0..18446744073709551615  */
typedef float               float32;        /* 1.1754943635e-38 to 3.4028235e+38 */
typedef double              float64;        /* 2.2250738585072015e-308 to 1.7976931348623158e+308 */

typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */


#endif /* STD_TYPES_H */
