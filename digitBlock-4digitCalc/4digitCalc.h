#ifndef __4DIGITCALC__
#define __4DIGITCALC__
#define DIGIT_LEN	4
/*
stored a normalized number.
*/
typedef struct nn {
	int start_pos;
	int end_pos;
	char *digit ;
} NormalizedNumber;

typedef struct num{
	int start_pos;
	char digit[DIGIT_LEN+1];
	char carryborrow ;
	int end_pos;
} Number ;

void copyNumber(Number *res, const Number r1, const Number r2) ;
void normalizeNumber (NormalizedNumber *res, Number *part);
void  setNumber (Number *a, int s1, int e1, const char *val);
int addNumber(Number *res, const Number r1, const Number r2);
#endif