#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int eggs[11][200];
int egg(int n, int k){

		for(int i=0; i<=n; i++){
				eggs[i][1] = 1;
				eggs[i][0] = 0;
		}
		
		for(int i=0; i<=k; i++){
				eggs[1][i]=i;
		}

		for(int i=2; i<=n; ++i){
				for(int j=2; j<=k; ++j){
						eggs[i][j] = INT_MAX;
						for(int x=1; x<=k; ++x){
								int m = 1 + max(eggs[i-1][x-1], eggs[i][j-x]);
								if( m < eggs[i][j] )
										eggs[i][j] = m;
						}
				}
		}
}


int main(int argc, char* argv[]){
		int n,k;
		cin >> n >> k;
		egg(n,k);
		cout << eggs[n][k] << endl;
		return 0;
}
