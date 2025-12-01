#include <bits/stdc++.h>
using namespace std;

struct CircularQueue{
    int front,rear,cap;
    vector<int> a;

    CircularQueue(int n){
        cap=n;
        a.resize(n);
        front=0;
        rear=0;
    }
    bool isFull(){ return (rear+1)%cap==front; }
    bool isEmpty(){ return front==rear; }

    void enqueue(int x){
        if(isFull()){ cout<<"Overflow\n"; return; }
        a[rear]=x;
        rear=(rear+1)%cap;
    }
    void dequeue(){
        if(isEmpty()){ cout<<"Underflow\n"; return; }
        front=(front+1)%cap;
    }
    void peek(){
        if(isEmpty()){ cout<<"Empty\n"; return; }
        cout<<a[front]<<"\n";
    }
    void display(){
        if(isEmpty()){ cout<<"Empty\n"; return; }
        int i=front;
        while(i!=rear){
            cout<<a[i]<<" ";
            i=(i+1)%cap;
        }
        cout<<"\n";
    }
};

int main(){
    int n;
    cin>>n;
    CircularQueue q(n);
    int ch,x;

    while(true){
        cout<<"\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin>>ch;
        if(ch==1) cin>>x, q.enqueue(x);
        else if(ch==2) q.dequeue();
        else if(ch==3) q.peek();
        else if(ch==4) q.display();
        else break;
    }
}
