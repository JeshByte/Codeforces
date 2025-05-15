#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    ll o=0;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        if(input&1){
            o++;
        }
    }
    ll maxi=*max_element(arr.begin(),arr.end());
    if(o==n || o==0){
        cout<<maxi<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==maxi){
            arr[i]=(-1);
            break;
        }
    }
    vector<ll> odd,even;
    for(int i=0;i<n;i++){
        if(arr[i]==(-1)){
            continue;
        }
        if(arr[i]&1){
            odd.push_back(arr[i]);
        }
        else{
            even.push_back(arr[i]);
        }
    }
    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());
    if(maxi&1){
        for(int i=0;i<odd.size();i++){
            maxi+=(odd[i]-1);
        }
        for(int i=0;i<even.size();i++){
            maxi+=even[i];
        }
    }
    else{
        maxi+=odd[0];
        for(int i=1;i<odd.size();i++){
            maxi+=(odd[i]-1);
        }
        for(int i=0;i<even.size();i++){
            maxi+=even[i];
        }
    }
    cout<<maxi<<'\n';
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
