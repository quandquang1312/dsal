class FenwickTree {
public:
    FenwickTree(int n) {
        this->n = n;
        ft1.assign(n, 0);
        ft2.assign(n, 0);
    }

    FenwickTree(vector<int> arr) : FenwickTree(arr.size()) {
        for (int i=0; i<arr.size(); i++)
            add(i, arr[i]);
    }

    void add(vector<int> &ft, int idx, int vl) {
        for (; idx < n; idx = idx | (idx + 1))
            ft[idx] += vl;
    }

    void range_add(int l, int r, int x) {
        add(this->ft1, l, x);
        add(this->ft1, r+1, -x);
        add(this->ft2, l, x*(l-1));
        add(this->ft2, r+1, -x*r);
    }

    int range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l-1);
    }

private:
    vector<int> ft1, ft2;
    int n;

private:
    int g(int i) { return i & (i + 1); }

    int sum(vector<int>& ft, int i) {
        int rs = 0;
        while (i >= 0) {
            rs += ft[i];
            i = g(i) - 1;
        }
        return rs;
    }

    int prefix_sum(int idx) {
        return sum(this->ft1, idx) * idx - sum(ft2, idx);
    }
};
