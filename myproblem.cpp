#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	struct node* next;
};

void create(struct node* s, int data)
{
	struct node* temp;
	temp=(struct node*) malloc(sizeof(struct node));
	
	temp->data=data;
	temp->next=NULL;
	if(s==NULL)
	{
		temp=s;
	}
}

void display(struct node* head)
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}

int main()
{
	struct node* head;
	head=(struct node*)malloc(sizeof(struct node));
	head=NULL;
	
	create(head, 50);
	create(head, 100);
	create(head, 500);
	
	display(head);
}
