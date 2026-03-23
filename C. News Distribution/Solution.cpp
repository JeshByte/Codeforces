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
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
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
void solve(ll t,ll testcases){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> arr;
    for(int i=0;i<m;i++){
        ll k;
        cin>>k;
        vector<ll> temp;
        for(int j=0;j<k;j++){
            ll input;
            cin>>input;
            temp.push_back(input);
        }
        arr.push_back(temp);
    }
    //cout<<"hi\n";
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<arr[i].size();j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    DSU D=DSU(n);
    for(int i=0;i<m;i++){
        ll len=arr[i].size();
        for(int j=0;j<=len-2;j++){
            D.Union(arr[i][j],arr[i][j+1]);
        }
    }
    map<ll,ll> parent;
    for(int i=1;i<=n;i++){
        parent[D.findParent(i)]++;
    }
    for(int i=1;i<=n;i++){
        cout<<parent[D.findParent(i)]<<" ";
    }
    cout<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
