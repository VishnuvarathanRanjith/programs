class Solution {
public:
    vector<int>mxt;
    vector<int>mnt;
    void buildmx(long long i,int l,int h,vector<int>& nums){
        if(l==h){
            mxt[i]=nums[l];
            return;
        }
        int mid=(l+h)/2;
        buildmx(i*2+1,l,mid,nums);
        buildmx(i*2+2,mid+1,h,nums);
        mxt[i]=max(mxt[i*2+1],mxt[i*2+2]);
    }
    void buildmn(long long i,int l,int h,vector<int>& nums){
         if(l==h){
            mnt[i]=nums[l];
            return;
        }
        int mid=(l+h)/2;
        buildmn(i*2+1,l,mid,nums);
        buildmn(i*2+2,mid+1,h,nums);
        mnt[i]=min(mnt[i*2+1],mnt[i*2+2]);
    }
    int qmx(long long i,int low,int high,int l,int r){
        if(low>r || high<l)return INT_MIN;
        if(l<=low && high<=r)return mxt[i];
        int mid=(low+high)/2;
        int left=qmx(i*2+1,low,mid,l,r);
        int right=qmx(i*2+2,mid+1,high,l,r);
        return max(left,right);

    }
     int qmn(long long i,int low,int high,int l,int r){
        if(low>r || high<l)return INT_MAX;
        if(l<=low && high<=r)return mnt[i];
        int mid=(low+high)/2;
        int left=qmn(i*2+1,low,mid,l,r);
        int right=qmn(i*2+2,mid+1,high,l,r);
        return min(left,right);
        
    }
    int firstStableIndex(vector<int>& nums, int k) {
        mxt.resize(4*nums.size());
        mnt.resize(4*nums.size());
        buildmx(0,0,nums.size()-1,nums);
        buildmn(0,0,nums.size()-1,nums);
        for(int i=0;i<nums.size();i++){
            int a=qmx(0,0,nums.size()-1,0,i);
            int b=qmn(0,0,nums.size()-1,i,nums.size()-1);
            if((a-b)<=k)return i;
        }
        return -1;
    }
};