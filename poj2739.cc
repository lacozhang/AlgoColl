#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[101];
char b[101];

int main(int argc, char* argv[]){

	double la=0, lb=0;
	int n,i;
	int lena=0, lenb= 0;
	cin >> n;
	for(i=0; i<n; ++i){

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		cin >> a >> b;

		lena = strlen(a);
		lenb = strlen(b);

		a[6] = '\0';
		b[6] = '\0';

		for(int j=0; j<6; ++j){
			if(a[j] == '\0')
				a[j] = '0';
			if( b[j] == '\0' )
				b[j] = '0';
		}

		la = atof(a);
		lb = atof(b);
		cout << (int)((log10(lb/1e5)+(lenb-1))/(log10(la/1e5)+lena-1)) << endl;
	}
	return 0;
}

