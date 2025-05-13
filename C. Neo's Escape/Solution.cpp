#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }   
    vector<ll> comp;
    for(int i=0;i<n;i++){
        if(comp.empty() || comp[comp.size()-1]!=arr[i]){
            comp.push_back(arr[i]);
        }
    }
    ll ans=0;
    ll len=comp.size();
    if(comp.size()==1){
        cout<<1<<'\n';
        return;
    }
    if(comp[0]>comp[1]){
        ans++;
    }
    if(comp[len-1]>comp[len-2]){
        ans++;
    }
    for(int i=1;i<len-1;i++){
        if(comp[i]>comp[i+1] && comp[i]>comp[i-1]){
            ans++;
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
