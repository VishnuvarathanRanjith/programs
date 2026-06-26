/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let ans=new Array(2);
    ans.fill(-1);
    let mp=new Map();
    for(let i=0;i<nums.length;i++){
        let need=target-nums[i];
        if(mp.has(need)){
            ans[0]=mp.get(need);
            ans[1]=i;
            break;
        }
        mp.set(nums[i],i);
    }
    return ans;
};