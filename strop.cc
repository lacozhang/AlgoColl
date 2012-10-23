#include <iostream>

using namespace std;

void mystrcpy(char* src, char* dst){
		if( !src || !dst )
				return;
		while( *dst ++ = *src ++ );
}

int main(int argc, char* argv[]){

		char s[]= "hello world\n";
		char d[20];
		mystrcpy(s, d);
		cout << d;
		return 0;
}
