#include <iostream>

using namespace std;

struct ListNode{
		int val;
		ListNode *next;
		ListNode(){
				val = -1;
				next = NULL;
		}
};

ListNode*  makelist(int dat[], int size){

		if(0 == size)
				return NULL;
		ListNode *head = NULL, *tail = NULL;
		for(int i = 0; i<size; ++i){

				ListNode* tmp = new ListNode;
				tmp->val = dat[i];
				if( !head ){
						head = tmp;
				}

				if( tail ){
						tail->next = tmp;
				}
				tail = tmp;
		}

		return head;
}

void outlist(ListNode* root){
		ListNode *iter = root;
		while( iter ){
				cout << iter->val << "\t";
				iter = iter->next;
		}
		cout << "\n";

}

void revlist(ListNode*& root){
		ListNode* head = NULL;

		while( root ){

				ListNode* tmp = root;
				root = root->next;
				tmp->next = head;
				head = tmp;
		}
		root = head;
}

void rout(ListNode* root){
		if( NULL == root )
				return ;
		rout(root->next);
		cout << root->val << "\t";
}

int main(int argc, char* argv[]){
		
		int dat[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		ListNode *root = makelist(dat, 10);
		
		outlist( root );
		revlist( root );
		outlist( root );
		rout( root );

		return 0;
}
