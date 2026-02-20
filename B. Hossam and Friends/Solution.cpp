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
const ll MAXN = 100005;
const ll K = 20; 

ll st[MAXN][K];
ll logs[MAXN];


void precomputeLogs(ll n) {
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i / 2] + 1;
}


void build(const vector<ll>& arr, ll n) {
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}


ll query(ll L, ll R) {
    ll j = logs[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> arr;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        arr.push_back({a,b});
    }
    vector<ll> fr(n+1,n+1);
    for(int i=0;i<m;i++){
        ll a=arr[i].first;
        ll b=arr[i].second;
        fr[a]=min(fr[a],b);
    }
    ll l,r;
    l=1;
    r=1;
    ll ans=0;
    precomputeLogs(n+1);
    build(fr,n+1);
    //cout<<query(2,4)<<'\n';
    //cout<<query(4,4)<<'\n';
    while(r<=n){
        ll mini=query(l,r);
        //cout<<mini<<'\n';
        if(r+1<=n && r+1!=mini){
            r++;
        }
        else{
            ll len=(r-l)+1;
            ans=ans+len;
            l++;
            if(l>r){
                r=l;
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
  solve(i);
  }
  return 0;
}
