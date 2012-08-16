#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include "4digitCalc.h"

NormalizedNumber NormNumber ;
Number number1, number2, number3;
Number RES[2];

void copyNumber(Number *res, const Number r1, const Number r2)
{
	memcpy(res[0].digit, r1.digit, strlen(r1.digit));
	res[0].start_pos = r1.start_pos ;
	res[0].end_pos = r1.end_pos;

	memcpy(res[1].digit, r2.digit, strlen(r2.digit));
	res[1].start_pos = r2.start_pos ;
	res[1].end_pos = r2.end_pos ;

	res[1].carryborrow = res[0].carryborrow = 0 ;
}
/*
�μ� ���̿� ������ �ִٸ� 0�� ä���ִ� �Լ� ȣ��
*/
void normalizeNumber (NormalizedNumber *res, Number *part)
{
	int i,j;
	int k;
	int h;
	
	/*
	���� �κ��� �������� �κ��� ���� ��쿡 ���.
	*/
	k = part[0].end_pos - part[1].start_pos + 1 ;
	res->digit = (char*)malloc((k));
	
	memset(res->digit, '0', k);		
	
	for(i=0; i<DIGIT_LEN; i++)
		*(res->digit+i) = part[0].digit[i] ;
	
	/*
	for(j=0; j<part[0].start_pos - part[1].end_pos; j++) ;
	*/
	h = part[0].start_pos - part[1].end_pos - 1 ;

	for(j=0; i+h-1<k; i++,j++)
		*(res->digit+h+i) = part[1].digit[j] ;	

	for (i =0; i < k; i++)
		printf("%c",*(res->digit+i)) ;
	putchar('\n');


}

void  setNumber (Number *a, int s1, int e1, const char *val)
{
	a->start_pos = s1;
	a->end_pos = e1;
	
	memcpy(a->digit, val, strlen(val));
}

int addNumber(Number *res, const Number r1, const Number r2)
{
	int k = 0;

	k = r1.end_pos - r2.end_pos ;

	if ( k >= DIGIT_LEN) {
		copyNumber (res, r1, r2);
		return k;
	}

	if ( k <= -DIGIT_LEN) {
		copyNumber(res, r2,r1); 
		return k;
	}
	/*
	k is a number that has not DIGIT_LEN or -DIGIT_LEN
	*/

	return k;
}
int main()
{
	int a;

	setNumber (&number1, 1,4,"1234");
	setNumber (&number2, 2,5,"6789");
	/*
	printf("%s\n", number1.digit);
	printf("%s\n", number2.digit);
	*/

	a = addNumber(RES, number1, number2);
	/*
	�μ� ���̿� ������ �ִٸ� 0�� ä���ִ� �Լ� ȣ��.
	*/
	if ( a >= DIGIT_LEN || a <= -DIGIT_LEN)
		normalizeNumber ( &NormNumber, RES) ;
	
	printf("\"%s\"\"%s\"\n", RES[0].digit, RES[1].digit );

	return 0;
}
