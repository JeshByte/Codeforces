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
bool check(ll k,vector<pair<ll,ll>>& arr,ll n){
    pair<ll,ll> range={0,0};
    // if(curr>=arr[0].first && curr<=arr[0].second){
    //     range.first=min(curr-k,arr[0].first)
    // }
    for(int i=0;i<n;i++){
        if(range.first<=arr[i].first && range.second>=arr[i].second){
            range.first=arr[i].first;
            range.second=arr[i].second;
        }
        else if(range.first>=arr[i].first && range.second<=arr[i].second){
            range.first=max(range.first-k,arr[i].first);
            range.second=min(range.second+k,arr[i].second);
        }
        else if(range.first<=arr[i].first && arr[i].first<=range.second && range.second<=arr[i].second){
            range.first=arr[i].first;
            range.second=min(range.second+k,arr[i].second);
        }
        else if(arr[i].first<=range.first && range.first<=arr[i].second && arr[i].second<=range.second){
            range.second=arr[i].second;
            range.first=max(range.first-k,arr[i].first);
        }
        else if(range.second<arr[i].first){
            if(range.second+k>=arr[i].first){
                range.first=arr[i].first;
                range.second=min(range.second+k,arr[i].second);
            }
            else{
                return false;
            }
        }
        else if(arr[i].second<range.first){
            if(range.first-k<=arr[i].second){
                range.second=arr[i].second;
                range.first=max(range.first-k,arr[i].first);
            }
            else{
                return false;
            }
        }
    }
    return true;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }   
    ll low=0,high=1e10;
    ll ans=1e10;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(check(mid,arr,n)){
            ans=min(ans,mid);
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
