#include <iostream>

using namespace std;

void lds(int dat[], int size){

		int *cnt = new int[size];
		int *prev = new int[size];
		cnt[0] = 1;
		prev[0] = -1;
		for(int i=1; i<size; ++i){
				prev[i] = -1;
				int l=1;
				for(int j=0; j<i; ++j){
						if(dat[i] < dat[j] && l < cnt[j] + 1){
								l = cnt[j] + 1;
								prev[i] = j;
						}
				}
				cnt[i] = l;
		}

		int pos;
		int max=0;
		for(int i=0; i<size; ++i){
				if( cnt[i] > max ){
						max = cnt[i];
						pos =i;
				}
		}

		while( pos != -1 ){
				cout << dat[pos];
				pos = prev[pos];
		}

		cout << "\n";

		delete cnt;
}

int binsearch(int dat[], int low, int high, int key){
		while(low <= high){
				int mid = (low + high)/2;
				if(dat[mid] == key){
						return mid;
				} else if(dat[mid] > key){
						high = mid - 1;
				} else {
						low = mid + 1;
				}
		}

		return high;
}

void lds2(int dat[], int size){

		for(int l=0, h=size-1; l<h; ++l, --h){
				int tmp = dat[h];
				dat[h] = dat[l];
				dat[l] = tmp;
		}

		for(int i=0; i<size; ++i)
				cout << dat[i] << "\t";
		cout << "\n";

		int *active = new int[size + 1];
		int maxl = 1;
		active[1] = dat[0];

		for(int i=1; i<size; ++i){
				cout << "round begin\n";
				cout << "active list:";
				for(int j=1; j<=maxl; ++j)
						cout << active[j] << "\t";
				cout << "\n";

				if(dat[i] < active[1]){
						active[1] = dat[i];
				} else if(dat[i] > active[maxl]){
						maxl++;
						active[maxl] = dat[i];
				} else {
						int p = binsearch(active, 1, maxl, dat[i]);
						cout << "bin pos:" << p << "\n";
						active[p + 1] = dat[i];
				}
		}

		cout << "max len:" << maxl << "\n";
		delete [] active;
		
}

int main(int argc, char* argv[]){

		int dat[]={ 2, 5, 3, 7, 11, 8, 10, 13, 6 };

		lds(dat, 9);
		lds2(dat, 9);

		return 0;
}
