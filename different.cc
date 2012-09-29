#include <iostream>

using namespace std;

int want(int dat[], int size){
	int cnt1=0, cnt2=0, val1, val2;
	for(int i=0; i<size; i++){
		if( 0 == cnt1 || dat[i] == val1){
			cnt1++; val1 = dat[i];
		}else if( 0 == cnt2 || dat[i] == val2 ){
			cnt2++; val2 = dat[i];
		}else {
			cnt1--; cnt2--;
		}
	}
	cnt1 = cnt2 = 0;
	for(int i=0; i<size; i++){
		if( dat[i] == val1 )
			cnt1++;
		if( dat[i] == val2 )
			cnt2++;
	}
	cout << val1 << "\t" << cnt1 << endl;
	cout << val2 << "\t" << cnt2 << endl;
	if( cnt1 > cnt2 )
		return val1;
	else
		return val2;
}

int main(){
	int a[10],m;
	cin >> m;
	for(int i=0; i<m; i++)
		cin >> a[i];
	cout << want(a, m) << endl;
	return 0;
}
