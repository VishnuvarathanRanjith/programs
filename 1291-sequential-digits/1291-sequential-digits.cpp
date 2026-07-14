class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int i=2;
        string s="123456789";
        int k=1;

        while(i<=9){
            int j=9-k;
            int id=0;
            while(j--){
                string str=s.substr(id,i);
                ans.push_back(stoi(str));
                id++;
            }
            i+=1;
            k++;
        }
        vector<int>res;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                res.push_back(ans[i]);
            }
            cout<<ans[i]<<" ";
    
        }
        return res;
    }

};