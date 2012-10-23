#include <iostream>
#include <string>

using namespace std;

void stablework(string& str){
	int i= str.size() -1, j=str.size()-1;
	while( i>=0 ){
		if( str[i] != '*' ){
			swap( str[i], str[j] );
			--j;
		}
		--i;
	}
}

int main(int argc, char* argv[]){
	string in;
	cin >> in;
	stablework(in);
	cout << in << "\n";
	return 0;
}
