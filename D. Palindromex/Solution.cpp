#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
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
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
ll findNext(ll val,ll i,map<ll,vector<ll>>& mp){
    ll f=mp[val][0];
    ll s=mp[val][1];
    if(i==f){
        return s;
    }
    return f;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<2*n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    map<ll,vector<ll>> mp;
    for(int i=0;i<2*n;i++){
        mp[arr[i]].push_back(i);
    }
    ll i=0;
    ll ans=1;
    while(i<2*n){
        ll next=findNext(arr[i],i,mp);
        if(next<i){
            i++;
            continue;
        }
        //cout<<i<<" "<<next<<'\n';
        ll start=i;
        ll end=next;
        set<ll> st;
        bool found=true;
        // if(i==1 && next==5){
        //     cout<<start<<" "<<end<<'\n';
        // }
        while(true){
            if(start<2*n && end>=0 && start<=end && arr[start]==arr[end]){
                st.insert(arr[start]);
                if((end-start)<=1){
                    break;
                }
                start++;
                end--;
            }
            else{
                //cout<<start<<" "<<end<<'\n';
                found=false;
                break;
            }
        }
        // if(i==1 && next==5){
        //     if(found){
        //         cout<<"hi\n";
        //     }
        //     cout<<start<<" "<<end<<'\n';
        // }
        if(found){
            //cout<<"hi\n";
            ll need=0;
            for(auto it:st){
                if(it==need){
                    need++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,need);
            i=next+1;
        }
        else{
            i=start;
            continue;
        }
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
