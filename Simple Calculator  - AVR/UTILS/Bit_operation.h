#ifndef BIT_OPERATION_H_INCLUDED
#define BIT_OPERATION_H_INCLUDED

#define CLR_BIT(REG, BIT_NUMBER) REG &= ~(1<<BIT_NUMBER)
#define SET_BIT(REG, BIT_NUMBER)  REG |= (1<<BIT_NUMBER)
#define TOGG_BIT(REG, BIT_NUMBER)  REG ^= (1<<BIT_NUMBER)
#define GET_BIT(REG, BIT_NUMBER)  ((REG>>BIT_NUMBER)&1)

#endif // BIT_OPERATION_H_INCLUDED
