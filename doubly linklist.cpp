#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
struct node* head;
struct node* tail;

void display()
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<< temp->data<< endl;
		temp=temp->next;
	}
}
void insert(int data)
{
	
	
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
}

int length()
{
	struct node* temp;
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void insertbeg(int data)
{
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
}

void insertend(int data)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
}

void insertinpos(int pos, int data)
{
	int i=1;
	if(pos<1 || pos> length())
	{
		cout<< " this is invalid"<< endl;
	}
	else if(pos==1)
	{
		insertbeg(data);
	}
	else
	{
		struct node* newnode;
		struct node* temp;
		temp=head;
		newnode=(struct node*) malloc(sizeof(struct node));
		newnode->data=data;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	}
}
void insertafterpos(int pos, int data)
{
	int i=1;
	if(pos<1 || pos>length())
	{
		cout<< " this is invalid" << endl;
	}
	else
	{
		struct node* newnode;
		struct node* temp;
		newnode=(struct node*) malloc(sizeof(struct node));
		
		temp=head;
		newnode->data=data;
		while(i< pos)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	}
}
int main()
{
	insert(50);
	insert(40);
	insert(20);
	insert(80);
	insert(90);
	display();
	insertbeg(100);
	display();
	insertend(500);
	display();
	insertinpos(3,1000);
	display();
	insertafterpos(3,5000);
	display();
	
	
	return 0;
}
