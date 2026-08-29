class MajorityChecker {
    struct Node{
        pair<int,int> m1;
        pair<int,int> m2;
    };
public:
    vector<int> arr;
    vector<Node> seg;
    unordered_map<int, vector<int>> pos;
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        int n = arr.size();
        seg.resize(4*n);
        for (int i = 0; i < n; ++i) {
            pos[arr[i]].push_back(i);
        }
        build(1,0,n-1);
    }

    Node merge(Node left, Node right){
        Node res;
        if (left.m1.first == right.m1.first) {
            res.m1 = {left.m1.first, left.m1.second + right.m1.second};
        } else if (left.m1.second > right.m1.second) {
            res.m1 = {left.m1.first, left.m1.second - right.m1.second};
        } else {
            res.m1 = {right.m1.first, right.m1.second - left.m1.second};
        }
        return res;
    }

    void build(int node,int l,int r){
        if(l==r){
            seg[node].m1 = {arr[l],1};
            return;
        }
        int mid = (l+r)/2;
        int left = 2*node;
        int right = 2*node+1;
        build(left, l, mid);
        build(right, mid + 1, r);

        seg[node] = merge(seg[left],seg[right]);
    }

    Node query(int node,int l,int r,int ql,int qr){
        if(ql>r || l>qr) return {{-1, 0}, {-1, 0}};
        if(l>=ql && qr>=r) return seg[node];
        int mid = (l + r) / 2;
        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);
        if (left.m1.first == -1) return right;
        if (right.m1.first == -1) return left;
        return merge(left, right);
    }

    
    int query(int l, int r, int th) {
        Node ans = query(1,0,arr.size()-1,l,r);
        int temp = ans.m1.first;
        if(temp!=(-1)){
            auto& v = pos[temp];
            auto it_start = lower_bound(v.begin(), v.end(), l);
            auto it_end = upper_bound(v.begin(), v.end(), r);
            int dist = distance(it_start,it_end);
            if(dist>= th) return temp;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */