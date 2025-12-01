#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* insertBeg(Node* head,int x){
    Node* t=new Node{x,head,NULL};
    if(head) head->prev=t;
    return t;
}
Node* insertEnd(Node* head,int x){
    if(!head) return new Node{x,NULL,NULL};
    Node* t=head;
    while(t->next) t=t->next;
    t->next=new Node{x,NULL,t};
    return head;
}
Node* deleteBeg(Node* head){
    if(!head) return head;
    Node* t=head->next;
    if(t) t->prev=NULL;
    delete head;
    return t;
}
Node* deleteEnd(Node* head){
    if(!head||!head->next) return NULL;
    Node* t=head;
    while(t->next) t=t->next;
    t->prev->next=NULL;
    delete t;
    return head;
}
void displayForward(Node* head){
    while(head) cout<<head->data<<" ", head=head->next;
    cout<<"\n";
}
void displayBackward(Node* head){
    if(!head) return;
    while(head->next) head=head->next;
    while(head) cout<<head->data<<" ", head=head->prev;
    cout<<"\n";
}

int main(){
    Node* head=NULL;
    int ch,x;

    while(true){
        cout<<"\n1 InsertBeg\n2 InsertEnd\n3 DeleteBeg\n4 DeleteEnd\n5 Forward\n6 Reverse\n7 Exit\n";
        cin>>ch;

        if(ch==1) cin>>x, head=insertBeg(head,x);
        else if(ch==2) cin>>x, head=insertEnd(head,x);
        else if(ch==3) head=deleteBeg(head);
        else if(ch==4) head=deleteEnd(head);
        else if(ch==5) displayForward(head);
        else if(ch==6) displayBackward(head);
        else break;
    }
}
