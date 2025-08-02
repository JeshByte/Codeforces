#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
bool fun(string& s,vector<ll>& arr,ll n,ll st,ll e,bool comp,vector<ll>& prev){
    while(st<=e){
        if(comp){
            set<ll> usable;
            if(arr[st]<prev[prev.size()-1]){
                usable.insert(arr[st]);
            }
            if(arr[e]<prev[prev.size()-1]){
                usable.insert(arr[e]);
            }
            if(usable.empty()){
                prev.push_back(max(arr[st],arr[e]));
            }
            else{
                prev.push_back(*usable.begin());
                comp=!comp;
            }
        }
        else{
            set<ll> usable;
            if(arr[st]>prev[prev.size()-1]){
                usable.insert(arr[st]);
            }
            if(arr[e]>prev[prev.size()-1]){
                usable.insert(arr[e]);
            }
            if(usable.empty()){
                prev.push_back(min(arr[st],arr[e]));
            }
            else{
                prev.push_back(*usable.rbegin());
                comp=!comp;
            }
        }
        if(prev[prev.size()-1]==arr[st]){
            s+="L";
            st++;
        }
        else{
            s+="R";
            e--;
        }
    }
    for(int i=0;i<=prev.size()-5;i++){
        if (prev[i] < prev[i+1] && prev[i+1] < prev[i+2] && prev[i+2] < prev[i+3] && prev[i+3] < prev[i+4]) {
            return false;
        }
        if (prev[i] > prev[i+1] && prev[i+1] > prev[i+2] && prev[i+2] > prev[i+3] && prev[i+3] > prev[i+4]) {
            return false;
        }
    }
    return true;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<pair<ll,ll>> larger,smaller;
    if(arr[0]<arr[1]){
        smaller.push_back({0,1});
    }
    else{
        larger.push_back({0,1});
    }
    if(arr[0]<arr[n-1]){
        smaller.push_back({0,n-1});
    }
    else{
        larger.push_back({0,n-1});
    }
    if(arr[n-1]<arr[0]){
        smaller.push_back({n-1,0});
    }
    else{
        larger.push_back({n-1,0});
    }
    if(arr[n-1]<arr[n-2]){
        smaller.push_back({n-1,n-2});
    }
    else{
        larger.push_back({n-1,n-2});
    }
    pair<ll,ll> large={1e6,1e6},small={-1,-1};
    ll val=1e6;
    for(int i=0;i<larger.size();i++){
        if(arr[larger[i].second]<val){
            large=larger[i];
            val=arr[larger[i].second];
        }
    }
    val=-1;
    for(int i=0;i<smaller.size();i++){
        if(arr[smaller[i].second]>val){
            small=smaller[i];
            val=arr[smaller[i].second];
        }
    }
    if(large != pair<ll,ll>{1e6,1e6}){
        bool comp=false;
        string s="";
        ll st=-1,e=-1;
        if(large==pair<ll,ll>{0,1}){
            s+="LL";
            st=2;
            e=n-1;
        }
        if(large==pair<ll,ll>{0,n-1}){
            s+="LR";
            st=1;
            e=n-2;
        }
        if(large==pair<ll,ll>{n-1,0}){
            s+="RL";
            st=1;
            e=n-2;
        }
        if(large==pair<ll,ll>{n-1,n-2}){
            s+="RR";
            st=0;
            e=n-3;
        } 
        vector<ll>prev={arr[large.first],arr[large.second]};
        if(fun(s,arr,n,st,e,comp,prev)){
            cout<<s<<'\n';
            return;
        }
    }
    if(small!=pair<ll,ll>{-1,-1}){
        bool comp=true;
        string s="";
        ll st=-1,e=-1;
        if(small==pair<ll,ll>{0,1}){
            s+="LL";
            st=2;
            e=n-1;
        }
        if(small==pair<ll,ll>{0,n-1}){
            s+="LR";
            st=1;
            e=n-2;
        }
        if(small==pair<ll,ll>{n-1,0}){
            s+="RL";
            st=1;
            e=n-2;
        }
        if(small==pair<ll,ll>{n-1,n-2}){
            s+="RR";
            st=0;
            e=n-3;
        } 
        vector<ll>prev={arr[small.first],arr[small.second]};
        if(fun(s,arr,n,st,e,comp,prev)){
            cout<<s<<'\n';
            return;
        }
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
