#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool helper(vector<int> v,int k){
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
	}
	int n=v.size();
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	for(int i=1;i<=sum;i++)
		dp[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<v[i-1])
				dp[i][j]=dp[i-1][j];
			if(j>=v[i-1])
				dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
		}
	}
	int minSum=0;
	for(int i=sum/2;i>=0;i--){
		if(dp[n][i]==true){
			minSum=i;
			break;
		}
	}
	if(minSum>=k/2 && sum-minSum>=k/2)
		return true;
	return false;
	
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,sum=0;
		cin>>n>>k;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			sum+=v[i];
		}
		if(sum<2*k)
			cout<<-1<<"\n";
		else{
			sort(v.begin(),v.end(),greater<int>());
			if(v[0]>=k){
				sum=0;
				int cnt=0;
				bool found = false;
				for(int i=1;i<v.size();i++){
					sum+=v[i];
					cnt++;
					if(sum>=k){
						found=true;
						break;
					}
				}
				if(found){
					cout<<cnt+1<<"\n";
				}
				else
					cout<<-1<<"\n";
			}
			else{
				vector<int> v1;
				sum=0;
				for(int i=0;i<v.size();i++){
					v1.push_back(v[i]);
					sum+=v[i];
					if(sum>=2*k)
						break;
				}
				v.erase(v.begin(),v.begin()+v1.size());
				bool ans = helper(v1,k*2);
				while(!ans && !v.empty()){
					v1.push_back(v[0]);
					v.erase(v.begin());

					ans = helper(v1,2*k);
				}
				if(ans)
					cout<<v1.size()<<"\n";
				else
					cout<<-1<<"\n";
			}
		}
		
	}
}
