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
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        arr[i]=input;
    }
    ll q;
    cin>>q;
    vector<pair<ll,ll>> queries;
    for(int i=0;i<q;i++){
        ll l,k;
        cin>>l>>k;
        queries.push_back({l,k});
    }
    vector<vector<ll>> prefix(n+1,vector<ll>(32,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<32;j++){
            if(arr[i]&(1ll<<j)){
                prefix[i][j]=1+prefix[i-1][j];
            }
            else{
                prefix[i][j]=prefix[i-1][j];
            }
        }
    }
    vector<ll> res(q+1);
    for(int i=0;i<q;i++){
        ll l=queries[i].first;
        ll k=queries[i].second;
        ll low=l;
        ll high=n;
        ll ans=-1;
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll val=0;
            for(int j=0;j<32;j++){
                if((prefix[mid][j]-prefix[l-1][j])==(mid-l+1)){
                    val+=(1ll<<j);
                }
            }
            if(val>=k){
                //cout<<"hi\n";
                low=mid+1;
                ans=max(ans,mid);
            }
            else{
                high=mid-1;
            }
        }
        res[i]=ans;
    }
    for(int i=0;i<q;i++){
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
  solve(i);
  }
  return 0;
}
