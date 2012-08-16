#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define DIGIT_LEN	4
/*
int addNumberDigit (char **res, const char* src1, const char* src2)
{
}
*/

int addNumberDigit (char *res, const char* src1, const char* src2)
{
	int s, t, u ;
	int i ;
	for (u=0, i=DIGIT_LEN-1; i >=0; i--) {
		s = *(src1+i) - '0' + *(src2+i) -'0' + u ;
		t = s % 10 ;
		u = s / 10 ;
		*(res+i+1)  = t + '0' ; 
	}
	*res  =	u + '0' ;
	*(res+DIGIT_LEN+1)  =	'\0' ;
	return t;
}

int mulNumberDigit (char *res, const char* src1, const char* src2)
{
	char mRes[DIGIT_LEN][DIGIT_LEN*2+2] ;
	int i, j, s, t, u ;
	int h;
	
	/* mRes�� res�� �ܼ� �ʱ�ȭ */
	for (i=0; i < DIGIT_LEN; i++) {
		for (j=0; j<DIGIT_LEN*2+2; j++) {
			mRes[i][j] = '0' ;
		}
		mRes[i][j-1] = '\0' ;
	}
	memset (res, '0', DIGIT_LEN*2+2);
	

	/* �ڸ����� ������ �� �ٸ� �迭�� ����*/
	for (h=0, i=DIGIT_LEN-1; i >=0; i--, h++) {
		u=0 ;
		for(j=DIGIT_LEN-1;j >=0; j--) {
			s = (*(src1+i) - '0' ) * (*(src2+j) -'0') + u ;
			t = s % 10 ;
			u = s / 10 ;
			mRes[h][j+i+2] = t + '0' ;
		}
		mRes[h][j+i+2] = u + '0' ;		
	}

	/* �� �ڸ����� ����� ������ ����� ���� */
	u = 0;	
	for( j = DIGIT_LEN*2; j >=0; j--) {
		s=t=0 ;
		for(i =0 ; i < DIGIT_LEN ; i++) {			
			s += mRes[i][j] - '0' ;
		}
		s = s + u ;
		t = s % 10 ;
		u = s / 10 ;
		res[j] = t + '0' ;
	}
	res[j] = u + '0';
	res[DIGIT_LEN*2+1] = '\0';
	return 0;
}

int main()
{
	char r[DIGIT_LEN+2] ;
	char mRes[DIGIT_LEN*2+2] ;
	char *m = "9999";
	char *n = "9999";
	int aRes ;
	int i;

	aRes = addNumberDigit (r, m, n) ;
	puts(r);

	aRes = mulNumberDigit (mRes, m,n) ;
	puts(mRes);

	return 0;
}