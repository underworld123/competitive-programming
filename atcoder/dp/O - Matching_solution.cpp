#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define N 25
#define endl "\n"
#define mod 1000000007
ll n,ar[N][N]; ll dp[22][2097160];
ll maxval(ll i,ll mask){
	if(i==n){
		return 1;
	}
	if(dp[i][mask]!=-1){
		return dp[i][mask];
	}

	ll j,k=0;
	for(j=0;j<n;j++){
		if(ar[i][j]==1&&(mask&(1<<j))==0){
			k=k%mod+maxval(i+1,mask|(1<<j))%mod;
			k=k%mod;
		}
	}
	return dp[i][mask]=k%mod;
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>ar[i][j];
		}
	}
	l=maxval(0,0)%mod;
	cout<<l;
	return 0;
}
