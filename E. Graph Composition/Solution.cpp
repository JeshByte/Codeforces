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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<ll,ll>>EF,EG;
    for(int i=0;i<m1;i++){
        ll u,v;
        cin>>u>>v;
        EF.push_back({u,v});
    }
    for(int i=0;i<m2;i++){
        ll u,v;
        cin>>u>>v;
        EG.push_back({u,v});
    }
    DSU* DG=new DSU(n);
    for(int i=0;i<m2;i++){
        DG->Union(EG[i].first,EG[i].second);
    }
    vector<pair<ll,ll>>nEF;
    ll ans=0;
    for(int i=0;i<m1;i++){
        if(DG->findParent(EF[i].first)==DG->findParent(EF[i].second)){
            nEF.push_back(EF[i]);
        }
        else{
            ans++;
        }
    }
    DSU* DF=new DSU(n);
    for(int i=0;i<nEF.size();i++){
        DF->Union(nEF[i].first,nEF[i].second);
    }
    set<ll>sF,sG;
    for(int i=1;i<=n;i++){
        sF.insert(DF->findParent(i));
        sG.insert(DG->findParent(i));
    }
    ans+=(sF.size()-sG.size());
    cout<<ans<<'\n';
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
