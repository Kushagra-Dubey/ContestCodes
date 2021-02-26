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


const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

bool comp(pii p1, pii p2) {
	if (p1.ff < p2.ff)
		return 1;
	return 0;
}
void solve() {
	int n;
	cin >> n;
	vi w(n), l(n);
	fo(i, n)
	cin >> w[i];
	fo(i, n)
	cin >> l[i];

	if (n == 2) {
		if (w[0] > w[1]) {
			if (l[0] == 1)
				cout << "2\n";
			else
				cout << "1\n";
		}
		else
			cout << "0\n";
	}
	else {
		mii mp;
		fo(i, n)
		mp.insert({w[i], l[i]});
		vector<pii> v(n);
		fo(i, n) {
			v[i].ff = w[i];
			v[i].ss = i;
		}
		sort(v.begin(), v.end(), comp);
		bool sorted = 1;
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (v[i].ss >= v[i + 1].ss) {
				while (v[i].ss >= v[i + 1].ss) {
					cnt++;
					v[i + 1].ss += mp[v[i + 1].ff];
				}
			}
		}
		cout << cnt << "\n";
	}

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
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
