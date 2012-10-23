#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
		int n;
		int i=1;
		int cnt = 0;
		cin >> n;
		while(i <= n){
				cout << "i:" << i << "\n";
				if( i & n ){
						cnt++;
				}
				i <<= 1;
		}

		cout << "count :" << cnt << "\n";
		return 0;
}
