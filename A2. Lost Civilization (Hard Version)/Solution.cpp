#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<pair<ll,ll>> st;
    vector<ll> dp(n,0);
    ll s=0;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top().first==arr[i]+1){
            ll ind=st.top().second;
            ll len=n-ind;
            ll cnt=ind-i;
            dp[ind]=len*cnt;
            //cout<<dp[ind]<<'\n';
            st.pop();
        }
        st.push({arr[i],i});
    }
    for(int i=0;i<n;i++){
        if(dp[i]==0){
            ll len=n-i;
            ll cnt=i+1;
            dp[i]=len*cnt;
        }
    }
    ll ans=accumulate(dp.begin(),dp.end(),0ll);
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
