#include<iostream>
#include<vector>
#define NODE 5
using namespace std;
int graph[NODE][NODE] = {{0, 1, 1, 1, 1},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 1, 0},
   {1, 1, 1, 0, 1},
   {1, 0, 0, 1, 0}
};
int tempGraph[NODE][NODE];
int findStartVert(){
   for(int i = 0; i<NODE; i++){
      int deg = 0;
      for(int j = 0; j<NODE; j++){
         if(tempGraph[i][j])
         deg++; 
      }
      if(deg % 2 != 0)
      return i;
   }
   return 0; 
}
bool isBridge(int u, int v){
   int deg = 0;
   for(int i = 0; i<NODE; i++)
      if(tempGraph[v][i])
         deg++;
      if(deg>1){
         return false; 
      }
   return true; 
}
int edgeCount(){
   int count = 0;
   for(int i = 0; i<NODE; i++)
      for(int j = i; j<NODE; j++)
         if(tempGraph[i][j])
            count++;
   return count; 
}
void fleuryAlgorithm(int start){
   static int edge = edgeCount();
   for(int v = 0; v<NODE; v++){
      if(tempGraph[start][v]){ 
         if(edge <= 1 || !isBridge(start, v)){
            cout << start << "--" << v << " ";
            tempGraph[start][v] = tempGraph[v][start] = 0; 
            edge--;
            fleuryAlgorithm(v);
         }
      }
   }
}
int main(){
   for(int i = 0; i<NODE; i++) //copy main graph to tempGraph
   for(int j = 0; j<NODE; j++)
   tempGraph[i][j] = graph[i][j];
   cout << "Euler Path Or Circuit: ";
   fleuryAlgorithm(findStartVert());
}
