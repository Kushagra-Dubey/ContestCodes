#include<bits/stdc++.h>
using namespace std;

#define forever         while(true)
#define int 			long long
#define rep(i, s, n)    for(int i=s;i<n;i++)
#define fo(i, n)        rep(i, 0, n)
#define tr(c, it)       for(auto it : c)
#define all(c)          (c).begin(), (c).end()
#define sz(x)           (int)(x.size())
#define ff              first
#define ss              second
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define st  			set<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define w(x)            int x; cin>>x; while(x--)

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 1000000;


// this code snipet is taken from gfg, the link is mentioned above;
#define SIEVE
int cnt = 0;
vector<int> pr{0, 0};
void sieve() {
	bool prime[N + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= N; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= N; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= N; p++) {
		if (prime[p])
			cnt++;
		pr.pb(cnt);
	}
}


void solve() {
	int x, y;
	cin >> x >> y;
	if (pr[x] > y)
		cout << "Divyam\n";
	else
		cout << "Chef\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef SIEVE
	sieve();
#endif
#ifdef NCR
	init();
#endif
	w(t) solve();
	return 0;
}
