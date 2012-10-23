#include <iostream>

using namespace std;


int xdivt(int x, int y){
		if( x < y )
				return 0;
		int i=1;
		while( (y << i) < x ){
				++i;
		}
		--i;
		int rest = x - (y << i);
		int a = 1U << i;
		int b = xdivt(rest, y);
		return a + b;
}


int main(int argc, char* argv[]){
		int x,y;
		cin >> x >> y;
		int ret = xdivt(x, y);
		cout << ret << "\n";
		return 0;
}
