#include <bits/stdc++.h>
using namespace std;

struct QueueArr{
    int front,rear,cap;
    vector<int> a;

    QueueArr(int n){
        cap=n;
        a.resize(n);
        front=0;
        rear=-1;
    }
    bool isFull(){ return rear==cap-1; }
    bool isEmpty(){ return front>rear; }

    void enqueue(int x){
        if(isFull()){ cout<<"Overflow\n"; return; }
        a[++rear]=x;
    }
    void dequeue(){
        if(isEmpty()){ cout<<"Underflow\n"; return; }
        front++;
    }
    void peek(){
        if(isEmpty()){ cout<<"Empty\n"; return; }
        cout<<a[front]<<"\n";
    }
    void display(){
        if(isEmpty()){ cout<<"Empty\n"; return; }
        for(int i=front;i<=rear;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    int n;
    cin>>n;
    QueueArr q(n);
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
