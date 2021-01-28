
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
		head=head->next;
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
	tail->prev->next=NULL;
	free(temp);
}

void deletefromposition(int position)
{
	struct node* temp;
	int i;
	temp=head;
	while(i<position)
	{
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}
void reverse()
{
	struct node* current, *nextnode;
	current=head;
	while(current !=NULL)
	{
		nextnode=current->next;
		current->next=current->prev;
		current->prev=nextnode;
		current=nextnode;
	}
	current=head;
	head=tail;
	tail=current;
	
}


int main()
{
	insert(50);
	insert(40);
	insert(20);
	insert(80);
	insert(90);
	insertbeg(100);
	insertend(500);
	insertinpos(3,1000);
	insertafterpos(3,5000);
	display();
	
	
	return 0;
}

