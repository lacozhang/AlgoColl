#include <iostream>
#include <algorithm>

using namespace std;

void c_sort( int* str, int k, int n ){

		int* low = new int[k+1];
		int * high = new int[k+1];
		int* pos = new int[k+1];

		for( int i=0; i<n; ++i ){
				low[str[i]]++;
		}
		
		for( int i=2; i<=k; ++i ){
				low[i] += low[i-1];
		}

		for( int i=1; i<=k; ++i )
				high[i] = low[i];
		for( int i=k; i>1; --i ){
				low[i] = low[i-1];
		}
		low[1] =0;
		
		for( int i=1; i<=k; i++)
				pos[i] = low[i];

		cout << "pos array\n";
		for( int i=1; i<=k; ++i )
				cout << pos[i] << "  ";
		cout << "\n";

		for( int i=0; i<n; ++i ){
				int tmp = str[i];
				while( low[tmp] > i || high[tmp] <= i ){
						swap( str[i], str[pos[tmp]] );
						pos[tmp]++;
						tmp = str[i];
				}
		}
		for( int i=0; i<n; ++i ){
				cout << str[i] << "\t";
		}
		cout << "\n";

}

int main( int argc, char* argv[] ){
		int k;
		int n;
		cout << "n: ";
		cin >> n;
		cout << "k: ";
		cin >> k;
		int* arr = new int[n];
		for( int i=0; i<n; ++i )
		cin >> arr[i];
		c_sort( arr, k, n );
		delete [] arr;
		return 0;
}
