class Solution {
public:
    
    vector<long long> seg;

    long long LCM(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }

    void build(int i, int l, int r, vector<int>& a) {
        if(l == r) {
            seg[i] = a[l];
            return;
        }

        int m = (l + r) / 2;

        build(2*i+1, l, m, a);
        build(2*i+2, m+1, r, a);

        seg[i] = LCM(seg[2*i+1], seg[2*i+2]);
    }

    void update(int i, int l, int r, int idx, int val) {
        if(l == r) {
            seg[i] = val;
            return;
        }

        int m = (l + r) / 2;

        if(idx <= m)
            update(2*i+1, l, m, idx, val);
        else
            update(2*i+2, m+1, r, idx, val);

        seg[i] = LCM(seg[2*i+1], seg[2*i+2]);
    }

    long long query(int i, int l, int r, int ql, int qr) {

        if(qr < l || ql > r) return 1;

        if(ql <= l && r <= qr) return seg[i];

        int m = (l + r) / 2;

        return LCM(
            query(2*i+1, l, m, ql, qr),
            query(2*i+2, m+1, r, ql, qr)
        );
    }

    vector<long long> RangeLCMQuery(vector<int>& arr, vector<vector<int>>& queries) {

        int n = arr.size();

        seg.resize(4*n);

        build(0, 0, n-1, arr);

        vector<long long> ans;

        for(auto &q : queries) {

            if(q[0] == 1)
                update(0, 0, n-1, q[1], q[2]);

            else
                ans.push_back(query(0, 0, n-1, q[1], q[2]));
        }

        return ans;
    }
};