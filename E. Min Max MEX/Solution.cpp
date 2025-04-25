#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
bool isGood(vector<ll>&arr,ll mid,ll n,ll k){
    if(mid==0){
        return true;
    }
    ll cnt=0;
    vector<bool>used(mid,false);
    ll unique=0;
    for(int i=0;i<n;i++){
        if(arr[i]<mid){
            if(!used[arr[i]]){
                used[arr[i]]=true;
                unique++;
                if(unique==mid){
                    cnt++;
                    fill(used.begin(),used.end(),false);
                    unique=0;
                }
            }
        }
    }
    return cnt>=k;
}
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll mex=0;
    vector<ll>temp=arr;
    sort(temp.begin(),temp.end());
    if(temp[0]==0){
        for(int i=0;i<n;i++){
            if(i!=n-1 && temp[i+1]-temp[i]>1){
                mex=temp[i]+1;
                break;
            }
            if(i==n-1){
                mex=temp[i]+1;
            }
        }
    }
    //cout<<mex<<'\n';
    ll low=0;
    ll high=mex;
    ll ans=0;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(isGood(arr,mid,n,k)){
            //cout<<mid<<'\n';
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<'\n';
    //cout<<'\n';
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
