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

int cnt = 0;
bool visited[101];
vector<int> adj[101];

void helper(int v, int w) {

	if (visited[v]) return;

	visited[v] = true;
	int y = adj[v].size();
	if (y == 0)
		return;
	if (w % y != 0) {
		cnt += w;
		return;
	}
	if (adj[v].size() == 0)
		return;
	tr(adj[v], u) {
		helper(u, w / y);
	}
}

void solve() {
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int x;
		cin >> x;
		adj[x].pb(i + 2);
	}
	int q;
	cin >> q;
	while (q--) {
		int v, w;
		cin >> v >> w;
		cnt = 0;
		memset(visited, false, sizeof(visited));
		helper(v, w);
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
	solve();
	return 0;
}
