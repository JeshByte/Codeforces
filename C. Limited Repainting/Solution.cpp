#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isGood(ll mid,vector<ll>&arr,string& s,ll n,ll k,vector<ll>&comp){
    bool isPaint=false;
    for(int i=0;i<n;i++){
        if(isPaint && s[i]=='B'){
            continue;
        }
        else if(isPaint && s[i]=='R'){
            if(arr[i]<=comp[mid]){
                continue;
            }
            else{
                isPaint=false;
                k--;
            }
        }
        else if(!isPaint && s[i]=='B'){
            if(arr[i]<=comp[mid]){
                continue;
            }
            else{
                if(k>0){
                    isPaint=true;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        else if(!isPaint && s[i]=='R'){
            continue;
        }
    }
    return true;
}
void solve(ll t) {
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
    set<ll>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    vector<ll>comp;
    comp.push_back(0);
    for(auto it:st){
        comp.push_back(it);
    }
    ll low=0;
    ll high=comp.size()-1;
    ll ans=-1;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(isGood(mid,arr,s,n,k,comp)){
            ans=comp[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);
    return 0;
}
