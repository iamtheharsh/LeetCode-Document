class SegmentTree{
    struct Node{
        int peaks;
        int le,re;
    };

    vector<Node> seg;
    vector<int> arr;
    public:
    SegmentTree(vector<int>& nums) {
        arr = nums;
        int n = arr.size();
        seg.resize(4 * n);
        build(1,0,n-1);
    }
    bool isPeak(int idx) {
        int n = arr.size();
        if (idx <= 0 || idx >= n - 1)
            return false;

        return arr[idx] > arr[idx - 1] && arr[idx] > arr[idx + 1];
    }


    void build(int node,int l,int r){
        if(l==r){
            Node temp;
            temp.peaks = isPeak(l)? 1:0;
            temp.le = arr[l];
            temp.re = arr[l];
            seg[node] = temp;
            return;
        }
        int mid = (l+r)/2;
        int left = 2*node;
        int right = 2*node + 1;
        build(left,l,mid);
        build(right,mid+1,r);

        Node temp;
        temp.peaks = seg[left].peaks + seg[right].peaks;
        temp.le = seg[left].le;
        temp.re = seg[left].re;
        seg[node] = temp;
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr<l || r<ql) return 0;
        if(ql<=l && r<=qr) return seg[node].peaks;
        int mid = (l+r)/2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
    int query(int l, int r) {
        if (l > r)
            return 0;

        return query(1, 0, arr.size() - 1, l, r);
    }


    void updatePeak(int node,int l,int r,int idx){
        if (l == r) {
            seg[node].peaks = isPeak(idx) ? 1 : 0;
            seg[node].le = arr[idx];
            seg[node].re = arr[idx];
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            updatePeak(2*node,l,mid,idx);
        }
        else updatePeak(2*node+1,mid+1,r,idx);
        seg[node].peaks = seg[2 * node].peaks + seg[2 * node + 1].peaks;
        seg[node].le = seg[2 * node].le;
        seg[node].re = seg[2 * node + 1].re;
    }

    void update(int idx,int val){
        arr[idx] = val;
        int n = arr.size();
        for(int i=max(0,idx-1);i<=min(n-1,idx+1);i++){
            updatePeak(1,0,n-1,i);
        }
    }
};
class Solution {
public:

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree st(nums);
        vector<int> ans;
        for(auto q:queries){
            if(q[0]==1){
                int l = q[1];
                int r = q[2];
                ans.push_back(st.query(l+1,r-1));
            }
            else {
                int idx = q[1];
                int val = q[2];
                st.update(idx,val);
            }
        }
        return ans;
    }
};