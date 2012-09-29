#include <iostream>
#include <set>

using namespace std;

int a[]={1,2,3,4};

void subset(int dat[], int pos, int n, set<int>& path){

		if(pos == n ){
				set<int>::iterator iter = path.begin();
				while( iter != path.end() ){
						cout << *iter << "\t";
						iter++;
				}
				cout << endl;
				return;
		}
		path.insert( dat[pos] );
		subset( dat, pos+1, n, path);
		path.erase( dat[pos] );
		subset( dat, pos+1, n,path);

}

		
int main(int argc, char* argv[]){
		set<int> work;
		subset(a, 0, (sizeof(a)/sizeof(int)), work);
		return 0;
}

