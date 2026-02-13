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
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    if(k>=3){
        cout<<0<<'\n';
        return;
    }
    ll mini=*min_element(arr.begin(),arr.end());
    ll minDiff1=2e18;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            minDiff1=min(minDiff1,abs(arr[i]-arr[j]));
        }
    }
    sort(arr.begin(),arr.end());
    ll ans=min(mini,minDiff1);
    if(k==1){
        cout<<ans<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll diff=abs(arr[i]-arr[j]);
            ll ind=lower_bound(arr.begin(),arr.end(),diff)-arr.begin();
            if(ind==n){
                ans=min(ans,abs(diff-arr[n-1]));
                continue;
            }
            else if(arr[ind]==diff){
                cout<<0<<'\n';
                return;
            }
            else{
                ans=min(ans,abs(diff-arr[ind]));
                ans=min(ans,abs(diff-arr[ind-1]));
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
