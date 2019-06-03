#include <iostream>
#include <string.h>
using std::cout;

void dfs(int graph[][4],bool visited[],int n,int i){
    
    visited[i] = true;
    cout << i << "\n";

    for(int j = 0; j < n; j++){
        if(graph[i][j] && !visited[j]){
            dfs(graph,visited,n,j);
        }
    }

}

int main(void){

    bool visited[4];
    memset(visited,false,sizeof(visited));
    int graph[4][4] =   {
                            {0,1,0,1},
                            {1,0,1,0},
                            {0,1,0,1},
                            {1,0,1,0}
                        };


    cout << "DFS Traversal of the graph\n";
    dfs(graph,visited,4,0);

    return 0;
}