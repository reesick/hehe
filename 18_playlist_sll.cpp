#include <bits/stdc++.h>
using namespace std;

struct Song{
    string name;
    Song* next;
    Song* prev;
};

Song* addSong(Song* head,string name){
    Song* t=new Song{name,NULL,NULL};
    if(!head) return t;
    Song* p=head;
    while(p->next) p=p->next;
    p->next=t; t->prev=p;
    return head;
}
Song* deleteSong(Song* head,string name){
    Song* t=head;
    while(t && t->name!=name) t=t->next;
    if(!t) return head;
    if(t->prev) t->prev->next=t->next;
    if(t->next) t->next->prev=t->prev;
    if(t==head) head=t->next;
    delete t;
    return head;
}
void show(Song* head){
    while(head) cout<<head->name<<" ", head=head->next;
    cout<<"\n";
}

int main(){
    Song* head=NULL;
    int ch;
    string s;

    while(true){
        cout<<"\n1 AddSong\n2 DeleteSong\n3 Show\n4 Exit\n";
        cin>>ch;

        if(ch==1) cin>>s, head=addSong(head,s);
        else if(ch==2) cin>>s, head=deleteSong(head,s);
        else if(ch==3) show(head);
        else break;
    }
}
