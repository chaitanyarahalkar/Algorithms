#include <iostream>
#include <list>
#include <string.h>

using std::cout;
using std::list;

void bfs(int graph[][4],bool visited[],int n,int i){
  	  
  	list<int> q;

  	visited[i] = true;

  	q.push_back(i);

  	while(!q.empty()){

  		i = q.front();
  		cout << i << "\n";
  		q.pop_front();

  		for(int j = 0; j < n; j++)
  			if(!visited[j] && graph[i][j]){

  				visited[j] = true;
  				q.push_back(j);
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


    cout << "BFS Traversal of the graph\n";
    bfs(graph,visited,4,0);

    return 0;
}