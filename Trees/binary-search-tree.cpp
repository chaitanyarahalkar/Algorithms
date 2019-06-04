#include <iostream>

using std::cout;
using std::string;

struct node{

	int data;
	node *left,*right;

};

node* insert(node* head,int n){

	if(head == NULL){
		head = new node();
		head->data = n;
		head->left = head->right = NULL;
		return head;
	}
	else if(head->data > n)
		head->left = insert(head->left,n);
	else if(head->data < n)
		head->right = insert(head->right,n);

	return head;

}

string search(node* head,int n){

	node *tmp = head;
	while(tmp != NULL){

		if(tmp->data == n)
			return "Found";

		else if(n < tmp->data)
			tmp = tmp->left;

		else if(n > tmp->data)
			tmp = tmp->right;
	}

	return "Not found";
}

node* minimum(node *head){
	node *tmp = head;

	while(tmp && tmp->left != NULL)
		tmp = tmp->left;

	return tmp;
}
node* remove(node *head,int n){

	if(head == NULL)
		return head;

	if(n < head->data)
		head->left = remove(head->left,n);

	else if(n > head->data)
		head->right = remove(head->right,n);

	else{

		if(head->left == NULL){
			node *tmp = head->right;
			free(head);
			return tmp;
		}

		else if(head->right == NULL){
			node *tmp = head->left;
			free(head);
			return tmp;
		}

		node *tmp = minimum(head->right);
		head->data = tmp->data;

		head->right = remove(head->right,tmp->data);


	}

	return head;

}
void inorder(node *head){

	if(head){

		inorder(head->left);
		cout << head->data << "\n";
		inorder(head->right);
	}

}

void preorder(node *head){

	if(head){

		cout << head->data << "\n";
		preorder(head->left);
		preorder(head->right);
	}

}
void postorder(node *head){

	if(head){

		postorder(head->left);
		postorder(head->right);
		cout << head->data << "\n";
	}

}

int main(void){

	int arr[] = {5,4,3,1,8,9,16,7};
	int n = sizeof(arr)/sizeof(int);
	int ele = 8;

	node *head = NULL;
	for(int x:arr)
		head = insert(head,x);


	cout << "In-order traversal\n";
	inorder(head);

	cout << "Pre-order traversal\n";
	preorder(head);

	cout << "Post-order traversal\n";
	postorder(head);

	cout << "Binary search\n";

	string result = search(head,ele);

	cout << result << " element " << ele << "\n";

	head = remove(head,ele);

	cout << "Deleted element " << ele << "\n";  

	preorder(head);

	return 0;
}