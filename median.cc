#include <iostream>

using namespace std;

int median(int data[], int l, int h){
		return data[(l+h)/2];
}

int findm(int data1[], int data2[], int n){
		int l1=0,l2=0,h1=n-1,h2=n-1;
		while( (l1 <= h1) && (l2 <= h2) ){
				int a=median(data1, l1, h1);
				int b=median(data2, l2, h2);
				if( a == b){
						return a;
				} else if( a > b ){
						h1=(l1+h1)/2-1;
						l2=(l2+h2)/2+1;
				} else {
						l1=(l1+h1)/2+1;
						h2=(l2+h2)/2-1;
				}
		}
		cout << "l1: "<< l1 << "h1:"<< h1<<"\n";
		cout << "l2: "<< l2 << "h2:"<< h2<< "\n";
		if( l1 == h1 )
				return data1[l1];
		if( l2 == h2 )
				return data2[l2];
		return -1;
}

int main(){
		int data1[]={1,2,3,4,7,9,12,14,16,18};
		int data2[]={10,11,12,13,14,15,16,17,18,19};
		cout << findm( data1, data2, 10);
		return 0;
}
