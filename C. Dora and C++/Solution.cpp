#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll comp=__gcd(a,b);
    for(int i=0;i<n;i++){
        arr[i]=arr[i]%comp;
    }
    sort(arr.begin(),arr.end());
    ll maxi=arr[n-1];
    ll ans=1e10;
    for(int i=0;i<n;i++){
        ll diff=maxi-arr[i];
        ans=min(ans,diff);
        maxi=arr[i]+comp;
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve();
  }
  return 0;
} 
