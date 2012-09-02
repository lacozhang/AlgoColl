#include <iostream>
#include <string>

using namespace std;

int g_cnt = 0;
string process(string& str){
		int len = str.size();
		int i=0;
		string out="";
		while(i < len){
				if( str[i] == '\"'){
						++g_cnt;
						if(g_cnt%2 == 1){
								out += "``";
						} else {
								out += "''";
						}
				} else {
						out += str[i];
				}
				++i;
		}
		return out;
}

int main(int argc, char* argv[]){
		string ori;
		string out = "";
		while( getline(cin, ori) ){
				out += process(ori);
				out += "\n";
		}
		cout << out << "\n";
		return 0;
}

