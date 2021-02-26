#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> v1(n);
		vector<int> v2(m);
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			cin>>v1[i];
			sum1+=v1[i];
		}
		for(int i=0;i<m;i++){
			cin>>v2[i];
			sum2+=v2[i];
		}
		if(sum1>sum2)
			cout<<0<<"\n";
		
		else{
			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end());
			int count=0,i=0,j=m-1;
			bool ans = true;
			while(sum2>=sum1){
				if(i>=v1.size() || j<=0){
					ans=false;
					break;
				}
				sum1 = sum1+v2[j]-v1[i];
				sum2 = sum2+v1[i]-v2[j];
				i++;
				j--;
				count++;
			}
			if(ans==false)
				cout<<-1<<"\n";
			else
				cout<<count<<"\n";
		}
	}
}
