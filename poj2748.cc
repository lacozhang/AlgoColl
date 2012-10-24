#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int mycom(const void* a, const void* b){
	const char* aa = (const char*)a;
	const char* bb = (const char*)b;
	return (*aa) - (*bb);
}

bool avail(char* str, int size, int& pos){
	int j=size-2;
	while( j >= 0 ){
		if( str[j] < str[j+1] ){
			pos = j;
			return true;
		}
		--j;
	}
	return false;
}

int firstb(char* str, int size, int i){

	for(int j=size-1; j>=0;--j){
		if( str[j] > str[i] ){
			return j;
		}
	}
	return -1;
}

void zswap(char& a, char& b){
	char c = a;
	a = b;
	b = c;
}

void zsrange(char* str, int s, int e){
	while(s<e){
		zswap(str[s],str[e]);
		++s;
		--e;
	}
}

void perm(char* str, int size){
	
	int i,k;
	while( avail(str,size,i) ){
		k = firstb(str, size, i);
		zswap(str[i], str[k]);
		zsrange(str, i+1, size-1);
		cout << str << endl;
	}
}

int main(int argc, char* argv[]){

	char str[8];
	cin >> str;
	qsort(str, strlen(str), sizeof(char), mycom);
	cout << str << endl;
	perm(str, strlen(str));
	return 0;
}


