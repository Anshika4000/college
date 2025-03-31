#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
      this->data=data;
      this->next=NULL;
    }
};

class queue
{
    public:
    Node* qfront;
    Node* rear;
    
    queue()
    {
        qfront=rear=NULL;
    }

    bool isEmpty()
    {
        if(qfront==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void enqueue(int data)
    {
        Node* temp = new Node(data);
        //empty
        if(qfront==NULL)
        {
            qfront=rear=temp;
        }
        //non empty
        else
        {
          rear->next = temp;
          rear=temp;
        }
    }

    void dequeue()
    {
        //0 node
        if(qfront==NULL)
        {
            cout<<"queue is empty"<<endl;
            return ;
        }
        
        Node* temp=qfront;
        qfront =qfront->next;

        //1 node
        if(qfront==NULL)
        {
           rear=NULL;
           delete temp;
        }
    }

    void peek()
    {
        if(isEmpty())
        {
          cout<<"queue is empty"<<endl;
        }
        else
        {
          cout<<qfront->data<<endl;
        }  
    }
    void print()
    {
        if(qfront==NULL)
           cout<<"queue is empty"<<endl;
        
        Node* temp = qfront;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    queue q;

    q.enqueue(10);
    q.enqueue(24);
    q.enqueue(37);
    q.enqueue(48);

    q.print();
    q.dequeue();
    q.peek();
    q.print();
    if(q.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }

    return 0;
}
