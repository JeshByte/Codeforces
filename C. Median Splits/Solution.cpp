#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll comp(ll a, ll b){
	if(a==b){
		return 0;
	}
	if(a>b){
		return 1;
	}
	if(a<b){
		return -1;
	}
    return -1;
}
void add(ll ele, ll& median, multiset<ll>& left, multiset<ll>& right){
	switch(comp(left.size(),right.size())){
		case 0:
		     if(ele>=median){
				 right.insert(ele);
				 median=*right.begin();
			 }
			 else{
				 left.insert(ele);
				 median=*left.rbegin();
			 }
			 break;
		case 1:
		     if(ele>=median){
				 right.insert(ele);
				 median=*left.rbegin();
			 }
			 else{
				 right.insert(*left.rbegin());
				 left.erase(prev(left.end()));
				 left.insert(ele);
				 median=*left.rbegin();
			 }
			 break;
	    case -1:
		      if(ele>=median){
				  left.insert(*right.begin());
				  right.erase(right.begin());
				  right.insert(ele);
				  median=*left.rbegin();
			  }
			  else{
				  left.insert(ele);
				  median=*left.rbegin();
			  }
			  break;
		default:
		      break;
	}
}
bool one(vector<ll>& arr,ll k,ll n){
    ll median=-1;
    multiset<ll> left,right;
    ll cnt=0;
    ll s=n-1;
    for(int i=n-1;i>=0;i--){
        add(arr[i],median,left,right);
        if(median<=k){
            if((s-i+1)&1){
                if(i-1>=0 && arr[i-1]>=median && arr[i-1]>k){
                    continue;
                }
            }
            s=i-1;
            cnt++;
            //cout<<"one "<<median<<'\n';
            if(cnt==2){
                return true;
            }
            median=-1;
            left.clear();
            right.clear();
        }
    }
    return false;
}
bool two(vector<ll>& arr,ll k,ll n){
    ll median=-1;
    multiset<ll> left,right;
    ll cnt=0;
    ll e=-1;
    for(int i=n-1;i>=0;i--){
        add(arr[i],median,left,right);
        if(median<=k){
            //cout<<"two "<<median<<'\n';
            cnt++;
            if(cnt==1){
                e=i;
                break;
            }
        }
    }
    if(e==-1){
        return false;
    }
    median=-1;
    left.clear();
    right.clear();
    ll s=-1;
    for(int i=0;i<n;i++){
        add(arr[i],median,left,right);
        if(median<=k){
            //cout<<"two "<<median<<'\n';
            cnt++;
            if(cnt==2){
                s=i;
                break;
            }
        }
    }
    if(cnt==2 && s!=-1 && e!=-1 && e-s>=2){
        return true;
    }
    return false;
}
bool three(vector<ll>& arr,ll k,ll n){
    ll median=-1;
    multiset<ll> left,right;
    ll cnt=0;
    ll s=0;
    for(int i=0;i<n;i++){
        add(arr[i],median,left,right);
        if(median<=k){
            //cout<<"three "<<median<<'\n';
            if((i-s+1)&1){
                if(i+1<n && arr[i+1]>=median && arr[i+1]>k){
                    continue;
                }
            }
            s=i+1;
            cnt++;
            if(cnt==2){
                return true;
            }
            median=-1;
            left.clear();
            right.clear();
        }
    }
    return false;
}
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    if(one(arr,k,n) || two(arr,k,n) || three(arr,k,n)){
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
