#include <iostream>
#include <list>
#include <bitset>
#include <string>
#include <cstring>

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
		Finger total[2500];
		int cnt;
		Finger *by_cnt[1101];
		void reset(){
				cnt = 0;
				for(int i=0; i<2500; ++i){
						(total[i]).next = NULL;
				}
				for(int i=0; i<1101; ++i){
						by_cnt[i] = NULL;
				}
		}
};

All g_all;
char article[5000000];

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
		Finger& c = g_all.total[g_all.cnt];
		memset( c.str, 0, sizeof(c.str));
		strcpy( c.str, nstr );
		c.next = g_all.by_cnt[len];
		g_all.by_cnt[len] = &c;
		++ g_all.cnt;
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
				Finger* tmp = g_all.by_cnt[i];
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
		for(int i = 0; i<cnt; ++i){
				int ret;
				ret = count();
				cout << ret << "\n";
				g_all.reset();
		}

		return 0;
}
