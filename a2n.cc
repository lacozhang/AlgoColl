#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int a2n(const char* str){
		
		if(!str)
				return 0;
		if( !isdigit( *str ) && *str != '+' && *str != '-'){
				cout << "illegal number\n";
				abort();
		}
		int flag = (*str == '-')?-1:1;
		int pos = isdigit(*str)?0:1;
		int num = 0;
		while( *(str+pos) != '\0' ){
				if( ! isdigit(*(str+pos))){
						cout << "illegal number\n";
						abort();
				}
				num = num*10 + (*(str+pos) - '0');
				++pos;
		}
		return flag*num;
}

int main(int argc, char* argv[]){

		string str;
		cin >> str;
		cout << a2n(str.c_str());
		return 0;
}
