#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCK 5
int multiplication(const char * block1, const char * block2, char * block3, char * block4)
{
	unsigned int calc;
	int calc_block1, calc_block2;

	int i, j, temp_exp=1, q,r;

	calc = atoi(block1) * atoi(block2);

	calc_block1 = calc / 10000;
	calc_block2 = calc % 10000;

	for(i=0; i<MAX_BLOCK-1; i++) {
		temp_exp*=10;
		q = calc_block1 % temp_exp ;
		calc_block1 -= q;
		block3[3-i] = '0' + (q/(temp_exp/10)) ;

		r = calc_block2 % temp_exp ;
		calc_block2 -= r;
		block4[3-i] = '0' + (r/(temp_exp/10)) ;
	}
	return 0;
}

int addition(const char * block1, const char * block2, char * block3, char * block4)
{
	unsigned int calc;
	int calc_block1, calc_block2;

	int i, j, temp_exp=1, q,r;

	calc = atoi(block1) + atoi(block2);

	calc_block1 = calc / 10000;
	calc_block2 = calc % 10000;

	for(i=0; i<MAX_BLOCK-1; i++) {
		temp_exp*=10;
		q = calc_block1 % temp_exp ;
		calc_block1 -= q;
		block3[3-i] = '0' + (q/(temp_exp/10)) ;

		r = calc_block2 % temp_exp ;
		calc_block2 -= r;
		block4[3-i] = '0' + (r/(temp_exp/10)) ;
	}
	return 0;
}

int main()
{
	/*
	implementing larger than 80-digit later
	*/
	char block1[MAX_BLOCK]="9999", block2[MAX_BLOCK]="9999";
	char block3[MAX_BLOCK]="0000", block4[MAX_BLOCK]="0000";
	
	multiplication(block1,block2,block3,block4);

	printf("%s %s\n", block3, block4);

	addition(block1,block2,block3,block4);
	printf("%s %s\n", block3, block4);

	return 0;

}