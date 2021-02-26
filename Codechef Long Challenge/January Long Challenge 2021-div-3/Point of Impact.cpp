#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,x,y;
		cin>>n>>k>>x>>y;

		if(x==y)
			cout<<n<<" "<<n<<"\n";
		else{
			k=k%4;

			if(x>y){
				if(k==1)
					cout<<n<<" "<<n-(x-y)<<"\n";
				if(k==2)
					cout<<n-(x-y)<<" "<<n<<"\n";
				if(k==3)
					cout<<0<<" "<<x-y<<"\n";
				if(k==0)
					cout<<x-y<<" "<<0<<"\n";
			}
			if(y>x){
				if(k==1)
					cout<<n-(y-x)<<" "<<n<<"\n";
 	 			if(k==2)
 	 				cout<<n<<" "<<n-(y-x)<<"\n";
 	 			if(k==3)
 	 				cout<<y-x<<" "<<0<<"\n";
 	 			if(k==0)
 	 				cout<<0<<" "<<y-x<<"\n";
			}
		}
	}
}
