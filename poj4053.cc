#include <iostream>
#include <list>
#include <bitset>
#include <string>
#include <cstring>
#include <map>

using namespace std;

struct Finger{
		char str[1100];
		Finger* next;
		Finger(){
				next = NULL;
				memset(str, 0, sizeof(str));
		}
};
struct All{
		All(){
				cnt = 0;
		}
		Finger total[2500];
		int cnt;
		void reset(){
				cnt = 0;
				for(int i=0; i<2500; ++i){
						(total[i]).next = NULL;
				}
		}
		Finger* get(){
				++cnt;
				return &total[cnt-1];
		}
};

All g_all;
char article[5000000];

struct Lst{
		Finger* next;
		Lst(){
				next = NULL;
		}
};

map<int, Lst>  g_cnt;

void add(const char* str){

		char nstr[2000];
		int cnt;
		memset(nstr, 0, sizeof(nstr));

		for(int j=0; *str;){
				switch(*str){
				case '[':
						++str;
						cnt = 0;
						while(isdigit(*str)){
								cnt = cnt*10 + *str -'0';
								++str;
						}
						for(int i=0; i<cnt; ++i, ++j){
								nstr[j] = *str;
						}
						break;
				case ']':
						break;
				default:
						nstr[j] = *str;
						++j;
				}
				++str;
		}

		int len= strlen(nstr);
		Lst& head = g_cnt[len];
		Finger* item = g_all.get();
		strcpy(item->str, nstr);
		item->next = head.next;
		head.next = item;
}

void decode(const char* str){
		int i=0;
		int cnt =0;
		while( *str ){
				switch(*str){
				case '[':
						++str;
						cnt =0;
						while( isdigit(*str) ){
								cnt = cnt*10 + *str -'0';
								++str;
						}
						for(int j=0; j< cnt; ++j,++i){
								article[i] = *str;
						}
						break;
				case ']':
						break;
				default:
						article[i] = *str;
						++i;
				}
				++str;
		}
		article[i] = *str;
}


int count(){

		int cnt;
		string f;
		g_cnt.clear();
		cin >> cnt;
		for(int i=0; i<cnt; ++i){
				cin >> f;
				add( f.c_str() );
		}

		cin >> f;
		decode(f.c_str());
		cnt = 0;
		bitset<5000000> found;
		char* pos;
		found.reset();
		for(int i=1100; i>0; --i){

				Lst& head = g_cnt[i];
				Finger *tmp = head.next;

				while(tmp != NULL ){
						int len = strlen( tmp->str );
						bool fd = false;
						char* nt = article;
						while( pos = strstr(nt, tmp->str) ){
								int j,k;
								for(j=pos-article, k=0; k<len; ++j, ++k){
										if( found.test(j) ){
												break;
										} else {
												found.set(j);
										}
								}
								if( !fd && k>=len ){
										++cnt;
										fd = true;
								}
								if( k<len && fd ){
										--cnt;
										break;
								}
								nt = pos+len;
						}
						tmp = tmp->next;
				}
		}
		return cnt;
}

int main(int argc, char* argv[]){
		
		int cnt = 0;
		cin >> cnt;
		list<int> out;
		for(int i = 0; i<cnt; ++i){
				int ret;
				ret = count();
				g_all.reset();
				out.push_back(ret);
		}

		for(list<int>::iterator iter = out.begin();
			iter != out.end(); ++iter){
				cout << *iter << "\n";
		}
		return 0;
}
