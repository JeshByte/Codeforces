#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
bool check(ll mid,ll n,ll m,ll k){
    ll req=mid+1;
    ll poss=m/req;
    ll remain=m-(req*poss);
    ll total=remain+(poss*mid);
    total*=n;
    if(total>=k){
        return true;
    }
    return false;
}
void solve(ll t){
    ll n,m,k;
    cin>>n>>m>>k;
    ll low=1;
    ll high=m;
    ll ans=-1;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(check(mid,n,m,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
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
