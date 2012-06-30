#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] ){

  char c[200];
  int i=0;
  do {
	scanf("%c", &c[i]);
	++i;
	printf("%c", c[i] );
  }while( c[i] != '\n' );

  c[i] = 0;
  int len = strlen( c );
  for( int i=len-1; i>=0; --i ){
	printf("%c", c[i]);
  }
  return 0;
}
