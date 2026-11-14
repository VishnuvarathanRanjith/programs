class Solution {
public:
    int recur(vector<int>&nums,int i,vector<int>& dp){
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int mini=1e9;
        for(int j=nums[i];j>=1;j--){
            mini=min(mini,recur(nums,i+j,dp)+1);
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return recur(nums,0,dp);
    }
};