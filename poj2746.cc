#include <iostream>

using namespace std;

int get(int n, int m){
		int a=0;
		for(int i=2; i<=n; ++i)
				a = (a+m)%i;
		return a+1;
}

int main(int argc, char* argv[]){

		int n,m;
		cin >> n >> m;

		while( n && m ){
				cout << get(n, m) << endl;
				cin >> n >> m;
		}
		return 0;
}
