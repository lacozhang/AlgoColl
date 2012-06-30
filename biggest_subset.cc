/*最大子数组之和*/
#include <iostream>
#include <cstdlib>

using namespace std;

void biggest( int *a, int size ){
  int *b = (int*)malloc( sizeof(int)*size );
  if( !b ){
	cerr << "error\n";
	abort();
  }

  b[0] = a[0];
  for( int i=1; i < size; ++i ){
	b[i] = b[i-1]+a[i];
  }

  int i=1, m =b[0];
  int start=0, end=0, s=-1;
  while( i<size ){
	
	if( b[i] - b[start] > m ){
	  m = b[i] - b[start];
	  s = start;
	  end = i;
	}
	if( b[i] < b[start] ){
	  start = i;
	}
	++i;
  }

  cout << "max: " << m << "\n";
  cout << "start: " << s << "\tend:" << end << "\n";
  for( int k=s+1; k<=end; ++k ){
	cout << a[k] << "\t" ;
  }
}

int main(){
  int a[10];
  int i=0;
  while( i < 10 ){
	cin >> a[i];
	++i;
  }
  biggest(a, 10);
}
