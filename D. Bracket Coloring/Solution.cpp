#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
 
        exp = exp >> 1;
 
        base = (base * base) % mod;
    }
    return result;
}
ll findInverse(ll n,ll MOD){
    return modExpo(n,MOD-2,MOD);
}
ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}
bool check(string& s){
    stack<char> st;
    ll n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push('(');
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}
void solve(ll t){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1){
        cout<<-1<<'\n';
        return;
    }
    string rs=s;
    reverse(rs.begin(),rs.end());
    if(check(s) || check(rs)){
        cout<<1<<'\n';
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<'\n';
        return;
    }
    stack<pair<char,ll>> st;
    vector<ll> color(n+1,-1);
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push({'(',i});
        }
        else{
            if(!st.empty()){
                pair<char,ll> tp=st.top();
                color[tp.second]=1;
                color[i]=1;
                st.pop();
            }
        }
    }
    string remain="";
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            remain+=s[i];
        }
    }
    string reversed_remain=remain;
    reverse(reversed_remain.begin(),reversed_remain.end());
    if(check(reversed_remain) || check(remain)){
            cout<<2<<'\n';
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=2;
        }
        cout<<color[i]<<" ";
    }
    cout<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
