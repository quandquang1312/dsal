#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD (ll)1e9+7
#define MAXN 200100

#define FOR(i,a,b) for (int i=a; i<b; i++) 
#define LOG(x) cout << x << "\n";

int t, n, k;
ll arr[MAXN];
vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(3,0)));

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    
    t = 1;
    while (t--)
        solve();
    return 0;
}
