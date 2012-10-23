#include <iostream>
#include <string>

using namespace std;

void zatoi(char src[], int pos){
		if(!src)
				return 0;
		if( !pos && (src[pos] == '+' || src[pos] == '-') )
				return zatoi(src, pos+1);
}

int main(int argc, char* argv[]){
		string src;
		zatoi( src.c_str(), src.size() );
		return 0;
}
