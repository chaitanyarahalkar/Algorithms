#include <iostream>

using std::cout;
using std::max;

struct node{

	int data,lis;
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

int largest_independent_set(node *root){

	if(root == NULL)
		return 0;

	if(root->lis)
		return root->lis;

	if(root->left == NULL && root->right == NULL)
		return root->lis = 1;
	int lis_excluded = largest_independent_set(root->left) + largest_independent_set(root->right);

	int lis_included = 1;

	if(root->left)
		lis_included += largest_independent_set(root->left->left) + largest_independent_set(root->left->right);
	
	if(root->right)
		lis_included += largest_independent_set(root->right->left) + largest_independent_set(root->right->right);

	root->lis = max(lis_included,lis_excluded);

	return root->lis;

}

int main(void){

	node *root = NULL;

	root = insert(root,20);
	insert(root,8);
	insert(root,4);
	insert(root,12);
	insert(root,10);
	insert(root,14);
	insert(root,22);
	insert(root,25);

	int result = largest_independent_set(root);

	cout << "Largest independent set is " << result << "\n";

	return 0;
}