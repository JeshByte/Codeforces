#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
char replace(set<char> st){
    for(char i='a';i<='z';i++){
        if(st.find(i)==st.end()){
            return i;
        }
    }
}
void solve(ll t){
    string s;
    cin>>s;
    ll n=s.size();
    if(n==1){
        cout<<s<<'\n';
        return;
    }
    set<char> st;
    for(int i=1;i<n-1;i++){
        if(s[i]==s[i+1] && s[i]==s[i-1]){
            st.clear();
            st.insert(s[i]);
            char ch=replace(st);
            s[i]=ch;
        }
        else if(s[i]==s[i-1] && s[i]!=s[i+1]){
            st.clear();
            st.insert(s[i-1]);
            st.insert(s[i+1]);
            char ch=replace(st);
            s[i]=ch;
        }
        // else if(s[i]!=s[i-1] && s[i]==s[i+1]){
        //     s[i]++;
        //     if(s[i]==s[i-1]){
        //         s[i]++;
        //     }
        // }
    }
    if(s[n-1]==s[n-2]){
        st.clear();
        st.insert(s[n-2]);
        s[n-1]=replace(st);
    }
    cout<<s<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
