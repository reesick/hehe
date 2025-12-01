#include <bits/stdc++.h>
using namespace std;

struct node{int c,p; node*next;};

node* insert(node*h,int c,int p){
    node*t=new node{c,p,h};
    return t;
}

node* add(node*a,node*b){
    node*res=NULL;
    while(a || b){
        if(a && b && a->p==b->p)
            res = insert(res,a->c+b->c,a->p), a=a->next, b=b->next;
        else if(b==NULL || (a && a->p>b->p))
            res = insert(res,a->c,a->p), a=a->next;
        else
            res = insert(res,b->c,b->p), b=b->next;
    }
    return res;
}

int main(){
    int n,m; cin>>n>>m;
    node *A=NULL,*B=NULL;

    while(n--){int c,p;cin>>c>>p;A=insert(A,c,p);}
    while(m--){int c,p;cin>>c>>p;B=insert(B,c,p);}

    node*R = add(A,B);
    while(R) cout<<R->c<<"x^"<<R->p<<" ", R=R->next;
}
