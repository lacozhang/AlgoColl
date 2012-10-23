#include <iostream>
#include <stack>

using namespace std;

struct inter{
		int s,e;
};

void myqsort(int dat[], int size){
		inter tmp;
		stack<inter> range;
		tmp.s = 0, tmp.e = size-1;
		range.push( tmp );
		while(! range.empty() ){
				tmp = range.top();
				range.pop();
				if( tmp.e - tmp.s <= 0 ){
						continue;
				} else {
						int pivot = dat[tmp.e];
						int i=tmp.s, j=tmp.s-1;
						int s = tmp.s,e=tmp.e;
						while( i < tmp.e ){
								if(dat[i] < pivot ){
										++j;
										swap(dat[j], dat[i]);
								}
								++i;
						}
						swap(dat[j+1], dat[tmp.e]);
						tmp.s = j+2, tmp.e = e;
						range.push( tmp );
						tmp.s = s, tmp.e = j;
						range.push(tmp);
				}
		}
}

int main(){
		int dat[20] = {0};
		int n;
		cin >> n;
		for(int i=0; i<n; ++i){
				cin >> dat[i];
		}
		myqsort(dat, n);
		for(int i=0; i<n; i++){
				cout << dat[i] << endl;
		}
		return 0;
}
