/* 判断输出是不是后续遍历的结果*/
#include<iostream>
#include<vector>

using namespace std;

bool judge( vector<int>& data, int start, int end ){
		
		if( end - start <= 0 )
				return true;
		int root = data.at( end );
		int lpos=-1, rpos=-1;
		bool l=false, r=false;
		bool check=true;

		if( data[start] <= root ){
				l = true;
				lpos = start;
		}

		rpos = start;

		while( rpos <= end && data[rpos] <= root ) ++rpos;
		if( rpos < end ){
				r=true;
		}

		for( int i=lpos; l && i < rpos; ++i ){
				if( data[i] > root )
						check=false;
  
		}

		for( int i=rpos; r && i < end; ++i ){
				if( data[i] <= root )
						check=false;
		}

		if( !check )
				return check;
		else if ( l && r )
				return judge( data, lpos, rpos-1 ) && judge( data, rpos, end-1 );
		else if( l )
				return judge( data, lpos, end-1);
		else return judge( data, rpos, end-1 );

}


int main( int argc, char* argv[] ){
		vector<int> src;
		int val;

		while( cin >> val ){
				src.push_back( val );
		}

		cout << "input over\n";
		if( judge( src, 0, src.size()-1 ) ){
				cout << "True\n";
		}
		else {
				cout << "False\n";
		}
		return 0;
}
