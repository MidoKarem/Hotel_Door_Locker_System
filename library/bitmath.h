#ifndef bitmath_h_
#define bitmath_h_

#define SET_BIT(VAR,BIT_NUMBER)     (VAR|=(1<<BIT_NUMBER))
#define CLR_BIT(VAR,BIT_NUMBER)     (VAR&=(~(1<<BIT_NUMBER)))
#define TOGGLE_BIT(VAR,BIT_NUMBER)  (VAR^=(1<<BIT_NUMBER))
#define GET_BIT(VAR,BIT_NUMBER)     ((VAR>>BIT_NUMBER)&1)
#endif   /*bitmath_h_*/
