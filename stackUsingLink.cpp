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

class stack
{
    public:
    Node* link;
    Node* top;

    stack(int data)
    {
        Node* node1=new Node(data);
       
    }
    
    void push(Node* &top,int d)
  {
        Node* temp = new Node(d);
        temp->next = top;
        top = temp;
  }

  void print(Node* &top)
{
    if(top==NULL)
      return;
    
    Node* temp = top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void pop(Node* &top)
{
    Node* temp=top;
    top=top->next;
    delete temp;
}

void peek(Node* &top)
{
  Node* temp=top;
  cout<<temp->data<<endl;

}
};

int main()
{
    
    stack st(10);
    Node* head = new Node(10);
    Node* top = head;
    st.push(top,20);
    st.print(top);
    st.push(top,30);
    st.print(top);
    st.pop(top);
    st.print(top);
    st.peek(top);

    return 0;
}