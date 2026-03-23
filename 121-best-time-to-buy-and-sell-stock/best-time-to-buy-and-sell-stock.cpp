class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0], maxdiff=0;
        for(int i=1;i<prices.size();i++){
            int sell= prices[i];
            maxdiff= max(maxdiff,prices[i]-buy );
            buy= min(buy, prices[i]);
        }
        return maxdiff;
    }
};