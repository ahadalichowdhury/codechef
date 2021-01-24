#include<iostream>
using namespace std;
#define N 5
int top=-1;
int stack[N];

void push(int data)
{
	if(top==N-1)
	{
		cout<< " this is overflow"<< endl;
	}
	else
	{
		top++;
		stack[top]=data;
	}
}
void display()
{
	int i;
	for(i=top;i>=0; i--)
	{
		cout<< stack[i]<< " ";
	}
}
void pop()
{
	
	if(top==-1)
	{
		cout<< "this is empty"<< endl;
	}
	else
	{
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		cout<< " empty";
	}
	else
	{
		cout<< stack[top];
	}
}
int main()
{
	push(50);
	push(60);
	display();
	peek();
	pop();
	display();
}
