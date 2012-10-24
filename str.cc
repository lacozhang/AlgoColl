#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void lus(const char* str ){
		int len = strlen(str);
		int *idx = new int[256];
		for(int i=0; i<256; ++i){
				idx[i] = -1;
		}

		int i, clen=0, maxlen =0, previdx;

		for(int i=0; i<len; ++i){
				previdx = idx[str[i]];

				if( -1 == previdx || i-clen > previdx )
						++clen;
				else{
						if( clen > maxlen )
								maxlen = clen;
						clen = i-previdx;
				}
				idx[str[i]] = i;
		}
		cout << "max:" << maxlen << "\n";
}

int main(int argc, char* argv[]){
		

		string str;
		cin >> str;
		lus( str.c_str() );
		return 0;
}
