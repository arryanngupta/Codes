class LockingTree {
public:
    unordered_map<int,int> mpp;
    vector<int> par;
    vector<vector<int>> adjList;
    vector<int> visited;
    int len;
    LockingTree(vector<int>& parent) {
        par = parent;
        int n = parent.size();
        len = n;
        adjList.resize(n);
        for(int i = 0; i<n; i++){
            int u = i,v = parent[i];
            if(v==-1) continue;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    
    bool lock(int num, int user) {
        if(mpp.count(num)) return false;
        mpp[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(mpp.count(num) && mpp[num]==user){
            mpp.erase(num);
            return true;
        }
        return false;
    }

    bool checkAncestors(int num){
        int node = num;
        while(node!=-1){
            if(mpp.count(node)) return false;
            node = par[node];
        }
        return true;
    }

    void dfs(int num,int &flag){
        visited[num] = 1;
        for(auto it: adjList[num]){
            if(!visited[it] && it!=par[num]){
                if(mpp.count(it)){
                    flag = 1;
                    unlock(it,mpp[it]);
                }
                dfs(it,flag);
            }
        }
    }
    
    bool upgrade(int num, int user) {
        if(mpp.count(num)) return false;
        if(!checkAncestors(num)) return false;
        visited.assign(len,0);
        int flag = 0;
        dfs(num,flag);
        if(!flag) return false;
        lock(num,user);
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */