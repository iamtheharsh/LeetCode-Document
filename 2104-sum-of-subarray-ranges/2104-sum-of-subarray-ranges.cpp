class Solution {
public:
    using ll = long long;

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n, -1), nse(n, n);
        vector<int> pge(n, -1), nge(n, n);

        stack<int> st;
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                pge[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty())
                nge[i] = st.top();
            st.push(i);
        }

        ll mx = 0, mn = 0;
        for(int i=0;i<n;i++){
            ll left = i-pse[i];
            ll right = nse[i] - i;
            mn += nums[i]*left*right;

            left = i-pge[i];
            right = nge[i] - i;
            mx += nums[i]*left*right;
        }
        return mx-mn;

    }
};