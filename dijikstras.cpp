#include <iostream>
#include <limits.h>
#define INF 9999
using namespace std;
#define V 4
void print(int set[V]){
    for(int i=0;i<V;i++){
        cout << i << " " << set[i] << endl;
    }
}
int minDist(bool check[],int set[]){
    int min=INT_MAX, min_val;
    for(int i=0;i<V;i++){
        if(check[i]==false && set[i] <= min){
            min=set[i];
            min_val=i;
        }
    }
    return min_val;
}
void dijkstra(int graph[V][V],int src){
    bool check[V]={false};
    int set[V]={INT_MAX};
    for(int i=0;i<V;i++){
        check[i]=false;
        set[i]=INT_MAX;
    }
    set[src]=0;
    for(int i=0;i<V-1;i++){
        int val=minDist(check,set);
        check[val]=true;
        for(int j=0;j<V;j++){
            if(!check[j] && set[val]!=INT_MAX && graph[val][j] && set[val] + graph[val][j] < set[j]){
                set[j]=set[val] +graph[val][j];
            }
        }
    }

    print(set);
}
void printSol(int graph[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF){
                cout << "i" << " ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void WFI(int graph[V][V]){
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] > (graph[i][k] + graph[k][j]) && (graph[k][j] != INF && graph[i][k] != INF)) 
                    graph[i][j] = graph[i][k] + graph[k][j];
        }}
    }
    printSol(graph);
}
int main(){           // a   b   c    d
    int graph[V][V] = { { 0, 20, 1, 1}, //a
                        { 20, 0, 3, INF },//b
                        { 1, 3, 0, 1 },//c
                        { 1, INF, 1, 0 } };//d

    WFI(graph);
}