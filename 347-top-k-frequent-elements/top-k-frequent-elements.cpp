class Solution {
public:
static bool compare(pair<int,int>&p1, pair<int,int>&p2){
    if(p1.second == p2.second) 
    return p1.first>p2.first;
    return p1.second> p2.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n= nums.size();
       unordered_map<int, int>mp;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
       } 
       vector<pair<int, int>>freq(mp.begin(), mp.end());
       sort(freq.begin(), freq.end(), compare);
       vector<int>res;
       for(int i=0;i<k;i++){
        res.push_back(freq[i].first);
       }
       return res;
    }
};