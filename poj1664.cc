#include <iostream>
#include <vector>

using namespace std;

int count(int m, int n, int s){
		int cnt = 0;
		if( n == 0 && m == 0 )
				return 1;
		if( m < 0 || n < 0 ){
				return 0;
		}

		for(int i=s; i<=m; i++){
				int m2 = m-i;
				if( m2 < 0 || n - 1 < 0 )
						continue;
				cnt += count(m2, n-1, i); 
		}
		return cnt;
}

int main(int argc, char* argv[]){
		int cnt=0, n, m;
		vector<int>  out;
		cin >> cnt;

		for(int i=0; i<cnt; ++i){
				cin >> m >> n;
				out.push_back( count(m, n, 0) );
		}

		for(int i=0; i<out.size(); ++i){
				cout << out[i] << "\n";
		}
		return 0;
}
