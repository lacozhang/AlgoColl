/* -*- C++ -*-  */

#include <iostream>
#include <cstdlib>
#include <stack>
#include <stack>

using namespace std;

struct node;

struct node{

		node* left, *right, *parent;
		int val;

		node(){
				left = right = parent = NULL;
				val = -1;
		}
		~node(){
		}

};

struct dlist{
		node *prev, *next;
		dlist(){
				prev = next = NULL;
		}
};

void construct_bst(int data[], int r, int n, node&);
void pre_order(node* r);
void mid_order(node* r);
void nr_mid_order(node* r);
node* predecessor(node* r);
node* min(node* r);
node* max(node* r);
void condouble(dlist&, node* r);
void lca(node* r, int, int);
node* lca_r(node* r, int a, int b);

struct stknode{
		node* dat;
		int freq;
		stknode(){
				dat = NULL;
				freq = 0;
		}
};

int main(int argc, char* argv[]){
		
		int n;
		cout << "node size :";
		cin >> n;
		int *data = new int[n];
		if( NULL == data ){
				cerr << "new failed : main\n";
				abort();
		}
		for(int i=0; i<n; ++i){
				cin >> data[i];
		}

		node root;
		construct_bst( data, 1, n, root);
/*		cout << "pre order\n";
		pre_order( &root );

		cout << "mid order\n";
		mid_order( &root );

		cout << "non recursive version\n";
		nr_mid_order( &root );

		dlist tmp;
		condouble(tmp, &root);
		for(node* i= tmp.prev; i; i = i->right){
				cout << i->val << "\n";
		}
*/
		cout << "post order begin\n";
		bool a = false, b = false;
//		lca( &root, 5, 7);
		lca_r( &root, 4, 5);
		return 0;
}


void construct_bst(int data[], int r, int n, node& root){

		root.val = data[r-1];
		if(r*2 <= n && data[r*2-1] != 0){
				root.left = new node;
				root.left->parent = &root;
				construct_bst(data, r*2, n, *(root.left));
		}
		if((r*2+1) <= n && data[r*2+1-1] != 0){
				root.right = new node;
				root.right->parent = &root;
				construct_bst(data, r*2+1, n, *(root.right));
		}
}

void pre_order(node* r){
		if( !r )
				return;
		cout << r->val << "\n";
		pre_order(r->left);
		pre_order(r->right);
}

void mid_order(node* r){
		if(!r)
				return;
		mid_order(r->left);
		cout << r->val << "\n";
		mid_order(r->right);
}

void nr_mid_order(node *r){
		
		cout << "stack version\n";
		stack<node*> stk;
		node* cur = r;
		while( !stk.empty() || cur ){
				while( cur != NULL ){
						stk.push(cur);
						cur = cur->left;
				}
				cur = stk.top();
				stk.pop();
				cout << cur->val << "  ";
				cur = cur->right;
		}
//		cout << cur->val << "\n";
		cout << "non stack version\n";
		cur = r;
		node *parent = NULL;
		while( 1 ){
				while( cur ){
						parent = cur;
						cur = cur->left;
				}
				cout << parent->val << "  ";
				cur = parent->right;
				while( !cur && parent && parent->parent && parent == parent->parent->right )
						parent = parent->parent;
				if( !cur )
						parent = parent->parent;
				if( !parent )
						break;
		}
		/* version 3 */
/*
		cout << "\nversion 3\n";
		cur = r->left;
		parent = r;
		while( parent != NULL ) {

				while( cur->left ){
						parent = cur;
						cur = cur->left;
				}

				cout << cur->val << "  ";
				node* tmp = cur->right;
				
				if( !tmp ){
						while( parent != NULL && cur == parent->right) {
								cur = parent;
								parent  = parent->parent;
						}
						if( parent ){
								cout << parent->val << "  ";
								tmp = parent->right;
						}
				}
				cur = tmp;

		}
*/
}

node* min(node* r){
		while( r->left != NULL )
				r = r->left;
		return r;
}

node* max(node* r){
		while( r->right != NULL )
				r = r->right;
		return r;
}

node* predecessor(node* r){

		if( r->left )
				return min(r->left);
		node* parent = r->parent;
		while( parent != NULL && parent->left == r ){
				r = parent;
				parent = parent->parent;
		}
		return parent;
}

void condouble(dlist& head, node* r){

		/*convert bst to ordered list*/
		/* mid tree search*/
		if( !r )
				return;
		condouble(head, r->left);
		
		if( NULL == head.prev ){
				head.prev  = r;
		}

		if( NULL !=  head.next ){
				(head.next)->right = r;
		}

		r->left = head.next;

		head.next = r;

		condouble(head, r->right );
}

void lca(node* r, int a, int b){
		stack<stknode>  stk;
		stack<stknode>  astk;
		stack<stknode>  bstk;

		bool fa = false, fb = false;
		stknode cur;
		node *ptr = r;

		while( !stk.empty() || ptr){

				while( ptr != NULL ){
						cur.dat = ptr;
						cur.freq = 1;
						stk.push( cur );
						ptr = ptr->left;
				}

				cur = stk.top();
				stk.pop();
				if( cur.freq == 1 ){
						cur.freq ++ ;
						stk.push( cur );
						ptr = (cur.dat)->right;
				} else {
						if( (cur.dat)->val == a && !fa ){
								fa = true;
								astk = stk;
						}
						
						if( (cur.dat)->val == b && !fb ){
								fb = true;
								bstk = stk;
						}
						
						if( fa && fb ){
								break;
						}

						cout << (cur.dat)->val << "\n";
				}
		}

		cout << "a ancestore\n";
		while( !astk.empty() ){
				stknode tmp = astk.top();
				astk.pop();
				cout << (tmp.dat)->val << "\n";
		}

		cout << "b ancestore\n";
		while( !bstk.empty() ){
				stknode tmp = bstk.top();
				bstk.pop();
				cout << (tmp.dat)->val << "\n";
				
		}
}


node* lca_r(node *root, int a, int b){
		if( !root )
				return NULL;
		if( root->val == a )
				return root;
		if( root->val == b )
				return root;

		node* l = lca_r(root->left, a, b);
		node* r = lca_r(root->right, a, b);

		if( l && r ){
				cout << root->val << "\n";
				return root;
		} else if( l ){
				return l;
		} else if( r ){
				return r;
		} else 
				return NULL;
}
