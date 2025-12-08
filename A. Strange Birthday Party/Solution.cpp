#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr1,arr2;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr1.push_back(input);
    }
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        arr2.push_back(input);
    }
    sort(arr1.rbegin(),arr1.rend());
    ll mini=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll curr;
        if(mini<m){
            curr=arr2[mini];
        }
        else{
            curr=1e10;
        }
        ll op1=ans+curr;
        ll op2=ans+arr2[arr1[i]-1];
        if(op1<op2){
            ans=op1;
            mini++;
        }
        else{
            ans=op2;
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
