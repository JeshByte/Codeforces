#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll maxSubarraySum(vector<ll> &arr,string &s) {
    ll res = arr[0];
    ll maxEnding = arr[0];
    for(int i=1;i<arr.size();i++){
        if(s[i]=='1'){
            maxEnding=max(maxEnding+arr[i],arr[i]);
            res=max(res,maxEnding);
        }
        else{
            maxEnding=0;
        }
    }
    return res;
}
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll curr=maxSubarraySum(arr,s);
    if(count(s.begin(),s.end(),'1')==n){
        if(curr==k){
            cout<<"Yes\n";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<'\n';
        }
        else{
            cout<<"No\n";
        }
        return;
    }
    if(curr>k){
        cout<<"No\n";
        return;
    }
    ll ind=s.find('0');
    ll lsum=0,rsum=0;
    ll lmax=0,rmax=0;
    for(int i=ind-1;i>=0 && s[i]=='1';i--){
        lsum+=arr[i];
        lmax=max(lmax,lsum);
    }
    for(int i=ind+1;i<n && s[i]=='1';i++){
        rsum+=arr[i];
        rmax=max(rmax,rsum);
    }
    cout<<"Yes\n";
    ll req=k-(rmax+lmax);
    //cout<<rmax<<" "<<lmax<<'\n';
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(i==ind){
                cout<<req<<" ";
            }
            else{
                cout<<-1000000000000000000<<" ";
            }
        }
        else{
            cout<<arr[i]<<" ";
        }
    }
    cout<<'\n';
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
