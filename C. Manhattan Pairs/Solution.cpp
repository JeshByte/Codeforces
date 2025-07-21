#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Ceil(a,b) ((a+b-1)/b)
ll calc(pair<ll,ll>a,pair<ll,ll>b){
    ll t1=abs(a.first-b.first);
    ll t2=abs(a.second-b.second);
    return t1+t2;
}
void solve(ll t) {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> x(n),y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first;
        x[i].second=y[i].second=i;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<ll> nx(n),ny(n);
    for(int i=0;i<n;i++){
        nx[x[i].second]=i;
        ny[y[i].second]=i;
    }
    vector<ll>q1,q2,q3,q4;
    for(int i=0;i<n;i++){
        if(nx[i]>=n/2 && ny[i]>=n/2){
            q1.push_back(i);
        }
        else if(nx[i]<n/2 && ny[i]>=n/2){
            q2.push_back(i);
        }
        else if(nx[i]<n/2 && ny[i]<n/2){
            q3.push_back(i);
        }
        else{
            q4.push_back(i);
        }
    }
    vector<pair<ll,ll>> ans;
    for(int i=0;i<q1.size();i++){
        ans.push_back(make_pair(q1[i]+1,q3[i]+1));
        //ans.push_back(make_pair(q2[i]+1,q4[i]+1));
    }
    for(int i=0;i<q2.size();i++){
        //ans.push_back(make_pair(q1[i]+1,q3[i]+1));
        ans.push_back(make_pair(q2[i]+1,q4[i]+1));
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
