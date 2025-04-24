#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
int check(ll t,vector<int>a,vector<int>b,int n){
    int diff=1e9+1;
    for(int i=0;i<t;i++){
        diff=min(diff,abs(a[i]-b[n-t+i]));
    }
    for(int i=t;i<n;i++){
        diff=min(diff,abs(a[i]-b[i-t]));
    }
    return diff;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=-1;
    for(ll i=0;i<=n;i++){
        ans=max(ans,check(i,a,b,n));
    }
    cout<<ans<<'\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
