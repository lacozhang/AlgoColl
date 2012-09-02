#include <iostream>
#include <cstdlib>

using namespace std;

int len[10000];
int n, k, count;

int compare(const void* a, const void* b){
		return *(int*)b - *(int*)a;
}

int work(int l){
		
		if( 0 == l)
				return true;
		int t = 0;
		for(int i=0; i<n; ++i ){
				t += (len[i])/l;
				if( t >= k)
						return true;
		}
		return false;
}

int main(int argc, char* argv[]){

		int i,b,e;
		cin >> n >> k;

		count = 0;
		for( i=0; i<n; ++i){
				cin >> len[i];
				count += len[i];
		}

		if( count < k)
				cout << 0 << endl;

		qsort(len, n, sizeof(int), compare);
		
		for( b =0, e= (count/k); b <= e; ){
				int mid = (b+e)/2;
				cout << mid <<"\t" << work(mid) << endl;
				if(work(mid))
						b = mid + 1;
				else
						e = mid -1;
		}
		cout << (b-1) << endl;
		return 0;
}
