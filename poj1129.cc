#include <iostream>
#include <string>

using namespace std;

int allnode[27];
bool hascolor[27];
bool used[27];
int color[27];

int main(){
		int num;
		string conn;
		cin >> num;
		while( num ){

				for(int i=0; i<27; i++){
						color[i] = 0;
				}
				for(int i=0; i<num; i++){
						cin >> conn;
						int idx = conn[0] - 'A' + 1;
						int cidx = -1;
						for(int i=0; i<27; i++){
								used[i] = false;
						}
								
						for(int j=2; j<conn.size(); ++j){
								int pdx = conn[j] - 'A' + 1;
								used[color[pdx]] = true;
						}
						for(int j=1; j<=26; ++j){
								if(!used[j]){
										cidx = j;
										break;
								}
						}
						color[idx] = cidx;
				}
				int idxmax = -1;
				for(int i=1; i<=num; i++){
						idxmax = idxmax > color[i] ? idxmax : color[i];
				}
				if( 1 == idxmax )
						cout << "1 channel needed." << endl;
				else
						cout <<idxmax<<" channels needed."<<endl;
				
				cin >> num;
		}
		return 0;
}
