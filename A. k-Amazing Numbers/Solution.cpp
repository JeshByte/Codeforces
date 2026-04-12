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
    map<ll,pair<ll,ll>> pos;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        pos[input]={-1,0};
    }
    for(int i=0;i<n;i++){
        ll prev=pos[arr[i]].first;
        ll dist=pos[arr[i]].second;
        ll ndist=i-prev;
        dist=max(dist,ndist);
        pos[arr[i]]={i,dist};
    }
    for(auto &it:pos){
        ll prev=it.second.first;
        ll dist=it.second.second;
        ll ndist=n-prev;
        dist=max(dist,ndist);
        it.second={n,dist};
    }
    // for(auto it:pos){
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<'\n';
    // }
    map<ll,ll> kval;
    for(auto it:pos){
        ll val=it.first;
        ll mdist=it.second.second;
        if(kval.find(mdist)!=kval.end()){
            kval[mdist]=min(kval[mdist],val);
        }
        else{
            kval[mdist]=val;
        }
    }
    // for(auto it:kval){
    //     cout<<it.first<<" "<<it.second<<'\n';
    // }
    ll mini=1e6;
    bool found=false;
    for(int i=1;i<=n;i++){
        if(kval.find(i)!=kval.end()){
            mini=min(mini,kval[i]);
            found=true;
        }
        if(!found){
            cout<<-1<<" ";
            continue;
        }
        cout<<mini<<" ";
    }
    cout<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  //generatePowers();
  //rec();
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
