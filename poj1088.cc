#include <iostream>
#include <cstdlib>

using namespace std;

int Fields[105][105];
int Road[105][105];
int d[4][2]={
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}
};


int dfs(int r, int c, int maxr, int maxc){
		int x, y, zmax=0;
		if( Road[r][c] != -1 )
				return Road[r][c];
		for(int k=0; k<4; ++k){
				x = r + d[k][0];
				y = c + d[k][1];
				if( x >= 1 && x <= maxr && y >= 1 && y <= maxc ){
						if( Fields[r][c] < Fields[x][y] )
								continue;
						int tmp = dfs(x,y, maxr, maxc);
						if( (tmp + Fields[r][c] - Fields[x][y]) > zmax )
								zmax = (tmp + Fields[r][c] - Fields[x][y]);
				}
		}
		Road[r][c] = zmax;
		return zmax;
}
int main(int argc, char* argv[]){
		int r, c;
		int x, y, zmax;
		int tmp;
		cin >> r >> c;
		while( r && c ){

				for(int i=0; i<101; i++)
						for(int j=0; j<101; ++j){
								Fields[i][j] = 0;
								Road[i][j] = -1;
						}
								

				for(int i=1; i<=r; i++){
						for(int j=1; j<=c; ++j){
								cin >> Fields[i][j];
								Road[i][j] = -1;
						}
				}

				zmax = 0;
				for(int i=1; i<=r; ++i){
						for(int j=1; j<=c; ++j){
								tmp = dfs(i, j, r, c);
								if( tmp > zmax )
										zmax = tmp;
						}
				}
				
				cout << zmax + 1 << endl;
				cin >> r >> c;
		}
		return 0;
}
