#include <iostream>
using namespace std;

class queue
{
    int* arr;
    int size;
    int qfront;
    int rear;

    public:
      queue(int size)
      {
        this->size=size;
        arr=new int[size];
        qfront=0;
        rear=0;
      }

      bool isEmpty()
      {
        if(qfront==rear)
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
        if(rear==size)
        {
            cout<<"queue is full"<<endl;
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
      }

      int dequeue()
      {
        if(qfront==rear)
        {
            return -1;
        }
        else
        {
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear)
            {
                qfront=0;
                rear=0;
            }
            return ans;
        }
      }
      int front()
      {
        if(qfront==rear)
           return -1;
        else
        {
            return arr[qfront];
        }
      }
};

int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(24);
    q.enqueue(37);
    q.enqueue(48);
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    if(q.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }

}