#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<int> count(n + 1, 0);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;


    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }


    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            for (int a = 1; a * p <= n; ++a) {
                count[a]++;
            }
        }
    }
    ll ans=accumulate(count.begin(),count.end(),0ll);
    cout<<ans<<'\n';

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
