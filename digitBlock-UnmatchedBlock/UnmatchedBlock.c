#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define DIGIT_LEN 4
#define RES_DIGIT_LEN DIGIT_LEN*2+2

void UnmatchedBlockAdd(char *, const char*, const char*, const int, const int) ;
/*src1이 항상 src2보다 큰 자리값이라는 가정에서 구현한 것임. */
void  UnmatchedBlockAdd(char *dest, const char* src1, const char*src2, const int startB1, const int startB2) 
{
	int h1, h2 ;
	int i ;
	int i1, i2 ;
	int j ;
	int k = RES_DIGIT_LEN -1;
	int u, s, d ;

	h1 = DIGIT_LEN-(startB1 - startB2)-1 ;
	h2 = startB1 - startB2;
	/*
	When h is a value, absolute constant k (< DIGIT_LEN)
	src1+h  ~ src1 + DIGIT_LEN
	src2  ~ src2 + DIGIT_LEN+h
	*/
	printf("H1 = %d, H2 = %d\n", h1, h2) ;	

	j = h2 +1 ;
	if (h1 < h2 ) j = h1;
	
	/* 낮은 부분에서 포함되지 않은 부분을 dest에 복사. */
	for(i=DIGIT_LEN-1; i > j; i--) {
		*(dest+(--k)) =  *(src2+i) ;
		printf("                *(src2+%d) = %c\n", i, *(dest+k));
	}

	u = s =  d = 0;
	/* 겹치는 부분에 대한 연산과 복사.*/
	for(i1=DIGIT_LEN-1, i2 =h1; i1 >= h2 && i2 >= 0; i1 --, i2--) {
		s = (*(src1+i1) - '0') + (*(src2+i2) - '0') + u ;
		u = s / 10 ;
		d = s % 10 ;
		*(dest+(--k)) = d + '0' ;
		printf("*(src1+%d) = %c + *(src2+%d) = %c ==> %d,%d\n", i1, *(src1+i1), i2, *(src2+i2), u, d);
	}

	/* 윗 부분의 연산에서 올림수를 더해야 함.*/
	for(i=h2-1; i >= 0; i--) {
		s = (*(src1+i) - '0') + u ;
		u = s / 10 ;
		d = s % 10 ;
		*(dest+(--k)) = d + '0' ;
		printf("*(src1+%d) = %c\n", i, *(src1+i));
	}
	*(dest+(--k)) = u + '0' ;

	for (i=0 ; i < RES_DIGIT_LEN; i++) {
		printf("%c", *(dest+i));
	}
	putchar('\n');
	return ;
}
int main()
{
	char src1[DIGIT_LEN+1]="9999"; /* 3~6 */
	char src2[DIGIT_LEN+1]=  "9999"; /*1~4 */
	char dest[RES_DIGIT_LEN] ;

	memset(dest, '0', RES_DIGIT_LEN);
	dest[RES_DIGIT_LEN-1] = '\0';
	UnmatchedBlockAdd(dest, src1, src2,5,1) ;

	memset(dest, '0', RES_DIGIT_LEN);
	dest[RES_DIGIT_LEN-1] = '\0';
	UnmatchedBlockAdd(dest, src1, src2,4,1) ;

	memset(dest, '0', RES_DIGIT_LEN);
	dest[RES_DIGIT_LEN-1] = '\0';
	UnmatchedBlockAdd(dest, src1, src2,3,1) ;

	memset(dest, '0', RES_DIGIT_LEN);
	dest[RES_DIGIT_LEN-1] = '\0';
	UnmatchedBlockAdd(dest, src1, src2,2,1) ;

	return 0;
}