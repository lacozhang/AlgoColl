#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
		
		int n=0, m=0, salary=0, cnt=0;
		string words;
		map<string, int> keywords;
		vector<int>  all;
		cin >> n >> m;
		
		for(int i=0; i<n; ++i){
				cin >> words >> salary;
				keywords[words] = salary;
		}

		for(int i=0; i<m; ++i){

				cnt = 0;
				cin >> words;
				while( words != "." ){
						if( keywords.count(words) ){
								cnt += keywords[words];
						}
						cin >> words;
				}

				all.push_back(cnt);
		}

		for(int i=0; i<all.size(); ++i){
				cout << all[i] << "\n";
		}
		return 0;
}
