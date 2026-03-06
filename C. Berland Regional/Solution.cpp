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
void toBinary(ll n,vector<ll>& bin){
    while(n){
        bin.push_back(n%2);
        n=n/2;
    }
    //reverse(bin.begin(),bin.end());
}
bool check(ll mid,ll n,map<ll,ll>& mp){
    ll incomplete=0;
    ll carry=0;
    for(int i=1;i<=n;i++){
        ll complete=min(mp[i],mid);
        incomplete=incomplete+(mp[i]-complete);
        ll remain=mid-complete;
        carry=carry+(remain/2);
    }
    if(carry>=incomplete){
        return true;
    }
    return false;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> u,s;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        u.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        s.push_back(input);
    }
    vector<vector<ll>> adj(n+1,vector<ll>());
    for(int i=0;i<n;i++){
        adj[u[i]].push_back(s[i]);
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()>1){
            sort(adj[i].rbegin(),adj[i].rend());
        }
    }
    for(int i=1;i<=n;i++){
        ll s=0;
        for(int j=0;j<adj[i].size();j++){
            s+=adj[i][j];
            adj[i][j]=s;
        }
    }
    // for(int i=1;i<=n;i++){
    //     if(adj[i].size()){
    //         for(int j=0;j<adj[i].size();j++){
    //             cout<<adj[i][j]<<" ";
    //         }
    //         cout<<'\n';
    //     }
    // }
    vector<ll> res(n+1,0);
    set<ll> factors;
    for(int i=1;i<=n;i++){
        if(adj[i].size()){
            for(int j=0;j<adj[i].size();j++){
                ll ind=j+1;
                factors.clear();
                factors.insert(1);
                factors.insert(ind);
                for(int k=2;k<=sqrtl(ind+1);k++){
                    // if(ind==4){
                    //     cout<<"hi\n";
                    // }
                    if((ind%k)==0){
                        factors.insert(k);
                        factors.insert(ind/k);
                    }
                }
                for(auto it:factors){
                    // if(ind==4){
                    //     cout<<it<<'\n';
                    // }
                    ll first=j-it;
                    ll val=0;
                    if(first>=0){
                        val=adj[i][first];
                    }
                    res[it]+=(adj[i][j]-val);
                    // if(it==2){
                    //     cout<<i<<" "<<ind<<'\n';
                    // }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
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
