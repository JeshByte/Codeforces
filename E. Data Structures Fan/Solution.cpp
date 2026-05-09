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
    string s;
    cin>>s;
    ll q;
    cin>>q;
    vector<vector<ll>> queries;
    for(int i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll l,r;
            cin>>l>>r;
            queries.push_back({type,l,r});
        }
        else{
            ll g;
            cin>>g;
            queries.push_back({type,g});
        }
    }
    vector<ll> preXor(n+1,0);
    for(int i=0;i<n;i++){
        preXor[i+1]=preXor[i]^arr[i];
    }
    ll zeroXor,oneXor;
    zeroXor=oneXor=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zeroXor=zeroXor^arr[i];
        }
        else{
            oneXor=oneXor^arr[i];
        }
    }
    for(int i=0;i<q;i++){
        ll type=queries[i][0];
        if(type==1){
            ll l=queries[i][1];
            ll r=queries[i][2];
            l--;
            r--;
            ll subXor=preXor[r+1]^preXor[l];
            zeroXor=zeroXor^subXor;
            oneXor=oneXor^subXor;
        }
        else{
            ll g=queries[i][1];
            if(g==0){
                cout<<zeroXor<<" ";
            }
            else{
                cout<<oneXor<<" ";
            }
        }
    }
    cout<<'\n';
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
