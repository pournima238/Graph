#include<unordered_map>
#include<list>
#include<bits/stdc++.h>
using namespace std;
#include<queue>

void bfs(vector<bool>&visited,unordered_map<int,list<int>>&adg,
        vector<int>&indegree, vector<int>&ans,int node, int v){
    visited[node]=1;
    queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(node);
        }
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adg[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
     unordered_map<int,list<int>>adg;
    for(int i=0; i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adg[u].push_back(v);
    }
    vector<int>indegree(v,0);
    for(auto i:adg){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    vector<bool>visited(v,0);
    vector<int>ans;
    for(int i=0; i<v; i++){
        if(visited[i]==0){
            bfs(visited, adg, indegree,ans,i,v);
        }
    }
    return ans;
}