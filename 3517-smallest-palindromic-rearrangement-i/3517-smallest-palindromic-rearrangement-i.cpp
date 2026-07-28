class Solution {
public:
    string smallestPalindrome(string s) {
       unordered_map<char,int>mp;
       for(char c:s){
        mp[c]++;
       }
        int n=s.size();
       string ans=s;
       int i=0;
       for(char c='a';c<='z';c++){
        if(mp[c]>0){
            if(mp[c]%2==0){
                int j=mp[c]/2;
                while(j--){
                    ans[i]=c;
                    ans[n-i-1]=c;
                    i++;
                }
            }
            else{
                int j=mp[c];
                int low=i;
                int high=n-i-1;
                int mid=(low+high)/2;
                ans[mid]=c;
                j=(j-1)/2;
                while(j--){
                    ans[i]=c;
                    ans[n-i-1]=c;
                    i++;
                }
            }
        }
       }
       return ans; 
    }
};