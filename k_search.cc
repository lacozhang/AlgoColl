#include <iostream>
#include <algorithm>

using namespace std;

void out( int data[], int l, int h){
		for( int i=l; i<h; ++i){
				cout << data[i] << "\n";
		}
}

void insert_sort( int data[], int l, int h){
		int k=l+1;
		while( k < h ){
				int i = k-1;
				int tmp=data[k];
				while( i>=l && data[i] > tmp ){
						data[i+1] = data[i];
						--i;
				}
				data[i+1] = tmp;
				++k;
		}
}

int mid(int data[], int l, int h){

		int cnt=(h-l)/5;
		int *ms = new int[cnt+1];
		for(int i=0; i<cnt; ++i){
				insert_sort( data, i*5, (i+1)*5 );
				ms[i] = i*5+2;
		}
		if( cnt*5 < h ){
				insert_sort( data, cnt*5, h);
				switch( h - cnt*5 ){
				case 1:
				case 2:
						ms[cnt]=data[cnt*5];
						break;
				case 3:
				case 4:
						ms[cnt]=data[cnt*5+1];
						break;
				default:
						cout << "error";
						abort();
				}
		}
		insert_sort( ms, 0, cnt+1);
		return ms[(cnt+1)/2];
}

int partion(int data[], int l, int h, int key){
		int i=l-1,j=l;
		while( j< h-1 ){
				if( data[j] < key ){
						++i;
						swap(data[i], data[j]);
				}
				if( data[j] == key ){
						swap(data[j], data[h-1]);
				}
				++j;
		}
		swap( data[i+1], data[h-1] );
		return i+1;
}

int k_sort( int data[], int l, int h, int k){
		if( l == h-1 )
				return data[l];
		if( l >= h )
				return -1;
		int val = mid(data, l, h);
		int pivot = partion(data, l, h, val)-l+1;
		if( k == pivot ){
				return data[pivot];
		} else if( k < pivot ){
				return k_sort( data, l, pivot, k);
		} else 
				return k_sort( data, pivot+1, h, k-pivot );
}


int main(int argc, char* argv[]){
		int data[100];
		for( int i=0; i<100; i++){
				cin >> data[i];
		}
		insert_sort(data, 0, 100);
		out(data, 0, 100);
		return 0;
}
