#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>arr;
    for(int i=0;i<x;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    sort(arr.begin(),arr.end());
    if(x==2){
        ll ans=0;
        ll left=arr[1]-arr[0]-1;
        if(left==1){
            ans++;
        }
        ll right=(arr[0]-1)+(n-arr[1]);
        if(right==1){
            ans++;
        }
        cout<<ans<<'\n';
        return;
    }
    ll ans=x-2;
    for(int i=0;i<x-1;i++){
        if(arr[i]+1!=arr[i+1]){
            ll left=arr[i+1]-arr[i]-1;
            if(left==1){
                ans++;
            }
        }
    }
    if(arr[x-1]==n && arr[0]==2){
        ans++;
    }
    else if(arr[x-1]==n-1 && arr[0]==1){
        ans++;
    }
    else if(arr[x-1]+2==arr[0]){
        ans++;
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
