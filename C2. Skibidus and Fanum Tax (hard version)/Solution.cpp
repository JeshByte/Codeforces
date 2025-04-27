#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve(ll t) {
    ll n,m;
    cin>>n>>m;
    vector<ll>a,b;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        b.push_back(input);
    }
    vector<ll>temp=a;
    sort(temp.begin(),temp.end());
    if(a==temp){
        cout<<"YES\n";
        return;
    }
    sort(b.begin(),b.end());
    ll prev=INT64_MIN;
    for(int i=0;i<n;i++){
        ll req=a[i]+prev;
        ll ind=lower_bound(b.begin(),b.end(),req)-b.begin();
        if(ind==m){
            prev=a[i];
            continue;
        }
        ll ele=b[ind]-a[i];
        if(a[i]<prev){
            a[i]=ele;
            
        }
        else{
        a[i]=min(ele,a[i]);
        }
        prev=a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);
    return 0;
}
