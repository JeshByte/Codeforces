#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
bool check(ll n) {
    for (int m = 2; m <= 20; ++m) { 
        ll low = 2, high = pow(n, 1.0 / m) + 1;
        while (low <= high) {
            ll k = (low + high) / 2;
            ll term = 1;
            ll sum = 1;

            for (int i = 1; i <= m; ++i) {
                term *= k;
                sum += term;
                if (sum > n) break;
            }

            if (sum == n) return true;
            else if (sum < n) low = k + 1;
            else high = k - 1;
        }
    }
    return false;
}

void solve(ll t){
    ll n;
    cin>>n;
    if(check(n)){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
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
