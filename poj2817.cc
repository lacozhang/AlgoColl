#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool used[65];
int sticks[65];

int compare(const void* a, const void* b){
		return *((const int*)b) - *((const int*)a);
}


bool cando(int total, int left, int count, int len){

		if( count == 0 && left == 0 )
				return true;

		if( 0 == left )
				left = len;

		for(int i=0; i<total; ++i){

				if( used[i] )
						continue;
				
				if( sticks[i] > left )
						continue;

				used[i] = true;
				
				if( cando(total, left-sticks[i], count-1, len) )
						return true;

				used[i] = false;

				if( sticks[i] == left || left == len ){
						break;
				}
		}
		return false;
}


int main(int argc, char* argv[]){
		
		int n, sum;


		cin >> n;
		while(n){

				memset(sticks, 0, sizeof(sticks));
				memset(used, false, sizeof(used));
				sum = 0;
				for(int i=0; i<n; ++i){
						cin >> sticks[i];
						sum += sticks[i];
				}

				qsort(sticks, n, sizeof(int), compare);
				for(int i=sticks[0]; i<=sum; ++i){
						if( sum %i != 0)
								continue;
						if( cando(n, 0, n, i) ){
								cout << i << endl;
								break;
						}
									   
				}
				cin >> n;
				
		}
		return 0;
}
