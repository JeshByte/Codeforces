#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
class DSU{
    vector<ll>parent,rank;
    public:
    DSU(ll n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    ll findParent(ll v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=findParent(parent[v]);
    }
    void Union(ll u,ll v){
        ll pu=findParent(u);
        ll pv=findParent(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
void solve(ll t){
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
    DSU dsu(n);
    for(int i=1;i<=n;i++){
      dsu.Union(i,arr[i-1]);
    }
    map<ll,ll> mp;
    for(int i=1;i<=n;i++){
      ll p=dsu.findParent(i);
      if(mp.find(p)==mp.end()){
        mp[p]=0;
      }
      if(s[i-1]=='0'){
        mp[p]++;
      }
    }
    for(int i=1;i<=n;i++){
      ll p=dsu.findParent(i);
      cout<<mp[p]<<" ";
    }
    cout<<'\n';
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
