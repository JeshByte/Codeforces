#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve() {
    ll n;
    cin >> n;
    ll ans=n+Ceil(n,6);
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
