#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll count(ll N, vector<ll>& primes) {
    if (N < 0) return 0;
    if (N == 0) return 0;

    ll ans = 0;
    ll num_primes = primes.size();

    for (ll i = 0; i < (1 << num_primes); ++i) {
        ll current_product = 1;
        ll set_bits_count = 0;

        for (ll j = 0; j < num_primes; ++j) {
            if ((i >> j) & 1) {
                current_product *= primes[j];
                set_bits_count++;
            }
        }

        if (current_product > N) continue;

        if (set_bits_count % 2 == 1) {
            ans -= (N / current_product);
        } else {
            ans += (N / current_product);
        }
    }
    return ans;
}
void solve(ll t){
    ll l,r;
    cin>>l>>r;
    vector<ll> primes={2,3,5,7};
    ll term1=count(r,primes);
    ll term2=count(l-1,primes);
    cout<<term1-term2<<'\n';
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
