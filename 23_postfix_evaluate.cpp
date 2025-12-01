#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    string tok;
    stack<long long> st;

    while(ss >> tok){
        if(isdigit(tok[0])){
            st.push(stoll(tok));
        }else if(tok=="+" || tok=="-" || tok=="*" || tok=="/"){
            if(st.size()<2){ cout<<"Invalid Expression\n"; return 0; }
            long long b=st.top(); st.pop();
            long long a=st.top(); st.pop();
            if(tok=="+") st.push(a+b);
            else if(tok=="-") st.push(a-b);
            else if(tok=="*") st.push(a*b);
            else{
                if(b==0){ cout<<"Division by zero\n"; return 0; }
                st.push(a/b);
            }
        }else{
            cout<<"Invalid Token\n";
            return 0;
        }
    }

    if(st.size()!=1){ cout<<"Invalid Expression\n"; return 0; }
    cout<<st.top();
}
