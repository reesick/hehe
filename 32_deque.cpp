#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
};

struct DequeLL{
    Node *front,*rear;
    DequeLL(){ front=rear=NULL; }

    bool isEmpty(){ return front==NULL; }

    void insertFront(int x){
        Node* t=new Node{x,front,NULL};
        if(front) front->prev=t;
        front=t;
        if(!rear) rear=t;
    }
    void insertRear(int x){
        Node* t=new Node{x,NULL,rear};
        if(rear) rear->next=t;
        rear=t;
        if(!front) front=t;
    }
    void deleteFront(){
        if(!front){ cout<<"Underflow\n"; return; }
        Node* t=front;
        front=front->next;
        if(front) front->prev=NULL;
        else rear=NULL;
        delete t;
    }
    void deleteRear(){
        if(!rear){ cout<<"Underflow\n"; return; }
        Node* t=rear;
        rear=rear->prev;
        if(rear) rear->next=NULL;
        else front=NULL;
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
    DequeLL dq;
    int ch,x;
    while(true){
        cout<<"\n1 InsertFront\n2 InsertRear\n3 DeleteFront\n4 DeleteRear\n5 Display\n6 Exit\n";
        cin>>ch;
        if(ch==1) cin>>x, dq.insertFront(x);
        else if(ch==2) cin>>x, dq.insertRear(x);
        else if(ch==3) dq.deleteFront();
        else if(ch==4) dq.deleteRear();
        else if(ch==5) dq.display();
        else break;
    }
}
