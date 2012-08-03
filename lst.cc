#include <iostream>

using namespace std;

struct node{
		int val;
		node* next;
		node(){
				val = -1;
				next = NULL;
		}
};

node* clist(int dat[], int n){

		if(0 == n)
				return NULL;
		node* ret = new node;
		ret->val = dat[0];
		ret->next = clist(dat+1, n-1);
}

void lsort(node* r){
		if( !r || r->next == NULL )
				return r;
		int cnt=0;
		for(node* i=r; i; i=i->next){
				cnt++;
		}
		cnt /= 2;
		node* next = NULL, *prev=NULL;
		for(node* next=r, j=0; j<cnt; ++j, next=next->next){
				prev = next;
		}
}

int main(int argc, char* argv[]){
		
		int dat[10];
		for(int i=0; i<10; ++i){
				cin >> dat[i];
		}
		node* root = clist(dat, 10);
/*		for(node* i=root; i; i=i->next){
				cout << i->val << "\n";
		}
*/
		lsort(root);
		return 0;
}
