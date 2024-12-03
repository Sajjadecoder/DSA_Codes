#include<iostream>
#include<string>
using namespace std;
int main(){
    //undirected unweighted graph
    int vertices,edges;
    cin>>vertices>>edges;
    bool matrix[vertices][vertices]{false};
    for (int i = 0; i < edges; i++)
    {
        int u,v;
        cin>>u>>v;
        matrix[u][v] = true;
        matrix[v][u] = true;
        //in case of undirected weighted graph:
        // int u,v,weight;
        // cin>>u>>v;
        // matrix[u][v] = weight;
        // matrix[v][u] = weight;

        
        //in case of directed unweighted graph:
        // int u,v;
        // cin>>u>>v;
        // matrix[u][v] =1;

        
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
        
    }
    
    return 0;
}