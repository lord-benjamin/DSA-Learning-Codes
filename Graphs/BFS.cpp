#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsOfGraph(int V,vector<vector<int>> adj){
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto val : adj[node]){
            if(!vis[val]){
                vis[val] = 1;
                q.push(val);
            }
        }
    }
    return bfs;
}

int main()
{
    int numOfNodes = 5;
    vector<vector<int>> adj = {{1,2,3},{},{4},{},{}};
    vector<int> bfs = bfsOfGraph(numOfNodes,adj);
    for(auto val : bfs){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}