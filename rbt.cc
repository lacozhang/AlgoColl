#include <iostream>
#include <cstdlib>
#include "rbt.h"
using namespace std;

class zyless{
public:
		bool operator()(int a1, int a2){
				return a1 < a2;
		}
};

void test(){
		RBTree<int, int, zyless> tmp;
		for(int i=0; i<10000; ++i ){
				tmp.insert(i, rand()%10000);
				tmp.midorder();
				tmp.del(i);
				tmp.midorder();
		}

		for( int i=0; i<100; ++i )
				tmp.insert(i, rand()%1000);
		tmp.midorder();
}


int main(){
		char t;
		while(1){
				test();
				char x;
				cin >> x;
		}
		return 0;
}
