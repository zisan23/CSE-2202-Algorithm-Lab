
// implementation of Queue using linked list

#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node *next;

        node(int x)
        {
            data = x;
            next = NULL;
        }

        node()
        {
            next = NULL;
        }
};

class Queue
{
    private:
        int size = 0;
        node *rear = new node();
        node *front = new node();

    public:
        Queue()
        {
            rear = NULL;
            front = NULL;
        }
        int getsize()
        {
            return size;
        }

        void push(int data)
        {
            node *new_node = new node(data);
            new_node->next = NULL;
            if(rear!=NULL)
            {
              rear->next= new_node;
            }
            rear=new_node;
            if (front == NULL)
            {
                front = new_node;
            }
            size++;
        }

        void pop()
        {
            if(empty())
            {
                return;
            }
            node*del=front;
            front=del->next;
            free(del);
            size--;
        }

        int peek()
        {
            return front->data;
        }

        bool empty()
        {
            return (size == 0) ? true : false;
        }

        void clear()
        {
            node *t = front;

            front=NULL;
            rear=NULL;

            while (t != NULL)
            {
                node *del = t;
                t = del->next;
                free(del);
            }
            size = 0;
        }

        bool search(int x)
        {
            node *t =front;

            while (t != NULL)
            {
                if (t->data == x)
                {
                    return true;
                }
                t = t->next;
            }

            return false;
        }

        void print()
        {
            node *t = front;

            while (t != NULL)
            {
                cout << t->data << " ";
                t = t->next;
            }
            cout << endl;
        }
};


void s_sum(int x,Queue a)
{
    Queue b;
    int n=a.getsize();
    for(int i=0;i<n;i++)
    {
        int t=a.peek();
        a.pop();
        a.push(t);
        b.push(t);
    }
    int sum=0;
    int f=0;
    int l=0,minl=INT_MAX;

    for(int i=1;i<=n;i++)
    {
        for(int it=1;it<i;it++)
        {
            a.pop();
        }
        while(sum<x && !a.empty())
        {
            sum+=a.peek();
            a.pop();
            l++;
        }
       
        if(sum==x && l<minl)
        {
           f=i;
           minl=l;
        }
        sum=0;
        l=0;
        while(!a.empty())
        {
            a.pop();
        }
        for(int it=0;it<n;it++)
        {
            int t=b.peek();
            b.pop();
            a.push(t);
            b.push(t);
        }
        
    }

    for(int i=1;i<f;i++)
    {
        b.pop();
    }
    for(int i=1;i<=minl;i++)
    {
        cout<<b.peek()<<" ";
        b.pop();
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    Queue q;
    int n;
    while(cin>>n)
    {
       q.push(n);
    }

    s_sum(7,q);
}