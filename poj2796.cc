#include <iostream>

using namespace std;


int array[6][101];

int pack(int c[6], int w[6], int max){
		
		for(int i=0; i<=100; i++){
				array[0][i] = 0;
		}
		for(int i=0; i<6; ++i){
				array[i][0] = 0;
		}
		for(int i=1; i<6; i++){
				for(int j=1; j<=max; ++j){
						if( j >= c[i] ){ // Important Line
								if( array[i-1][j] < (array[i-1][j-c[i]] + w[i]) ){
										array[i][j] = array[i-1][j-c[i]] + w[i];
								} else {
										array[i][j] = array[i-1][j];
								}
						} else {
								array[i][j] = array[i-1][j];
						}
				}
		}
		return array[5][max];
}

int main(int argc, char* argv[]){
		int max;
		int c[6];
		cin >> max;
		for(int i=1; i<6; ++i){
				cin >> c[i];
		}
		cout << pack(c, c, max) << "\n";
		return 0;
}
