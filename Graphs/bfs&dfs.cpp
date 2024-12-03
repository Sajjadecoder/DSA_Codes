#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int> BFSTraversal(int vertices,vector<int> adjList[]){
    queue<int> q;
    vector<int> visited(vertices,0);
    q.push(0);
    visited[0] = 1;
    vector<int> ans;
    while (!q.empty()) 
    {
        int val = q.front();
        ans.push_back(val);
        q.pop();
        for (int i = 0; i < adjList[val].size(); i++)
        {
            int num =adjList[val][i]; 
            if (visited[num]==0)
            {
                visited[num] = 1;
                q.push(num);
            }
            
        }
        
    }
    return ans;
    
}
void DFSTraversal(int vertice,vector<int> &visited,vector<int> adjList[],vector<int>&ans){
    visited[vertice] = 1;
    ans.push_back(vertice);
    for (int i = 0; i < adjList[vertice].size(); i++)
    {
        int nextVertice = adjList[vertice][i];
        if (visited[nextVertice]==0)
        {
            DFSTraversal(nextVertice,visited,adjList,ans);
        }
        
    }
    
}
int main(){

    return 0;
}