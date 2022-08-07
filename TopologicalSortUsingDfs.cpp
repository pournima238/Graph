#include<unordered_map>
#include<list>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,list<int>> &adg ,vector<bool> &visited,
 stack<int> &s, int node){
visited[node]=1;
for(auto i:adg[node]){
    if(visited[i]==0){
        dfs(adg,visited,s,i);
    }
}
    s.push(node);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adg;
    for(int i=0; i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adg[u].push_back(v);
    }
   vector<bool>visited(v,0);
    stack<int>s;
    vector<int>ans;
    for(int i=0; i<v; i++){
        if(visited[i]==0){
            dfs(adg,visited,s, i);
        }
    }
    while(!s.empty()){
        int m=s.top();
        s.pop();
        ans.push_back(m);
    }
    return ans;
}