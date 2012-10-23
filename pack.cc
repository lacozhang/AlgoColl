#include <iostream>

using namespace std;

void pack(int a[][1000], int w[], int c[], int limit, int cnt){

		for(int i=0; i<cnt; ++i){
				a[i][0] = 0;
		}

		for(int i=0; i<cnt; i++){
				for(int j=1; j<=limit; ++j){

						if( j < c[i] && i > 0){
								a[i][j] = a[i-1][j];
						}

						if( j < c[i] && 0 == i){
								a[i][j] = 0;
						}

						if( j > c[i] ){
								a[i][j] = a[i-1][j] > a[i-1][j-c[i]] + w[i] ?
										a[i-1][j] : a[i-1][j-c[i]]+w[i];
						}
				}
		}
		cout << "max :" << a[cnt-1][limit] << "\n";
}

int main(int argc, char* argv[]){
		
/*		int a[] = { 100, 99, 98, 1, 2, 3 };
		int b[] = { 1, 2, 3, 4, 5, 40 };

		int size = sizeof(a)/sizeof(int);
		int limit = 0;
		for(int i=0; i<size; ++i){
				limit += a[i];
				limit += b[i];
		}
		cout << "sum:" << limit << "\n";

		limit /= 2;
*/
		int dat[100][1000];
/*
		int* c = new int[size*2];
		for(int i=0; i<size; i++){
				c[i] = a[i];
				c[i+size] = b[i];
		}

		for(int i=0; i<size; ++i){
				cout << c[i] << "\t" << c[i+size] << "\n";
		}
*/
		int w[] = {1, 1, 2, 3, 29, 30, 210, 232, 12311, 12312};
		int limit = 0;
		for(int i=0; i<10; ++i){
				limit += w[i];
		}
		cout << "max:" << limit << "\n";
		pack( dat, w, w, limit/2, 10);
		return 0;
}
