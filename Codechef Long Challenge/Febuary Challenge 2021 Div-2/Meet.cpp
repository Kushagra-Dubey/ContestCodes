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
const int N = 0;

int helper(set<char> &coll1, set<char> &coll2) {
	vector<char> coll3(min(coll1.size(), coll2.size()));
	auto itlast = set_intersection(all(coll1), all(coll2), coll3.begin());
	return itlast - coll3.begin();
}
void solve() {
	int n;
	cin >> n;
	string arr[n];
	fo(i, n)
	cin >> arr[i];
	map<string , set<char>> mp;
	for (auto it : arr) {
		mp[it.substr(1)].insert(it[0]);
	}
	int ans = 0;
	for (auto it : mp) {
		for (auto ik : mp) {
			if (it != ik) {
				int common = helper(it.ss, ik.ss);
				ans += (it.ss.size() - common) * (ik.ss.size() - common);
			}
		}
	}
	cout << ans << "\n";
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
