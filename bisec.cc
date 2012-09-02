#include <iostream>

using namespace std;

int bisearch(int dat[], int s, int e, int v){
		int l=s, h=e, mid;
		while( l<=h ){
				mid = l + (h-l)/2;
				if( dat[mid] >= v ){
						h = mid - 1;
				} else {
						l = mid + 1;
				}
		}
		if( a[h] == v )
				return h;
		else if( a[l] == v )
				return l;
		else
				return -1;
}

int main(int argc, char* argv[]){

		int dat[]={1,2,2,2,3,4,5,6,7,7,7,8,8,9,10};
		while(1){
				int v ;
				cin >> v;
				cout << bisearch( dat, 0, sizeof(dat)/sizeof(int) -1, v) << "\n";
		}
		return 0;
}
