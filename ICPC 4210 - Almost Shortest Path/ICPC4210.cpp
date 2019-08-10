/******************************************************************************************************************************
 * ICPC 4210 - Almost Shortest Path
 * https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&page=show_problem&problem=2211
 *
 * Author:
 *   Stephano Beneventi <stbeneventi@gmail.com>
 *
 */

#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

class Graph{
  public:

  int V;
  vii P;

  Graph(int v, Graph g){
    V=g.V;
    P = vii(g.V, vi(0));
  }

  Graph(int v){
    V=v;
    P = vii(V, vi(V, -1));
  }

  int dijkstra(int s, int t, Graph &GC);
  void printGraph();
  void delGraph(Graph &GC, int t);

};

int Graph::dijkstra(int s,int t,Graph &GC){

  vector<int> lambda(V,-1);
  vector<bool> T(V,true);

    int u=-1,i,j,min=-1;
    lambda[s]=0;

    while(u!=t){

      for(i=0;i<V;i++){
         if(min==-1 && lambda[i]!=-1 && T[i]==true)min=i;
         if(lambda[i]<=lambda[min] && lambda[i]!=-1 && T[i]==true){
            min=i;
         }
      }

      u=min;
      if(u==-1)break;
      min=-1;

      for(i=0;i<V;i++){
        if(P[u][i]!=-1 && T[i]==true){
          if(lambda[i]==-1){
            lambda[i]=lambda[u]+P[u][i];
            GC.P[i].push_back(u);
          }
          else if(lambda[i]>lambda[u]+P[u][i]){
            lambda[i]=lambda[u]+P[u][i];
            GC.P[i].clear();
            GC.P[i].push_back(u);
          }
          else if(lambda[i]==lambda[u]+P[u][i]){
            GC.P[i].push_back(u);
          }
        }
      }

      T[u]=false;
    }

   return lambda[t];

}

void Graph::printGraph(){
  int size;
  for(int i=0;i<V;i++){
    size=P[i].size();
    printf("%d",i);
    for (int j=0;j<size;j++){
      printf("[%d]",P[i][j]);
    }
    printf("\n");
  }
};

void Graph::delGraph(Graph &GC, int f) {
  for (int i=0;i<GC.P[f].size();i++) {
    int u = GC.P[f][i];
    P[u][f] = -1;
    delGraph(GC,u);
  }
}

int main() {
  int v,a;
  int s,t;
  int v1,v2,p;
  int i;

  while (1) {
    scanf("%d %d",&v,&a);

    if (v==0 && a==0)
      break;

    scanf("%d %d",&s,&t);

    Graph G1(v);

    for (i = 0; i < a; i++) {
      scanf("%d %d %d",&v1,&v2,&p);
      G1.P[v1][v2] = p;
    }

    Graph G2(v,G1);
    Graph G3(v,G1);

    G1.dijkstra(s,t,G2);

    G1.delGraph(G2,t);

    printf("%d\n",G1.dijkstra(s,t,G3));

  }
}
