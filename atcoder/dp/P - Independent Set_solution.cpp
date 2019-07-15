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
#define N 100005
#define endl "\n"
#define mod 1000000007
ll n; ll dp[N][3];
vector<ll> vc[N];
ll dfs(ll i,ll fl[],ll pre_cl){
	if(dp[i][pre_cl]!=-1){
		return dp[i][pre_cl]%mod;
	}
	if(pre_cl==2){
		ll j,c=1;
		for(j=0;j<vc[i].size();j++){
			if(fl[vc[i][j]]==0){
				fl[vc[i][j]]=1;
				c=(c*dfs(vc[i][j],fl,1))%mod;
				fl[vc[i][j]]=0;
			}
		}
		return dp[i][pre_cl]=c%mod;
	}
	else {
		ll j,c1=1,c2=1;
		for(j=0;j<vc[i].size();j++){
			if(fl[vc[i][j]]==0){
				fl[vc[i][j]]=1;
				c1=(c1*dfs(vc[i][j],fl,1))%mod;
				fl[vc[i][j]]=0;
			}
		}
		for(j=0;j<vc[i].size();j++){
			if(fl[vc[i][j]]==0){
				fl[vc[i][j]]=1;
				c2=(c2*dfs(vc[i][j],fl,2))%mod;
				fl[vc[i][j]]=0;
			}
		}
		return dp[i][pre_cl]=(c1%mod+c2%mod)%mod;
	}
}
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=1;i<n;i++){
		cin>>k>>l;
		vc[k].ps(l);
		vc[l].ps(k);
	}
	
	ll fl[n+1]={0}; fl[1]=1;
	ll an=dfs(1,fl,-1)%mod;
	cout<<an;
	return 0;
}
