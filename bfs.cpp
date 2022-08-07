#include<unordered_map>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
void buildAdg(unordered_map<int, set<int>>&adg,
              vector<pair<int, int>> &edges ){
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adg[u].insert(v);
        adg[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int>> &adg, 
         unordered_map<int,bool> &visited,vector<int> &result, int i){
    int node=i;
    queue<int>q;
    visited[node]=1;
    q.push(node);
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
       
        result.push_back(frontnode);
        for(auto j:adg[frontnode]){
            if(!visited[j]){
                q.push(j);
                visited[j]=1;
            }
           
            }
        }
    }





vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    
    //first we create adjacency list and then and then process it through queue     and visited;
    vector<int>result;
    unordered_map<int, set<int>> adg;
    unordered_map<int,bool> visited;
    
    buildAdg(adg,edges);
    //to see whether all nodes are traversed
    for( int i=0;i<vertex; i++){
        if(!visited[i]){
            bfs(adg, visited,result,i);
        }
    }
    return result;
}