#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *block_a = "12345";
	char *block_b = "67890";
	char block_res[5][3] ;
	int size_a, size_b ;

	int i,j ;
	size_a = strlen(block_a)-1 ;
	size_b = strlen(block_b)-1 ;
	
	for(i=size_a; i>=0; i--) {
		char temp_res[5][3] ;
		int ta=block_a[i] - '0';
		int temp_int[5] ;
		char buffer[20];
		
		for (j=size_b;j>=0; j--) {			
			temp_int[j] = ta*(block_b[j]-'0') ;
			itoa(temp_int[j], buffer,10);
			printf("%3d(%d)", temp_int[j],strlen(buffer));
		}
		printf("\n");
	}

	return 0;
}