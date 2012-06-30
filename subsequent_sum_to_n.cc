#include <iostream>

using namespace std;

int g_a[100];
int g_b[100];

void print_n( int n ){
		
		for( int i=0; i<100; ++i ){
				g_a[i] = i+1;
		}
		for( int i=0; i<100; ++i ){
				g_b[i] =0;
		}
		int i=0, j=-1, sum=0;
		while( j < n-1 ){
				while( sum < n && j < n){
						++j;
						sum += g_a[j];
				}
				if( sum == n ){
						int k=i;
						while( k <= j ){
								cout << g_a[k] << "\t";
								++k;
						}
						cout << "\n";
						++j;
						sum += g_a[j];
				}
				while( sum > n && i < n){
						sum -= g_a[i];
						++i;
				}
				if( sum == n ){
						int k=i;
						while( k <= j ){
								cout << g_a[k] << "\t";
								++k;
						}
						++j;
						sum += g_a[j];
						cout << "\n";
				}
		}
}

int main( int argc, char* argv[] ){
		int n;
		cout << "n : ";
		cin >> n;
		print_n( n );
		return 0;
}
