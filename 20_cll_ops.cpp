#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insertBeg(Node* head,int x){
    Node* t=new Node{x,NULL};
    if(!head){
        t->next=t;
        return t;
    }
    Node* p=head;
    while(p->next!=head) p=p->next;
    p->next=t; t->next=head;
    return t;
}
Node* insertEnd(Node* head,int x){
    Node* t=new Node{x,NULL};
    if(!head){
        t->next=t;
        return t;
    }
    Node* p=head;
    while(p->next!=head) p=p->next;
    p->next=t; t->next=head;
    return head;
}
Node* deleteBeg(Node* head){
    if(!head||head->next==head) return NULL;
    Node* p=head;
    while(p->next!=head) p=p->next;
    Node* t=head;
    head=head->next;
    p->next=head;
    delete t;
    return head;
}
Node* deleteEnd(Node* head){
    if(!head||head->next==head) return NULL;
    Node* p=head;
    while(p->next->next!=head) p=p->next;
    Node* t=p->next; p->next=head;
    delete t;
    return head;
}
void display(Node* head){
    if(!head) return;
    Node* t=head;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=head);
    cout<<"\n";
}

int main(){
    Node* head=NULL;
    int ch,x;

    while(true){
        cout<<"\n1 InsertBeg\n2 InsertEnd\n3 DeleteBeg\n4 DeleteEnd\n5 Display\n6 Exit\n";
        cin>>ch;

        if(ch==1) cin>>x, head=insertBeg(head,x);
        else if(ch==2) cin>>x, head=insertEnd(head,x);
        else if(ch==3) head=deleteBeg(head);
        else if(ch==4) head=deleteEnd(head);
        else if(ch==5) display(head);
        else break;
    }
}
