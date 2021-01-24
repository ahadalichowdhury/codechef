#include<iostream>
using namespace std;

#define N 5
int front=-1;
int rear=-1;
int queue[N];
void enqueue(int data)
{
	if(rear== N-1)
	{
		cout<< "thiis is empty" << endl;
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]= data;
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
		cout<< "the queue is empty" << endl;
	}
	else if(front == rear)
	{
		front=rear=-1;
	}
	else
	{
				front++;


	}
}

void display()
{
	if(front==-1 && rear==-1)
	{
		cout<< "the queue is empty" << endl;
	}
	else
	{
		for(int i=front; i<rear+1; i++)
		{
			cout<< queue[i];
		}
	}
	
}
int main()
{
	enqueue(20);
	enqueue(30);
	enqueue(40);
	display();
	dequeue();
	display();
}
