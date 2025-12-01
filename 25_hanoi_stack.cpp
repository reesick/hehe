#include <bits/stdc++.h>
using namespace std;

struct Frame{
    int n;
    char from, aux, to;
    int state;
};

int main(){
    int n;
    cin>>n;

    stack<Frame> st;
    st.push({n,'A','B','C',0});

    while(!st.empty()){
        Frame &f = st.top();
        if(f.n==0){ st.pop(); continue; }

        if(f.state==0){
            f.state=1;
            st.push({f.n-1,f.from,f.to,f.aux,0});
        }else if(f.state==1){
            cout<<f.from<<" -> "<<f.to<<"\n";
            f.state=2;
            st.push({f.n-1,f.aux,f.from,f.to,0});
        }else{
            st.pop();
        }
    }
}
