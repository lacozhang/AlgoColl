/*给定n和m，要求从1,2，。。。n中任意选数，使其和等于m，列出所有的可能能*/

#include <iostream>
#include <cstring>
using namespace std;

int data[101][101];

void count(int n, int m ){

		for( int col=0; col<=m; col++ )
				data[0][col]=0;
		for( int row=0; row<=m; row++ )
				data[row][0]=1;
		data[0][0]=1;


		for( int row=1; row<=n; row++ ){
				for( int col=1; col<=m; ++col ){
						if( col < row )
								data[row][col] = data[row-1][col];
						else data[row][col] = data[row-1][col] + data[row-1][col-row];
				}
		}
}

void printout( int n, int m ){
		for( int i=n; i>=1; i-- ){
				for( int j=1; j<=m; ++j ){
						cout << data[i][j] << "  ";
				}
				cout << "\n";
		}
}

int cnt[101];
int gcnt=0;

void printfull( int pos, int n, int m ){
		if( m == 0 && n >= 0){

				for( int i=0; i < pos; ++i )
						cout << cnt[i] << "\t";
				cout << "\n";
				gcnt++;
				return;
		}
		if( m < 0 || n < 1){
				return;
		}
		if( n > m ){
				printfull( pos, n-1, m );
		} else {
				cnt[pos]=n;
				printfull( pos+1, n-1, m-n );
				printfull( pos, n-1, m );
		}
}

int main( int argc, char* argv[] ){

		int n,m;
		cout << "n : ";
		cin >> n;
		cout << "m : ";
		cin >> m;
		count( n, m);
		// printout( n, m);
		printfull( 0, n, m);
		cout << "gcnt " << gcnt << "\n";
		cout << "count ";
		cout << data[n][m] << "\n";
		return 0;
}
