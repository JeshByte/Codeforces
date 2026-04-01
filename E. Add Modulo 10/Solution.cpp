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
void toBinary(ll n,vector<ll>& bin){
    while(n){
        bin.push_back(n%2);
        n=n/2;
    }
    //reverse(bin.begin(),bin.end());
}
bool check(ll mid,vector<ll>&binm,vector<ll>&bins,ll ind,ll carry){
    ll pc=carry-mid;
    ll b=mid;
    for(int i=ind-1;i>=0;i--){
        ll total;
        if(bins[i]==0){
            total=pc*2;
        }
        else{
            total=pc*2+1;
        }
        if(binm[i]==0){
            pc=total;
            continue;
        }
        if(total<mid){
            return true;
        }
        else{
            pc=total-mid;
        }
    }
    if(pc==0){
        return true;
    }
    return false;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll digit=arr[i]%10;
        if(digit&1){
            arr[i]+=digit;
        }
    }
    set<ll> st;
    ll cnt=0;
    for(int i=0;i<n;i++){
        ll digit=arr[i]%10;
        if(digit==0){
            cnt++;
            st.insert(arr[i]);
        }
    }
    if(cnt>0){
        //cout<<"hi\n";
        if(st.size()==1 && cnt==n){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
        return;
    }
    ll to,te,so,se;
    to=te=so=se=0;
    for(int i=0;i<n;i++){
        ll ldigit=arr[i]%10;
        ll tp=arr[i];
        tp=tp/10;
        ll sdigit=tp%10;
        if(ldigit==6){
            if(sdigit&1){
                so++;
            }
            else{
                se++;
            }
        }
        else{
            if(sdigit&1){
                to++;
            }
            else{
                te++;
            }
        }
    }
    if(to>0 && te>0){
        cout<<"No\n";
        return;
    }
    if(so>0 && se>0){
        cout<<"No\n";
        return;
    }
    if(to>0 && so>0){
        cout<<"No\n";
        return;
    }
    if(te>0 && se>0){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
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
