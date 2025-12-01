#include <bits/stdc++.h>
using namespace std;

struct Item{
    int data;
    int pr;
};

int main(){
    vector<Item> pq;
    int ch;
    while(true){
        cout<<"\n1 Insert\n2 DeleteHighest\n3 Display\n4 Exit\n";
        cin>>ch;

        if(ch==1){
            Item it;
            cin>>it.data>>it.pr;
            pq.push_back(it);
        }else if(ch==2){
            if(pq.empty()){ cout<<"Empty\n"; continue; }
            int idx=0;
            for(int i=1;i<(int)pq.size();i++)
                if(pq[i].pr>pq[idx].pr) idx=i;
            cout<<"Deleted: "<<pq[idx].data<<" (pr="<<pq[idx].pr<<")\n";
            pq.erase(pq.begin()+idx);
        }else if(ch==3){
            if(pq.empty()){ cout<<"Empty\n"; continue; }
            for(auto &x:pq) cout<<"("<<x.data<<","<<x.pr<<") ";
            cout<<"\n";
        }else break;
    }
}
