#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int i=0;
		
		string ans="";
		while(i+4<=n){
			string str = "abcdefghijklmnop";
			for(int j=i;j<i+4;j++){
				if(s[j]=='0')
					str = str.substr(0,str.size()/2);
				else
					str=str.substr(str.size()/2,str.size()-1);
			}
			i+=4;
			ans=ans+str;
		}
		cout<<ans<<"\n";
	}
}
