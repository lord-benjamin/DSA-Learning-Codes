#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node,vector<vector<int>> adj,int vis[],vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto val : adj[node]){
        if(!vis[val]){
            dfs(val,adj,vis,ls);
        }
    }
}

vector<int> dfsOfGraph(int V,vector<vector<int>> adj){
    int vis[V] = {0};
    vector<int> ls;
    int start = 0;
    dfs(start,adj,vis,ls);
    return ls;
}

int main()
{
    int numOfNodes = 5;
    vector<vector<int>> adj = {{1,2,4},{0},{0},{4},{0,3}};
    vector<int> dfs = dfsOfGraph(numOfNodes,adj);
    for(auto val : dfs){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}