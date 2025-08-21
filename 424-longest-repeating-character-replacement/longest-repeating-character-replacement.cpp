class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0, maxlen=0, maxf=0;
        int n= s.size();
        vector<int>freq(26,0);
        while(r< n){
            freq[s[r]-'A']++;
            maxf=max(maxf, freq[s[r]-'A']);
            if((r-l+1)-maxf >k){
                freq[s[l]-'A']--;
                l++;
            }
            maxlen= max(maxlen, r-l+1);
            r++;  
        }
        return maxlen;
    }
};