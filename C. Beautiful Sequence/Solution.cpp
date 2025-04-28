#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll MOD=998244353;
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll ones=0;
    ll ways=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            ones++;
        }
        else if(arr[i]==2){
            ways=(ways*2)+ones;
            ways=ways%MOD;
        }
        else{
            ans=ans+ways;
            ans=ans%MOD;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}
