#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

void next_1( char* str ){
		printf("假定位置i不匹配时，如何调整\n");
		int len = strlen( str );
		int *next = (int*)malloc( sizeof(int)*(len+1) );
		memset( next, 0, sizeof(int)*(len+1) );
		next[0]=-1;
		int i=0;
		int k=-1;
		while( i <= len ){
				if( k==-1 || str[i] == str[k] ){
						++i;
						++k;
						while( k != -1 && str[i] == str[k] )
								k = next[k];
						next[i]=k;
				} else 
						k = next[k];
		}
		for( int i=0; i<len; ++i){
				printf("%d\t", next[i]);
		}
		printf("\n");
}

void next_2( char* str ){
		printf("假定位置i匹配，i+1不匹配时，如何调整\n");
		int len = strlen( str );
		int *next = (int*)malloc( sizeof(int)*(len+1));
		memset( next, 0, sizeof(int)*(len+1));
		int k=-1;
		next[0]=-1;
		for( int i=1; i<len; ++i ){
				while( k != -1 && str[k+1] != str[i] )
						k = next[k];
				if( str[k+1] == str[i] )
						k++;
				next[i]=k;
		}
		for( int i=0; i<len; ++i ){
				printf("%d\t", next[i]);
		}
		printf("\n");
}

int max( int a, int b){
		return a>b?a:b;
}

void extend_kmp(const char tgt[], const char pat[]){
		printf("extend kmp\n");
		int* next_p = new int[ strlen(pat) ];
		int* next_t = new int[ strlen(tgt) ];
		memset( next_p, 0, sizeof(int)*strlen(pat));
		memset( next_t, 0, sizeof(int)*strlen(tgt));
		
		int i=0,j=0,k=1;
		while( 1+j < strlen(pat) && pat[j] == pat[1+j] )
				++j;
		next_p[1]=j;
		for( i=2; i<strlen(pat); ++i ){
				int len = k + next_p[k]-1, l = next_p[i-k];
				if( l < len -i + 1 )
						next_p[i]=l;
				else {
						j = max(0, len-i+1);
						while( i+j < strlen(pat) && pat[i+j] == pat[j] )
								++j;
						next_p[i]=j;
						k=i;
				}
		}

		j=0;
		while( j < strlen(tgt) && j < strlen(pat) && tgt[j] == pat[j] )
				++j;
		next_t[0] = j;
		k=0;
		for( i=1; i<strlen(tgt); ++i ){
				int len = k+next_t[k]-1, l=next_p[i-k];
				if( l < len-i+1 )
						next_t[i]=l;
				else {
						j = max(0, len-i+1);
						while( i+j < strlen(tgt) && j < strlen(pat) && tgt[i+j] == pat[j] )
								++j;
						next_t[i]=j;
						k=i;
				}
		}
		printf("string %s\n", tgt);
		printf("pattern %s\n", pat);
		for( i=0; i<strlen(pat); ++i )
				printf("%d\t", next_p[i]);
		printf("\n");
		for( i=0; i<strlen(tgt); ++i )
				printf("%d\t", next_t[i]);
		printf("\n");
}

int main(){
		char* work= "abcabcdabe";
		next_1(work);
		next_2(work);
		extend_kmp( "abcdetdgsabslabckaiabcdeacbed", "abc");
		return 0;
}
