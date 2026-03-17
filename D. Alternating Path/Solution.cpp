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
pair<bool,ll> isBipartite(ll root,int n, vector<vector<ll>>& adj) {
    vector<int> color(n+1, -1); 
    queue<int> q;

    color[root] = 0;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u]; 
                q.push(v);
            } else if (color[v] == color[u]) {
                return {false,-1}; 
            }
        }
    }
    ll cnt=max(count(color.begin(),color.end(),1),count(color.begin(),color.end(),0));
    return {true,cnt};
}
void solve(ll t, ll testcases) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1); 
    ll total_ans = 0;
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            ll cnt0 = 0, cnt1 = 0;
            queue<ll> q;
            
            color[i] = 0;
            cnt0++;
            q.push(i);
            possible=true;
            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                for (ll v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) cnt0++; else cnt1++;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        possible = false; 
                    }
                }
            }
            if(possible){
                total_ans += max(cnt0, cnt1);
            }
        }
    }

    //if (!possible) cout << 0 << '\n';
    cout << total_ans << '\n';
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
