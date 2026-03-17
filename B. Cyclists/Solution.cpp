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
    ll n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<ll> arr(n+1);
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        arr[i]=input;
    }
    if(k==n){
        ll ans=m/arr[p];
        cout<<ans<<'\n';
        return;
    }
    deque<pair<ll,ll>> dq;
    multiset<pair<ll,ll>> heap;
    bool avail=false;
    for(int i=1;i<=k;i++){
        if(i==p){
            avail=true;
        }
        heap.insert({arr[i],i});
    }
    for(int i=k+1;i<=n;i++){
        dq.push_back({arr[i],i});
    }
    ll total=0;
    ll ans=0;
    while(total<=m){
        if(avail){
            if(total+arr[p]<=m){
            heap.erase({arr[p],p});
            pair<ll,ll> to_add=dq.front();
            heap.insert(to_add);
            dq.pop_front();
            dq.push_back({arr[p],p});
            total+=arr[p];
            avail=false;
            ans++;
            }
            else{
                break;
            }
        }
        else{
            pair<ll,ll> mini=*heap.begin();
            ll cost=mini.first;
            ll ind=mini.second;
            if(total+cost<=m){
            heap.erase({cost,ind});
            pair<ll,ll> to_add=dq.front();
            if(to_add.second==p){
                avail=true;
            }
            heap.insert(to_add);
            dq.pop_front();
            dq.push_back({cost,ind});
            total+=cost;
            }
            else{
                break;
            }
        }
    }
    cout<<ans<<'\n';
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
