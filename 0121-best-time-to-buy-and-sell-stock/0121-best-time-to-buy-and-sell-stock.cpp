class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro=0;
        int buy=prices[0];
        for(int i=0;i<prices.size();i++){
            buy=min(prices[i],buy);
            pro=max(pro,prices[i]-buy);
        }
        return pro;
    }
};