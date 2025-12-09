#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,h;
    cin>>n>>h;
    vector<ll> arr;
    for(int i=0;i<n;i++){
      ll input;
      cin>>input;
      arr.push_back(input);
    }
    priority_queue<ll> pq,temp;
    ll ans=0;
    for(int i=0;i<n;i++){
      pq.push(arr[i]);
      temp=pq;
      bool use=true;
      ll total=0;
      while(!temp.empty()){
        ll val=temp.top();
        temp.pop();
        if(use){
          total+=val;
        }
        use=!use;
      }
      if(total<=h){
        ans=i+1;
      }
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
} 
