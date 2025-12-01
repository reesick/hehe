#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct QueueLL{
    Node *front,*rear;
    QueueLL(){ front=rear=NULL; }

    bool isEmpty(){ return front==NULL; }

    void enqueue(int x){
        Node* t=new Node{x,NULL};
        if(!rear) front=rear=t;
        else rear->next=t, rear=t;
    }
    void dequeue(){
        if(!front){ cout<<"Underflow\n"; return; }
        Node* t=front;
        front=front->next;
        if(!front) rear=NULL;
        delete t;
    }
    void display(){
        if(!front){ cout<<"Empty\n"; return; }
        Node* t=front;
        while(t){ cout<<t->data<<" "; t=t->next; }
        cout<<"\n";
    }
};

int main(){
    QueueLL q;
    int ch,x;

    while(true){
        cout<<"\n1 Enqueue\n2 Dequeue\n3 Display\n4 Exit\n";
        cin>>ch;
        if(ch==1) cin>>x, q.enqueue(x);
        else if(ch==2) q.dequeue();
        else if(ch==3) q.display();
        else break;
    }
}
