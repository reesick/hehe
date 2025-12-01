#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;

    stack<long long> st;
    while(n>1){
        st.push(n);
        n--;
    }

    long long res=1;
    while(!st.empty()){
        res*=st.top();
        st.pop();
    }

    cout<<res;
}
