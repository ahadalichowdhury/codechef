#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* link;
	struct node* prev;
};
struct node* head,*tail;
void inssertbeg(int value)
{
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	newnode->data=value;
	newnode->prev=NULL;
	newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
		
	}
	else
	{
		newnode->link=head;
		head->prev=newnode;
		head=newnode;
	}
}
void insert(int data)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->link=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->link=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
}
int print()
{
    struct node * temp;
    temp= head;
    while(temp!= NULL)
    {
        cout<< temp->data << endl;
           temp=temp-> link;
    }
}

void insertend(int data)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	newnode->prev=NULL;
	tail->link=newnode;
	newnode->prev= tail;
	tail=newnode;
}
void insertatposition(int position, int data)
{
	int i=1;
	
	if(position==1)
	{
		
		
	}
	else
	{
	struct node* newnode, *temp;
	temp=head;
	newnode=(struct node*) malloc (sizeof(struct node));
	newnode->data=data;
	while(i<position-1)
	{
		temp=temp->link;
		i++;
	}
	newnode->prev=temp;
	newnode->link=temp->link;
	temp->link=newnode;
	newnode->link->prev=newnode;
		
	}
}
void deletebeg()
{
	struct node* temp;
	if(head== NULL)
	{
		cout<< "the node is empty"<< endl;
	}
	else
	{
		temp=head;
		head=head->link;
		head->prev=NULL;
		free(temp);
	}
}
void deleteend()
{
	struct node* temp;
	if(tail==NULL)
	{
		cout<< "this is empty" << endl;
	}
	temp=tail;
	tail=tail->prev;
	tail->prev->link=NULL;
	free(temp);
}

void deletefromposition(int position)
{
	struct node* temp;
	int i;
	temp=head;
	while(i<position)
	{
		temp=temp->link;
		i++;
	}
	temp->prev->link=temp->link;
	temp->link->prev=temp->prev;
	free(temp);
}
void reverse()
{
	struct node* current, *nextnode;
	current=head;
	while(current !=NULL)
	{
		nextnode=current->link;
		current->link=current->prev;
		current->prev=nextnode;
		current=nextnode;
	}
	current=head;
	head=tail;
	tail=current;
	
}

int main()
{
	head=NULL;
	tail=NULL;
	insert(30);
	insert(40);
	print();
	beg(5);
	print();
	insertend(50);
	print();
	insertatposition(3,100);
	print();
	deletebeg();
	print();
	deleteend();
	print();
	deletefromposition(3);
	print();
	//reverse();
	//print();
	
	return 0;
}

