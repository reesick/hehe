#include <bits/stdc++.h>
using namespace std;

int prec(const string &op){
    if(op=="+" || op=="-") return 1;
    if(op=="*" || op=="/") return 2;
    if(op=="^") return 3;
    return 0;
}

vector<string> tokenize(const string &s){
    vector<string> t;
    string num;
    for(char c : s){
        if(isdigit(c)){
            num += c;
        }else{
            if(!num.empty()){ t.push_back(num); num.clear(); }
            if(isspace(c)) continue;
            if(string("()+-*/^").find(c)!=string::npos)
                t.push_back(string(1,c));
        }
    }
    if(!num.empty()) t.push_back(num);
    return t;
}

int main(){
    string line;
    getline(cin, line);
    vector<string> infix = tokenize(line);

    reverse(infix.begin(), infix.end());
    for(auto &tok : infix){
        if(tok=="(") tok = ")";
        else if(tok==")") tok = "(";
    }

    vector<string> out;
    stack<string> st;

    for(auto &tok : infix){
        if(isdigit(tok[0])) out.push_back(tok);
        else if(tok=="(") st.push(tok);
        else if(tok==")"){
            while(!st.empty() && st.top()!="("){
                out.push_back(st.top());
                st.pop();
            }
            if(!st.empty() && st.top()=="(") st.pop();
            else { cout<<"Invalid Expression\n"; return 0; }
        }else{
            while(!st.empty() && prec(st.top())>prec(tok) && st.top()!="("){
                out.push_back(st.top());
                st.pop();
            }
            st.push(tok);
        }
    }
    while(!st.empty()){
        if(st.top()=="(" || st.top()==")"){ cout<<"Invalid Expression\n"; return 0; }
        out.push_back(st.top());
        st.pop();
    }

    reverse(out.begin(), out.end());
    for(size_t i=0;i<out.size();i++){
        if(i) cout<<" ";
        cout<<out[i];
    }
}
