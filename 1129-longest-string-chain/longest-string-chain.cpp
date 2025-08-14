class Solution {
public:
    int n;
    int t[1001][1001];

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

    int lis(vector<string>& words, int prev, int curr) {
        if (curr == n) return 0;
        if (prev != -1 && t[prev][curr] != -1) return t[prev][curr];

        // key fix: allow starting a new chain when prev == -1
        int taken = 0;
        if (prev == -1 || isPred(words[prev], words[curr])) {
            taken = 1 + lis(words, curr, curr + 1);
        }

        int not_taken = lis(words, prev, curr + 1);

        if (prev != -1) t[prev][curr] = max(taken, not_taken);
        return max(taken, not_taken);
    }

    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n = words.size();
        sort(words.begin(), words.end(), myFunction);
        return lis(words, -1, 0);
    }
};
