class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto in:invocations){
            adj[in[0]].push_back(in[1]);
        }
        queue<int>q;
        q.push(k);
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            if(vis[nd])continue;
            vis[nd]=1;
            for(auto ed:adj[nd]){
                q.push(ed);
            }
        }
        vector<int>ans;
        bool flag=false;
        for(auto in:invocations){
            int u=in[0];
            int v=in[1];
            if(vis[u]==0 && vis[v]==1){
                flag=true;
            }
        }
        if(flag){
            for(int i=0;i<n;i++){
                cout<<vis[i]<<" ";
                ans.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                cout<<vis[i]<<" ";
                if(vis[i]==0)ans.push_back(i);
            }
        }
        return ans;
    }
};