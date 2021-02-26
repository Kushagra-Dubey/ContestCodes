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
const int N = 30;

int dp[1001] = {0};
vi bits_count(N);
int l[1001][1001];

#define NCR
void init()
{
	// 0C0 = 1
	l[0][0] = 1;
	for (int i = 1; i < 1001; i++) {
		// Set every nCr = 1 where r = 0
		l[i][0] = 1;
		for (int j = 1; j < i + 1; j++) {

			// Value for the current cell of Pascal's triangle
			l[i][j] = ((l[i - 1][j - 1]) % MM + (l[i - 1][j]) % MM );
			l[i][j] %= MM;
		}
	}
}

// Function to return the value of nCr
int nCr(int n, int r)
{
	// Return nCr
	return l[n][r] % MM ;
}

int helper(vi v, int k, int n) {
	if (dp[k] != 0)
		return dp[k];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 1; j <= k; j += 2) {
			// cout << nCr(v[i], j) << " " << nCr(n - v[i], k - j) << "\n";
			cnt += ((nCr(v[i], j) % MM ) * (nCr(n - v[i], k - j) % MM)) % MM ;
			cnt %= MM;
		}
		sum = sum + ((cnt) * (int)pow(2, i) % MM) % MM  ;
		sum %= MM;

	}
	dp[k] = sum % MM;
	return sum % MM ;
}
void solve() {
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 30; j++) {
			if (v[i] & (1 << j))
				bits_count[j]++;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		int sum = 0;
		for (int i = k; i >= 1; i--)
			sum += helper(bits_count, i, n);
		cout << sum % MM << "\n";
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
