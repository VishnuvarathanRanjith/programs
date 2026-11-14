class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0,tl=0,tk=0;
        for(int i=0;i<gas.size();i++){
            int dif=gas[i]-cost[i];
            tl+=dif;
            tk+=dif;
            if(tk<0){
                st=i+1;
                tk=0;
            }
        }
        return (tl<0)?-1:st;
    }
};