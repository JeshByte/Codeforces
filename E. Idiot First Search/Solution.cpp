#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define Ceil(a,b) ((a+b-1)/b)

ll MOD=1e9+7;

ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

ll findInverse(ll n,ll MOD){
    return modExpo(n,MOD-2,MOD);
}

ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}

bool check(ll a,ll b){
    if(a!=b && b!=(7-a)){
        return true;
    }
    return false;
}

ll rec(ll v, vector<vector<ll>>& child, vector<ll>& dp){
    ll moves = 0;
    for(auto ch : child[v]){
        moves = (moves + 1 + rec(ch, child, dp) + 1) % MOD;
    }
    dp[v] = moves;
    return moves;
}

void traverse(ll v, vector<ll>& res, vector<ll>& dp, vector<ll>& parent, vector<vector<ll>>& child){
    ll p = parent[v];
    res[v] = (dp[v] + res[p] + 1) % MOD;
    for(auto ch : child[v]){
        traverse(ch, res, dp, parent, child);
    }
}

void solve(ll t){
    ll n;
    if(!(cin >> n)) return;
    
    vector<vector<ll>> child(n + 1);
    vector<ll> parent(n + 1, 0);
    
    for(int i = 1; i <= n; i++){
        ll l, r;
        cin >> l >> r;
        if(l != 0){
            parent[l] = i;
            child[i].push_back(l);
        }
        if(r != 0){
            parent[r] = i;
            child[i].push_back(r);
        }
    }

    vector<ll> dp(n + 1, 0);
    rec(1, child, dp);
    
    vector<ll> res(n + 1, 0);
    traverse(1, res, dp, parent, child);
    
    for(int i = 1; i <= n; i++){
        cout << res[i] << (i == n ? "" : " ");
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}
