/* -*- C++ -*- */
#ifndef __RED_BLACK_TREE__
#define __RED_BLACK_TREE__
#include<iostream>
#include<cstdlib>


enum COLOR {
		RED=1,
		BLACK
};

template<class Key, class Val>
struct tnode{
		struct tnode *left, *right, *parent;
		COLOR color;
		Key key;
		Val val;
		tnode(Key k, Val v): key(k), val(v){
				left = right = parent = NULL;
				color = RED;
		}
		~tnode(){
		}
};


template<class Key, class Val, class Less>
class RBTree{
public:
		RBTree(){
				root = NULL;
				cnt = 0;
		}
		~RBTree(){
				destroy(root);
		}

		bool insert(Key k, Val v){
				tnode<Key, Val>* parent = intern_query(k);

				tnode<Key, Val>* tmp = new tnode<Key, Val>(k, v);

				if( NULL == tmp ){
						std::cerr << "RBTree::insert new failed\n";
						std::abort();
				}

				if( NULL == parent ){
						root = tmp;
				} else {

						if( !opt(parent->key, k) && !opt( k, parent->key) ){
								delete tmp;
								return false;
						}

						if( opt(k,parent->key) )
								parent->left = tmp;
						else 
								parent->right = tmp;
						tmp->parent = parent;
				}
#ifdef _DEBUG
				std::cerr << "insert weill, begin fix\n";
#endif
				insert_fix( tmp );
				return true;
		}
		bool query(Key k, Val& v);

		bool del(Key k){

				tnode<Key, Val>* tgt = intern_query(k);
				if( NULL == tgt ){
						return false;
				}
				if( tgt->left && tgt->right ){

						tnode<Key, Val>* rp = successor(tgt);
						if( NULL == rp ){
								std::cerr << "RBTree::del rp is null\n";
								abort();
						}
						tgt->key = rp->key;
						tgt->val = rp->val;
						tgt = rp;
				}
				
				//
				tnode<Key, Val>* son = tgt->left ? tgt->left : tgt->right;
				tnode<Key, Val>* p = tgt->parent;
				bool left = true;

				if( NULL == p ){
						root = son;
				} else if( tgt == p->left ){
						p->left = son;
				} else {
						p->right = son;
						left = false;
				}

				if( NULL != son ){
						son->parent = p;
				}
				
				if( tgt->color == BLACK ){
						if( son && son->color == RED ){
								son->color = BLACK;
						} else {
								del_fix( son, p, left );
						}
				}

				delete tgt;
				return true;

		}

		void midorder(){
				mid_order( root ); 
				std::cout << "\n";
		}

private:

		//如果这个节点的父节点为空，那么说明，这个节点是根，所有不用改动了
		void del_fix(tnode<Key, Val>* tgt, tnode<Key, Val>* p, bool bleft){
				
				if( NULL == p )
						return ;
				del_fix_case2(tgt, p, bleft);
		}

		// 如果在对应的2-3-4树中，父节点有多于一个节点，那么调整节点的方向
		void del_fix_case2(tnode<Key, Val>* tgt, tnode<Key, Val>* p, bool bleft){
				
				tnode<Key, Val>* s= NULL;
				if( bleft ){
						s = p->right;
				} else {
						s = p->left;
				}

				if( p->color == BLACK && s && s->color == RED ){
						p->color = RED;
						s->color = BLACK;
						if( bleft )
								left_rotate(s);
						else
								right_rotate(s);
				}
				del_fix_case3(tgt, p, bleft);
		}
		// 在对应的2-3-4树中，兄弟节点只有一个节点，父节点只有一个节点，只能将兄弟节点和父节点合并，然后继续操作
		void del_fix_case3(tnode<Key, Val>* tgt, tnode<Key, Val>* p, bool bleft){
				
				tnode<Key, Val>* s=NULL;
				if( bleft ){
						s = p->right;
				} else {
						s = p->left;
				}
				
				if( p->color == BLACK && s && s->color == BLACK 
					&& ( !s->left  || s->left->color == BLACK )
					&& ( !s->right || s->right->color == BLACK ) ){
						s->color = RED;
						if( p->parent && p == p->parent->left )
								del_fix(p, p->parent, true);
						else
								del_fix(p, p->parent, false);
				} else {
						del_fix_case4(tgt, p, bleft);
				}
		}
		// 在对应的2-3-4树中，父节点有多于一个节点，兄弟节点只有一个节点，那么只能将相应的父节点和兄弟节点合并即可
		void del_fix_case4(tnode<Key, Val>* tgt, tnode<Key, Val>* p, bool bleft){

				tnode<Key, Val>* s=NULL;
				if( bleft ){
						s = p->right;
				} else {
						s = p->left;
				}
				
				if( p->color == RED && s && s->color == BLACK
					&& ( !s->left || s->left->color == BLACK )
					&& ( !s->right || s->right->color == BLACK ) ){
						p->color == BLACK;
						s->color == RED;
				} else {
						del_fix_case5(tgt, p, bleft);
				}
		}

		void del_fix_case5(tnode<Key, Val>* tgt, tnode<Key, Val>* p, bool bleft){

				tnode<Key, Val>* s=NULL;
				if( bleft ){
						s = p->right;
				} else {
						s = p->left;
				}
				
				if( s->color == BLACK ){

						if( bleft && s->left 
							&& s->left->color == RED
							&& ( !s->right || s->right->color == BLACK ) ){
								s->color = RED;
								s->left->color = BLACK;
								right_rotate( s->left );
						}
						
						if( !bleft && s->right
							&& s->right->color == RED
							&& ( !s->left || s->left->color == BLACK )){
								s->color = RED;
								s->right->color = BLACK;
								left_rotate( s->right );
						}
				}
				del_fix_case6(tgt, p, bleft);

		}

		void del_fix_case6(tnode<Key, Val>* tgt, tnode<Key, Val>* p, bool bleft){

				tnode<Key, Val>* s=NULL;
				if( bleft ){
						s = p->right;
				} else {
						s = p->left;
				}
				
				if( s ){
						s->color = p->color;
				}
				p->color = BLACK;

				if( bleft ){
						s->right->color = BLACK;
						left_rotate(s);
				} else {
						s->left->color = BLACK;
						right_rotate(s);
				}
				
		}

		tnode<Key, Val>* minimum(tnode<Key, Val>* n){

				if( NULL == n )
						return NULL;
				while( n->left != NULL )
						n = n->left;
				return n;
		}

		tnode<Key, Val>* maximum(tnode<Key, Val>* n){
				if( NULL == n )
						return n;
				while( n->right != NULL )
						n = n->right;
				return n;
		}
		tnode<Key, Val>* successor(tnode<Key, Val>* n){

				if( NULL == n )
						return n;
				if( n->right )
						return minimum(n->right);
				tnode<Key, Val>* p = n->parent;
				while( p && n == p->right ){
						n = p;
						p = p->parent;
				}
				return p;
		}

		tnode<Key, Val>* predecessor(tnode<Key, Val>* n){

				if( NULL == n )
						return n;
				if( n->left )
						return maximum( n->left );
				tnode<Key, Val>* p = n->parent;
				while( p && n == p->left ){
						n = p;
						p = p->parent;
				}
				return p;
		}

		void mid_order(tnode<Key, Val>* r){
				if( !r )
						return;
				mid_order( r->left );
				std::cout <<"key:"<< r->key << "\t";
				std::cout <<"val:"<< r->val << "\n";
				mid_order( r->right );
		}
		void right_rotate( tnode<Key, Val>* n){
#ifdef _DEBUG
				std::cerr << "right rotate\n";
#endif
				
				if( NULL == n ){
						std::cerr << "RBTree::right_rotate n is null\n";
						std::abort();
				}
				// get father and ensure its existence
				tnode<Key, Val>* p = n->parent;
				if( NULL == p ){
						std::cerr << "RBTree::right_rotate p NULL\n";
						std::abort();
				}
				// get grand father
				
				tnode<Key, Val>* pp = p->parent;
				// n must be left of p for clockwise rotate
				if( n != p->left ){
						std::cerr << "RBTree::right_rotate error\n";
						std::abort();
				}

				if( NULL == pp ){
						root = n;
				}
				
				p->left = n->right;
				if( n->right != NULL )
						n->right->parent = p;

				n->right = p;
				p->parent = n;

				n->parent = pp;
				if( pp != NULL ){
						if( p == pp->left )
								pp->left = n;
						else
								pp->right = n;
				}
		}

		void left_rotate( tnode<Key, Val>* n){
#ifdef _DEBUG
				std::cerr << "left_rotate\n";
#endif
				
				if( NULL == n ){
						std::cerr << "RBTree::left_rotate n is null\n";
						std::abort();
				}
				tnode<Key, Val>* p = n->parent;
				if( NULL == p ){
						std::cerr << "RBTree::left_rotate p is null\n";
						std::abort();
				}
				tnode<Key, Val>* pp = p->parent;
				
				if( n != p->right ){
						std::cerr << "RBTree::left_rotate error left rotate\n";
						std::abort();
				}

				if( NULL == pp ){
						root = n;
				}

				p->right = n->left;
				if( n->left )
						n->left->parent = p;

				n->left = p;
				p->parent = n;

				n->parent = pp;
				if( pp ){
						if( p == pp->left )
								pp->left = n;
						else
								pp->right = n;
				}
		}

		tnode<Key, Val>* intern_query(Key k){
				tnode<Key, Val>* cur = root, *p=NULL;
				while( cur != NULL ){
						p = cur;
						if(opt( k, cur->key)){
								cur = cur->left;
						} else if(opt(cur->key, k)){
								cur = cur->right;
						} else
								return cur;
				}
				return p;
		}
		tnode<Key, Val>* sibling(tnode<Key, Val>* n){
				if( NULL == n->parent )
						return NULL;
				if( n == n->parent->left )
						return n->parent->right;
				else
						return n->parent->left;
		}
		void insert_fix( tnode<Key, Val>* n ){
				
				if( n->parent == NULL ){
						n->color = BLACK;
						return;
				}

				if( n->parent->color == BLACK )
						return;
				
				tnode<Key, Val>* uncle = sibling(n->parent);
/*				if( NULL == uncle ){
				std::cerr << "RBTree::insert_fix uncle is null\n";
				abort();
				}*/
				tnode<Key, Val>* pp = n->parent->parent;
				if( NULL == pp ){
						std::cerr << "RBTree::insert_fix pp is null\n";
						abort();
				}

				if( uncle && RED == uncle->color ){
						pp->color = RED;
						n->parent->color = uncle->color = BLACK;
						insert_fix( pp );
				} else{
						if( n == n->parent->right && n->parent == pp->left ){
								left_rotate(n);
								n = n->left;
						}
						if( n == n->parent->left && n->parent == pp->right ){
								right_rotate(n);
								n = n->right;
						}
						n->parent->color = BLACK;
						pp->color = RED;
						if( n == n->parent->left )
								right_rotate( n->parent );
						else
								left_rotate( n->parent );
				}
		}

		void destroy(tnode<Key, Val>* r){
				if( !r )
						return;
				destroy(r->left);
				destroy(r->right);
				delete r;
		}
		tnode<Key, Val>* root;
		int cnt;
		Less opt;
};


#endif //__RED_BLACK_TREE__
