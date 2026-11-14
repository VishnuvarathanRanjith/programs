class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum<target){
                        left++;
                    }
                    else if(sum>target){
                        right--;
                    }
                    else{
                        if(!st.count({nums[i],nums[j],nums[left],nums[right]})){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        st.insert({nums[i],nums[j],nums[left],nums[right]});
                        }
                        left++;
                        right--;
                    }
                    
                }
            }
        }
        return ans;
    }
};