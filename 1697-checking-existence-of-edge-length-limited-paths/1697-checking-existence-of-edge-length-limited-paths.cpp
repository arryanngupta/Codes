class DisjointSets{
    vector<int> parent,rank;
    public:
        DisjointSets(int n){
            rank.resize(n+1,0); 
            parent.resize(n+1);
            for(int i = 0; i<n; i++){
                parent[i] = i;
            }
        }
        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }

        void findUnionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};


class Solution {
public:

    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[2]<=b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(),edgeList.end(),comp);
        int q = queries.size();
        vector<vector<int>> quer(q);
        for(int i = 0; i<q; i++){
            quer[i] = queries[i];
            quer[i].push_back(i);
        }
        sort(quer.begin(),quer.end(),comp);
        vector<bool> ans(q);
        DisjointSets ds(n);
        int i = 0,m = edgeList.size();
        for(auto it: quer){
            int u = it[0],v = it[1],l = it[2],idx = it[3];
            while(i<m && edgeList[i][2]<l){
                ds.findUnionByRank(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            if(ds.findUPar(u)==ds.findUPar(v)) ans[idx] = true;
            else ans[idx] = false;
        }
        return ans;
    }
};