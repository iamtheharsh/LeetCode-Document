class Solution {
public:
    string minCyclicRotation(const string& s) {
        int n = s.size();
        string ss = s+s;
        
        int i=0,j=1,k=0;

        while(i<n && j<n && k<n){
            if(ss[i+k]==ss[j+k]){
                k++;
                continue;
            }
            if(ss[i+k]>ss[j+k]){
                i = i + k+1;
                if(i<=j) i = j+1;
            }
            else{
                j = j+k+1;
                if(j<=i) j = i+1;
            }
            k=0;
        }
        int start = min(i,j);
        return ss.substr(start,n);
        
    }

    int minimumGroups(vector<string>& words) {
        int n = words.size();
        set<string> st;
        for(auto& w:words){
            int m = w.size();
            string odd , even;
            for(int i=0;i<m;i++){
                if(i%2) odd += w[i];
                else even += w[i];
            }
            odd = minCyclicRotation(odd);
            even = minCyclicRotation(even);
            st.insert(odd+even);
        }
        return st.size();
    }
};