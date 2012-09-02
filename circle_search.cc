#include <iostream>


using namespace std;

bool find(int *a, int s, int e, int val){
		
		int l=s, h=e, m=0;
		while( l <= h ){

				m = l + (h-l)/2;
				if( a[m] == val ){
						break;
				}

				if( ((a[m] > a[l]) || (a[m] < a[h] && a[h] > val)) && a[m] < val ){
						l = m + 1;
				} else {
						h = m - 1;
				}
		}

		if( a[m] == val )
				return true;
		else 
				return false;
					
}

int minimum(int *a, int s, int e){

		int l=s, h=e, m=0;
		while( l < h ){
				m = l + (h-l)/2;
				if( a[m] < a[l] )
						l = m;
				else
						h = m;
		}
		return m;
}

int main(int argc, char* argv[]){



		int a[]={7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
		int tgt ;
		cin >> tgt;
		cout << find(a, 0, sizeof(a)/sizeof(a[0])-1, tgt) << "\n";
		cout << minimum(a, 0, sizeof(a)/sizeof(a[0])-1) << "\n";
		return 0;
}
