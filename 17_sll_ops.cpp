#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insertBeg(Node* head,int x){
    return new Node{x,head};
}
Node* insertEnd(Node* head,int x){
    if(!head) return new Node{x,NULL};
    Node* t=head;
    while(t->next) t=t->next;
    t->next=new Node{x,NULL};
    return head;
}
Node* deleteBeg(Node* head){
    if(!head) return head;
    Node* t=head->next;
    delete head;
    return t;
}
Node* deleteEnd(Node* head){
    if(!head||!head->next) return NULL;
    Node* t=head;
    while(t->next->next) t=t->next;
    delete t->next;
    t->next=NULL;
    return head;
}
int searchLL(Node* head,int key){
    int i=0;
    while(head){
        if(head->data==key) return i;
        head=head->next; i++;
    }
    return -1;
}
void display(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

int main(){
    Node* head=NULL;
    int ch,x;

    while(true){
        cout<<"\n1 InsertBeg\n2 InsertEnd\n3 DeleteBeg\n4 DeleteEnd\n5 Search\n6 Display\n7 Exit\n";
        cin>>ch;

        if(ch==1) cin>>x, head=insertBeg(head,x);
        else if(ch==2) cin>>x, head=insertEnd(head,x);
        else if(ch==3) head=deleteBeg(head);
        else if(ch==4) head=deleteEnd(head);
        else if(ch==5) cin>>x, cout<<searchLL(head,x)<<"\n";
        else if(ch==6) display(head);
        else break;
    }
}
