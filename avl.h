#ifndef __AVL_H__
#define __AVL_H__

template<class Key, class Val>
struct tnode{
		tnode(Key k,Val v){
				m_key = k;
				m_val = v;
				left = right = parent = NULL;
		}

		tnode *left, *right, *parent;
		Key m_key;
		Val m_val;
};

template<class Key, class Val, class Less>
class AVLTree{
public:
		AVLTree(){
		}

		~AVLTree(){
		}

		bool find(const Key k, Val& v);
		bool insert(const Key& k, Val& v);
		bool del(const Key& k);

private:

		tnode<Key, Val>* intern_find(const Key& k){
		}

		tnode<Key, Val>* m_root;
};

#endif // __AVL_H__
