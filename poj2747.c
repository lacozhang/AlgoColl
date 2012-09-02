#include <iostream>

using namespace std;

int c(int n){
	int i,j,k,max=0;
	for(i=0; i<=n; ++i ){

		if( i%2 == 0 ){
			j = 0;
		}
		else{
			j = 1;
		}

		for(; j <= n; j += 2){
			for(k=0; k<=n; ++k){
				if( ((j+k)%3 == 0) && ((i+j+k)%5 == 0) ){
					if( i+j+k > max ){
						max = i+j+k;
					}
				}
			}
		}
	}
	return max;
}

int main(int, char* []){
	int n,t;
	cin >> n;
	while( n>0){
		cin >> t;
		cout << c(t) << "\n";
		--n;
	}
	return 0;
}
