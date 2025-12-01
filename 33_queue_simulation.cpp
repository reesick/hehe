#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;
    int ch;
    string job;

    while(true){
        cout<<"\n1 AddJob\n2 ProcessJob\n3 ShowQueue\n4 Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>job;
            q.push(job);
        }else if(ch==2){
            if(q.empty()){ cout<<"No Jobs\n"; continue; }
            cout<<"Processing: "<<q.front()<<"\n";
            q.pop();
        }else if(ch==3){
            if(q.empty()){ cout<<"Empty\n"; continue; }
            {
                queue<string> t=q;
                while(!t.empty()){
                    cout<<t.front()<<" ";
                    t.pop();
                }
                cout<<"\n";
            }
        }else break;
    }
}
