#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_DIGIT 5

typedef struct _ttt {
	char num[MAX_DIGIT];
	int start_p;	/* Most left */
	int end_p;	/* Most right */
} NumBlock;

void init_numblock (NumBlock *n,  const char *value, const int start, const int end)
{
	strcpy(n->num, value);
	n->start_p = start ;
	n->end_p = end ;

	return ;
}

void xPosAdd_Digit(NumBlock *n, const NumBlock a, const NumBlock b)
{
	int res_length ,i, j,k;
	NumBlock upper, lower;
	upper = a ;
	lower = b ;

	if (a.start_p < b.start_p) {
		upper = b ;
		lower = a ;
	}
	res_length = upper.start_p - lower.end_p ;
	if(res_length <= 0 ) {
		fprintf(stderr, "Numblock format error\n");
		exit(-2);
	}
	if (res_length == MAX_DIGIT -1) {
		/* upper와 lower가 같은 자리 */
	}

	if (res_length < MAX_DIGIT-1) {
		/* upper와 lower는 서로 겹치는 부분이 있을 수 있음 */
	}
	if (res_length >= (MAX_DIGIT-1)*2) {
		/*upper와 lower는 서로 겹치는 부분이 없음 */
	}
	return ;
}
int main()
{
	char *oa="1999", *ob="0012";
	NumBlock a, b ;
	NumBlock result[2];
	init_numblock(&a, oa, 4,1);
	init_numblock(&b, ob, 3,0);

	printf("%s, %d, %d\n", a.num, a.start_p, a.end_p);
	printf("%s, %d, %d\n", b.num, b.start_p, b.end_p);

	xPosAdd_Digit(result, a ,b);

	return 0;
}