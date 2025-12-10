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
void bfs(map<ll,vector<ll>>& adj,map<ll,bool>& vis,set<ll>& s1,set<ll>& s2){
    queue<ll>q;
    q.push(1);
    while(!q.empty()){
        ll vert=q.front();
        q.pop();
        if(!s1.count(vert) && !s2.count(vert)){
            s1.insert(vert);
        }
        vis[vert]=true;
        for(auto it:adj[vert]){
            if(!vis[it]){
                if(s1.count(vert)){
                    s2.insert(it);
                }
                else{
                    s1.insert(it);
                }
                q.push(it);
            }
        }
    }
}
void solve(ll t){
    ll n;
    cin>>n;
    map<ll,vector<ll>> adj;
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<ll> s1,s2;
    map<ll,bool>vis;
    bfs(adj,vis,s1,s2);
    ll ans=0;
    ans=(n*(n-1))/2;
    ans-=(n-1);
    ll len1=s1.size(),len2=s2.size();
    ll t1=(len1*(len1-1))/2;
    ll t2=(len2*(len2-1))/2;
    ans-=(t1+t2);
    cout<<ans<<'\n';
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
