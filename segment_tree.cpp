class SegmentTree {
private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node]= nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node]= tree[2 * node]+ tree[2 * node + 1];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node]= val;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node]= tree[2 * node]+ tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end)
            return 0;
        if (l <= start && r >= end)
            return tree[node];

        int mid = (start + end) / 2;
        int leftSum = query(2 * node, start, mid, l, r);
        int rightSum = query(2 * node + 1, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

public:
    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 1, n);
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};
