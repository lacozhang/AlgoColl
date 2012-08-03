#include <iostream>
#include <list>
#include <map>
#include <string>
#include <cstring>

using namespace std;

void convert(char phone[9], const char* tmp){

		char c[9];
		int i;
		for(i=0; *tmp; ++tmp){
				if( isdigit(*tmp) || isalpha(*tmp) ){
						phone[i] = *tmp;
						++i;
				}
		}
		strcpy(c, phone);
		for(int j=0,k=0; j<9;){
				if( k == 3 ){
						phone[k] = '-';
						k++;
				} else {
						switch(c[j]){
						case 'A':
						case 'B':
						case 'C':
								phone[k] = '2';
								break;
						case 'D':
						case 'E':
						case 'F':
								phone[k] = '3';
								break;
						case 'G':
						case 'H':
						case 'I':
								phone[k] = '4';
								break;
						case 'J':
						case 'K':
						case 'L':
								phone[k] = '5';
								break;
						case 'M':
						case 'N':
						case 'O':
								phone[k] = '6';
								break;
						case 'P':
						case 'R':
						case 'S':
								phone[k] = '7';
								break;
						case 'T':
						case 'U':
						case 'V':
								phone[k] = '8';
								break;
						case 'W':
						case 'X':
						case 'Y':
								phone[k] = '9';
								break;
						default:
								phone[k] = c[j];

						}
						++k;
						++j;
				}
		}
}

int main(int argc, char* argv[]){

		int cnt=0;
		int i =0;
		char p[9];
		map<string, int> phone;
		list<string> all;

		cin >> cnt;
		string str;
		for(i=0; i<cnt; ++i){
				cin >> str;
				all.push_back(str);
		}

		for(list<string>::iterator iter = all.begin(); 
			iter != all.end(); iter++){
				memset(p, 0, sizeof(p));
				convert(p, iter->c_str());
				phone[p] ++;
		}
		bool found = false;
		for(map<string, int>::iterator iter = phone.begin();
			iter != phone.end(); ++iter){
				if( iter->second > 1 ){
						cout << iter->first << " "
							 << iter->second << "\n";
						found = true;
				}
		}
		if(!found){
				cout << "No duplicates.\n";
		}
		return 0;
}
