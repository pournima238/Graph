#include<bits/stdc++.h>
#include<stack>
using namespace std;
class graph{
public:
unordered_map<int,list<pair<int,int>>> adg;
void addEdge(int u, int v, int weight){
    pair<int,int>p=make_pair(v,weight);
    adg[u].push_back(p);

}
void dfs(stack<int> &s,unordered_map<int,bool>&visited, int node){
 visited[node]=1;
 for(auto i:adg[node]){
    dfs(s,visited,i.first);
 }
 s.push(node);
}

void shortestPath(stack<int>&s, vector<int>&dist){
   while(!s.empty()){
   int top=s.top();
   s.pop();
   if(dist[top]!=INT_MAX){
    for(auto i:adg[top]){
        if((dist[top]+i.second)<dist[i.first]){
             dist[i.first]=dist[top]+i.second;
        }
    }
   }
   }



}
void print(){
  for(auto i:adg){
    cout<<i.first<<"->";
    for (auto j:i.second){
        cout<<"("<<j.first<<","<<j.second<<")";
    }
    cout<<endl;
    
  }
}

};

int main(){
    stack<int> s;
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
   unordered_map<int,bool>visited;
   for(int i=0; i<6;i++){
    if(!visited[i]){
        g.dfs(s,visited,i);
    }
   }
   vector<int>dist(6);
   for (int i = 0; i < 6; i++)
   {
    dist[i]=INT_MAX;
   }
   dist[1]=0;
   g.shortestPath(s,dist);
   for (int i = 0; i < 6; i++)
   {
    cout<<dist[i]<<" ";

   }
   
   
    g.print();

}