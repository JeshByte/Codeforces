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
    bool isSorted=true;
    ll idx=min_element(arr.begin(),arr.end())-arr.begin();
    for(int i=idx;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            isSorted=false;
            break;
        }
    }
    if(isSorted){
        cout<<idx<<'\n';
    }
    else{
        cout<<-1<<'\n';
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
