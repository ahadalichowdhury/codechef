#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};


node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}


struct Deque
{
    node* front;
    node* rear;
    int size;

    Deque()
    {
        front=rear=NULL;
        size=0;
    }

    void pushfront(int data);
    void pushback(int data);
    void popfront();
    void popback();
    void display();
    bool isempty();
    int qsize();
    
};

int Deque::qsize()
{
    return size;
}

bool Deque::isempty()
{
    return(front==NULL);
}

void Deque::pushfront(int x)
{
    node* newNode = getNewNode(x);

    if(front==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    size++;
}


void Deque::pushback(int x)
{
    node* newNode =getNewNode(x);

    if(rear==NULL)
    {
        front=rear=newNode;
    }

    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}


void Deque::popfront()
{
    node* temp = front;

    if(front==rear)
    {
        front=rear=NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        front->prev = NULL;
        free(temp);
    }
    size--;
}


void Deque::popback()
{
    node* temp = rear;

    if(front==rear)
    {
        front=rear=NULL;
        free(temp);
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
        free(temp);
    }
    size--;
}


void Deque::display()
{
    node* temp = front;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;;
        temp = temp->next;
    }
}



int main(){

    Deque dq;

    cout<<"Size = "<<dq.qsize()<<endl;

    dq.pushback(1);
    dq.pushback(2);
    dq.pushback(3);
    dq.pushfront(7);
    dq.pushfront(9);

    cout<<"Size = "<<dq.qsize()<<endl;

    dq.popfront();
    dq.popback();

    dq.display();

    cout<<"Size = "<<dq.qsize()<<endl;


    return 0;
    

}
