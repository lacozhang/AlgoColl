#include <iostream>
#include <algorithm>
#include <cstdlib>



using namespace std;

void out( int data[], int l, int h){
		for( int i=l; i<=h; ++i ){
				cout << data[i] << " ";
		}
		cout << "\n";
}

int partion(int data[], int l, int h, int p){
		cout << data[p] << "\t" << data[h] << "\n";
		swap( data[p], data[h]);
		int x = data[h];
		int i=l-1, j=l;
		cout << "key: " << x << "\n";
		while( j< h ){
				if( data[j] < x ){
						++i;
						swap( data[i], data[j]);
				}
				++j;
				out( data, l, h);
		}
		swap( data[i+1], data[h] );
		out( data, l, h);
		return i+1;
}

int rsearch(int data[], int i, int n){
		int l=0, h=n-1,k;
		while( l <= h){
				k = rand()%(h-l+1);
				cout << "pos : " << k+l << "\n";
				int q= partion( data, l, h, k+l);
				cout << "q: " << q << "\n";
				cout << "i: " << i << "\n";
				if( q-l+1 == i ){
						return data[q];
				} else if( q-l+1 < i ){
						i = i-q+l-1;
						l = q+1;
				} else {
						h = q-1;
				}
		}
		return -1;
}


int main(int argc, char* argv[]){
		int k;
		int data[]={10,3,4,7,8,2,1,9,5,6};
		cout << "k: ";
		cin >> k;
		out( data, 0, 9);
		cout << rsearch(data, k, 10) << "\n";
		return 0;
}
