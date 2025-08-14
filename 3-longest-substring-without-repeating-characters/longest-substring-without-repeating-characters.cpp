class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int start = 0, end = 0, maxLen = 0;

        while (end < s.length()) {
            if (st.find(s[end]) == st.end()) {
                // Character not in set, add it
                st.insert(s[end]);
                maxLen = max(maxLen, end - start + 1);
                end++;
            } else {
                // Character already in set, remove from left
                st.erase(s[start]);
                start++;
            }
        }

        return maxLen;
    }
};
