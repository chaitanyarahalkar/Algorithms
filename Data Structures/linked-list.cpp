#include <iostream>
#include <stack>

using std::cout;
using std::string;
using std::stack;

struct node
{
	int data;
	node* next;
};

node* create(int arr[],int n){

	node *head,*itr;
	int i = 0;

	itr = new node();
	itr->next = NULL;
	itr->data = arr[i];

	head = itr;

	while(i != n){
		itr->next = new node();
		itr = itr->next;
		itr->data = arr[++i];
	}	
	itr->next = NULL;
	return head;
}

void traverse(node* head){

	while(head->next != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

node* insert(node* head,int val,int pos){
	node *itr = head;

	while(--pos != 1)
		itr = itr->next;

	node *tmp = itr->next;

	itr->next = new node();
	itr = itr->next;
	itr->data = val;
	itr->next = tmp; 

	return head;

}

node* del(node* head,int pos){

	node *itr = head;
	while(--pos != 1)
		itr = itr->next;

	node *tmp = itr->next;
	free(tmp);
	itr->next = itr->next->next;

	return head;

}

string search(node* head,int val){

	node *tmp = head;
	while(tmp != NULL){
		if(tmp->data == val)
			return "Found!\n";
		tmp = tmp->next;
	}
	return "Not found!\n";
}

node* reverse(node* head){

	stack<int> s;
	node* tmp = head;
	node* tmp_head = head;

	while(tmp->next != NULL){
		s.push(tmp->data);
		tmp = tmp->next;
	}  	

	while(!s.empty()){

		tmp_head->data = s.top();
		s.pop();
		tmp_head = tmp_head->next;
	}

	return head;

}
int main(void){

	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(int);


	cout << "Traversal\n";
	node *head = create(arr,n);
	traverse(head);

	int val = 9;
	int pos = 4;
	cout << "Insertion of " << val << " at " << pos << "\n";
	head = insert(head,val,pos);
	traverse(head);

	cout << "Deletion at " << pos << "\n";
	head = del(head,pos);
	traverse(head);

	cout << "Searching " << val << "\n";
	string result = search(head,val);
	cout << result;


	cout << "Reversing\n";
	head = reverse(head);
	traverse(head);

	return 0;
}