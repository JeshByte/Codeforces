#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll start=arr[k-1];
    sort(arr.begin(),arr.end());
    ll idx;
    for(int i=0;i<n;i++){
        if(start==arr[i]){
            idx=i;
            break;
        }
    }
    ll target=arr[n-1];
    ll w=1;
    while(idx<n && arr[idx]!=target){
        ll curr=arr[idx];
        ll req=arr[idx]-w+1;
        ll poss=arr[idx]+req;
        while(idx+1<n && arr[idx+1]<=poss){
            idx++;
        }
        if(arr[idx]==curr){
            cout<<"NO\n";
            return;;
        }
        w+=(arr[idx]-curr);
    }
    if(arr[idx]==target){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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
