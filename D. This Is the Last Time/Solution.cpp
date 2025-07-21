#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<tuple<ll,ll,ll>> arr;
    for(int i=0;i<n;i++){
        ll l,r,k;
        cin>>l>>r>>k;
        arr.push_back(make_tuple(l,r,k));
    }
    sort(arr.begin(),arr.end());
    // for(int i=0;i<n;i++){
    //     cout<<get<0>(arr[i])<<" "<<get<1>(arr[i])<<" "<<get<2>(arr[i])<<'\n';
    // }
    ll ans=k;
    for(int i=0;i<n;i++){
        if(ans>=get<0>(arr[i]) && ans<=get<1>(arr[i]) && ans<get<2>(arr[i])){
            ans=get<2>(arr[i]);
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
