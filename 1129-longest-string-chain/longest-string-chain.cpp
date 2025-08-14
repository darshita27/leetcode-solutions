class Solution {
public:
int n;
bool isPred(const string &prev, const string &curr) {
        int m = prev.size(), k = curr.size();
        if (m >= k || k - m != 1) return false;
        int i = 0, j = 0;
        while (i < m && j < k) {
            if (prev[i] == curr[j]) i++;
            j++;
        }
        return i == m;
    }

    static bool myFunction(const string &a, const string &b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        n= words.size();
        sort(begin(words), end(words), myFunction);
        vector<int> t(n,1);
        int maxL=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isPred(words[j], words[i])){
                    t[i]= max(t[i], t[j]+1);
                    maxL= max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }
};