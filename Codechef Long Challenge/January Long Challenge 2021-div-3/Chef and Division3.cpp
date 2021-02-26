#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,d;
		cin>>n>>k>>d;
		int sum=0,input;
		for(int i=0;i<n;i++){
			cin>>input;
			sum +=input;
		}

		int c = sum/k;
		if(c>d)
			cout<<d<<"\n";
		else
			cout<<c<<"\n";
	}
}
