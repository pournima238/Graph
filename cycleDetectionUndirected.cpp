#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
#include<list>
#include<queue>
bool isBfs(unordered_map<int,bool>&visited,
           unordered_map<int, list<int>>&adg, int node){
    unordered_map<int,int>parent;
    parent[node]=-1;
    visited[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int frontN=q.front();
        q.pop();
        for(auto i:adg[frontN]){
            if( visited[i]==true && i!=parent[frontN]){
                return true;
            }else if(!visited[i]){
                q.push(i);
                visited[i]=1;
                parent[i]=frontN;
            }
        }
        return false;
    }
}

bool isDfs(int parent ,unordered_map<int,bool>&visited,
           unordered_map<int, list<int>>&adg, int node){
    visited[node]=1;
    for(auto i:adg[node]){
        if(visited[i]==true && i!=parent){
            return true;
        }else if(!visited[i]){
            isDfs(node,visited, adg,i);
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //creating adjacent list
    unordered_map<int, list<int>>adg;
    for(int i=0; i<m; i++){
        int u=edges[i][0];
        int v=edges[i][1];
         adg[u].push_back(v);
        adg[v].push_back(u);
        
    }
    unordered_map<int,bool>visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans= isDfs(-1,visited, adg, i);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}
