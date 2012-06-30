#include<stdio.h>

#define N 10

void a_test(int c[], int a[]){
	int i=0, j=0;
	for( j=0; j<N; ++j ){
		c[j]=0;
		for( i=0; i<j; ++i ){
			if( (a[i] < a[j]) && (c[i] > c[j]) ) {
				c[j]=c[i];
			}
		}
		c[j]++;
	}
}

int main(int argc, char* argv[]){
	int a[10],c[10];
	int i=0;
	for( i=0; i<N; ++i ){
		scanf("%d", &a[i]);
	}	
	printf("\n");
	a_test(c,a);
	for( i=0; i<N; ++i ){
		printf("%d\t", c[i]);
	}
	return 0;
}
