#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int N = 1e6;


void solve() {
	int n, q, m;
	cin >> n >> q >> m;
	int cnt[m + 1] = {0};
	vi v(N);
	rep(i, 1, n + 1)
	cin >> v[i];
	set<pair<int, int>> s;
	map<pair<int, int>, int> mp;
	int add = 0;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (v[x] > m)
			continue;
		else if (v[y] > m) {
			cnt[v[x]]++;
		}
		else
			mp[ {x, y}]++;
	}
	for (auto it : mp) {
		int x = it.ff.ff;
		int y = it.ff.ss;
		int rep = it.ss;
		cnt[v[x]] += rep;
		int z = v[x] + v[y];
		while (z <= m) {
			cnt[z] -= rep;
			z += v[x];
			if (z > m) break;
			cnt[z] += rep;
			z += v[y];
		}
	}
	int ans = 0;
	rep(i, 1, m + 1)
	cnt[i] += cnt[i - 1];

	cout << *max_element(cnt, cnt + m + 1) << "\n";


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
