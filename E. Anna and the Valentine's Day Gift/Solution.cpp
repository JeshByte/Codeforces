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
ll findTrailingZeroes(ll n){
    ll cnt=0;
    while(n){
        ll d=n%10;
        n=n/10;
        if(d==0){
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}
ll findDigitsBefore(ll n){
    ll cnt=0;
    ll total=0;
    bool flag=true;
    while(n){
        ll d=n%10;
        n=n/10;
        total++;
        if(d==0 && flag){
            cnt++;
        }
        else{
            flag=false;
        }
    }
    return (total-cnt);
}
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    multiset<pair<ll,ll>> tz,db;
    for(int i=0;i<n;i++){
        ll trailingZeroes=findTrailingZeroes(arr[i]);
        ll digitsBefore=findDigitsBefore(arr[i]);
        tz.insert({trailingZeroes,digitsBefore});
        db.insert({digitsBefore,trailingZeroes});
    }
    bool turn=true;
    while(tz.size()>=1){
        if(turn){
            auto it1=tz.end();
            it1--;
            pair<ll,ll> val1=*it1;
            tz.erase(it1);
            auto it2=db.find({val1.second,val1.first});
            if(it2!=db.end()){
                db.erase(it2);
            }
            tz.insert({0,val1.second});
            db.insert({val1.second,0});
        }
        else{
            if(tz.size()<2){
                break;
            }
            auto it1=tz.end();
            it1--;
            pair<ll,ll> val1=(*it1);
            tz.erase(it1);
            auto it2=db.find({val1.second,val1.first});
            if(it2!=db.end()){
                db.erase(it2);
            }
            auto it3=db.end();
            it3--;
            pair<ll,ll> val2=(*it3);
            db.erase(it3);
            auto it4=tz.find({val2.second,val2.first});
            if(it4!=tz.end()){
                tz.erase(it4);
            }
            tz.insert({val2.second,val1.first+val1.second+val2.first});
            db.insert({val1.first+val1.second+val2.first,val2.second});
        }
        turn=!turn;
    }
    auto it=tz.begin();
    pair<ll,ll> val=*it;
    ll ans=val.first+val.second;
    if(ans>=(m+1)){
        cout<<"Sasha\n";
    }
    else{
        cout<<"Anna\n";
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
