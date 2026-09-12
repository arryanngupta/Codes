class Node{
  public:
    Node* links[2];
    int cnt;
    Node(){
        links[0] = links[1] = NULL;
        cnt = 0;
    }
};

class Trie{
  public:
    Node* root;
    unordered_map<int,string> mpp;
    Trie(){
        root = new Node();
    }

    string bin(int n){
        if(mpp.count(n)) return mpp[n];
        int num = n;
        string ans = "";
        while(n){
            ans += ((n%2)+'0');
            n = n/2;
        }
        int len = ans.size();
        string zero(32-len,'0');
        reverse(ans.begin(),ans.end());
        mpp[num] = (zero+ans);
        return mpp[num];
    }

    void insert(int k){
        string s = bin(k);
        int n = s.size();
        Node* node = root;
        for(int i = 0; i<n; i++){
            if(!node->links[s[i]-'0']){
                Node* newNode = new Node();
                node->links[s[i]-'0'] = newNode;
            }
            node = node->links[s[i]-'0'];
            node->cnt++;
        }
    }

    void remove(int k){
        string s = bin(k);
        int n = s.size();
        Node* node = root;
        for(int i = 0; i<n; i++){
            Node* nxt = node->links[s[i]-'0'];
            nxt->cnt--;
            if(nxt->cnt==0){
                node->links[s[i]-'0']=NULL;
            }
            node = nxt;
        }
    }

    int find(int val){
        string s = bin(val);
        int n = s.size();
        int ans = 0;
        Node* node = root;
        for(int i = 0; i<n; i++){
            int bit = s[i]-'0';
            if(node->links[!bit]){
                ans += (1<<(32-i-1));
                node = node->links[!bit];
            }
            else node = node->links[bit];
        }
        return ans;
    }
};

class Solution {
public:

    vector<vector<int>> adjList;
    Trie t;
    unordered_map<int,vector<int>> mpp;
    vector<int> ans;

    void dfs(int node,vector<vector<int>>& queries){
        for(auto it: mpp[node]){
            int idx = it,val = queries[idx][1];
            ans[idx] = t.find(val);
        }
        for(auto it: adjList[node]){
            t.insert(it);
            dfs(it,queries);
            t.remove(it);
        }
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size(),root = -1;
        adjList.resize(n);
        for(int i = 0; i<n; i++){
            int u = parents[i],v = i;
            if(u!=-1) adjList[u].push_back(v);
            else root = i;
        }
        int q = queries.size();
        for(int i = 0; i<q; i++){
            int node = queries[i][0],val = queries[i][1];
            mpp[node].push_back(i);
        }
        ans.resize(q);
        t.insert(root);
        dfs(root,queries);
        return ans;
    }
};