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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    multiset<pair<ll,ll>>st;
    for(int i=0;i<n;i++){
        st.insert({arr[i],i});
    }
    ll last=n-1;
    ll cnt=0;
    while(!st.empty()){
        auto it=st.end();
        it--;
        ll val=(*it).first;
        ll ind=(*it).second;
        for(int i=ind;i<=last;i++){
            st.erase({arr[i],i});
        }
        cnt++;
        last=ind-1;
        if(last==-1){
            break;
        }
    }
    cout<<cnt<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
