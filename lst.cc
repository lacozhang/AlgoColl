#include <iostream>
#include <cstdlib>

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

int Length(node* head){
		int cnt = 0;
		while( head ){
				cnt++;
				head = head->next;
		}
		return cnt;
}

void Push(node **headref, int newData){
		node *n = new node;
		if( !n ){
				abort();
		}
		n->val = newData;
		n->next = *headref;
		*headref = n;
}

void outlist(node* head){

		while(head){
				cout << head->val << "\t";
				head = head->next;
		}
		cout << "\nEnd\n";
}

void DeleteList(node **head){
		node *tmp = NULL;
		while( *head ){
				tmp = *head;
				*head = (*head)->next;
				delete tmp;
		}
}

void FrontBackSplit(node* source, node** frontRef, node** backRef){

		node* slow = source, *fast = source->next;
		while( fast && fast->next ){
				slow = slow->next;
				fast = fast->next->next;
		}
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
}


int main(int argc, char* argv[]){
		
		node *head = NULL;
		for(int i=1; i<=19; ++i){
				Push(&head, i);
		}
		node *f=NULL, *b=NULL;
		FrontBackSplit(head, &f, &b);
		cout << Length(f) << "\n";
		cout << Length(b) << "\n";
		outlist(f);
		outlist(b);
		DeleteList(&f);
		DeleteList(&b);
		outlist(f);
		outlist(b);

		return 0;
}
