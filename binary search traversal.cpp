#include <iostream>
using namespace std;
typedef struct node Node;
struct node
{
	int data;
	node* left;
	node* right;
};

node *create_node(int item)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	if(new_node==NULL)
	{
		cout<< " Error ,This is empty " <<endl;
		exit(1);
	}
	new_node->data=item;
	new_node->left=NULL;
	new_node->right=NULL;
	
	return new_node;
}

void add_left_child(Node *node, Node *child)
{
	node->left=child;
}

void add_right_child(Node *node, Node *child)
{
	node->right=child;
}

Node *create_tree()
{
	Node *one=create_node(40);
	Node *two=create_node(25);
	Node *three=create_node(78);
	add_left_child(one, two);
	add_right_child(one, three);
	
	Node *four=create_node(10);
	Node *five=create_node(32);
	add_left_child(two, four);
	add_right_child(two, five);
	
	return one;
	
}

void pre_order(Node *node)
{
	cout<<"  " << node->data<<endl;
	
	if(node->left!=NULL)
	{
		pre_order(node->left);
	}
	
	if(node->right!=NULL)
	{
		pre_order(node->right);
	}
}

void post_order(Node *node)
{
	if(node->left!=NULL)
	{
		post_order(node->left);
	}
	
	if(node->right!=NULL)
	{
		post_order(node->right);
	}
	
	cout<<"  " << node->data<<endl;
}

void in_order(Node *node)
{
	if(node->left!=NULL)
	{
		in_order(node->left);
	}
	
	cout<<"  " << node->data;
	
	if(node->right!=NULL)
	{
		in_order(node->right);
	}
	
}

int main()
{
	Node *root = create_tree();
	
	cout<< "the pre order list is : "<< endl;
	
	pre_order(root);
	
	cout<< "the post order list is : "<< endl;
	
	post_order(root);
	
	cout<< "the in order list is : "<< endl;
	
	in_order(root);
	
	
}
