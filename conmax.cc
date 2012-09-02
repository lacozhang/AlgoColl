#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int minstr(const char* str, const char* pat){

		char* i=NULL, *j=NULL;
		int pos=0,k;

		int *num = new int[256];
		memset(num, -1, sizeof(int)*256);
		for(i = const_cast<char*>(pat), pos=0; *i; ++i, pos++){
				num[*i] = pos;
		}

		int* cnt = new int[strlen(pat)];
		memset(cnt, 0, sizeof(int)*strlen(pat));
		int m = strlen(str)+1;
		for( i = const_cast<char*>( str ), k=0,j = const_cast<char*>(str); *i; ++i){

				pos = num[*i];
				if( -1 != pos ){
						if( ! cnt[pos] )
								++k;
						++cnt[pos];
				}
				if( k == strlen(pat ) ){
						while( *j && k == strlen(pat) ){
								pos = num[*j];
								if(-1 != pos ){
										-- cnt[pos];
										if(!cnt[pos]){
												--k;
										}
								}
								++j;
						}
						if( m > (i-j + 1) ){
								m = i-j + 2;
						}
				}
		}
		return m;
}

int main(int argc, char* argv[]){
		

		string a, p;
		cin >> a >> p;
		cout << minstr(a.c_str(), p.c_str());
		return 0;
}
