#include <bits/stdc++.h>
using namespace std;

#define int long long

class FenwickTree {
private:
    std::vector<long long> BIT1, BIT2;

    void update(std::vector<long long> &BIT, int index, long long value) {
        while (index < BIT.size()) {
            BIT[index] += value;
            index += index & (-index);
        }
    }

    long long query(const std::vector<long long> &BIT, int index) {
        long long sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }

public:
    FenwickTree(int size) : BIT1(size + 1, 0), BIT2(size + 1, 0) {}

    void rangeUpdate(int left, int right, long long value) {
        update(BIT1, left, value);
        update(BIT1, right + 1, -value);
        update(BIT2, left, value * (left - 1));
        update(BIT2, right + 1, -value * right);
    }

    long long prefixSum(int index) {
        return query(BIT1, index) * index - query(BIT2, index);
    }

    long long rangeQuery(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.in", "r", stdin);

    int n; cin >> n;

    vector<FenwickTree> fts(101, FenwickTree(n));
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        fts[x].rangeUpdate(i,i,1);
    }

    int q; cin >> q;
    while (q--) {
        int l, r, vl;
        cin >> l >> r >> vl;
        l++; r++;
        int ans = fts[vl].rangeQuery(l, r);

        cout << ans << endl;
    }

    return 0;
}
