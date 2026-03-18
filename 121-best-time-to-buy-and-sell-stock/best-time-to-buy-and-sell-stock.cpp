class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0], maxProfit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            int sell = prices[i];
            maxProfit= max(maxProfit, sell-buy );
            buy= min(buy, prices[i]);
        }
        return maxProfit;
    }
};