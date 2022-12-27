#include <iostream>
#include <queue>
using namespace std;
class AdjListNode{
    public:
    int data;
    AdjListNode *next;

    AdjListNode(){
        data=0;
        next-NULL;
    }

    AdjListNode(int d){
        data=d;
        next=NULL;
    }
};
class AdjList{
    public:
    AdjListNode *head;

    AdjList(){
        head=NULL;
    }

    void addNode(int d){
        if(head==NULL){
            head= new AdjListNode(d);
            return;
        }
        AdjListNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new AdjListNode(d);
    }

    void printList(){
        for(AdjListNode *temp=head;temp!=NULL;temp=temp->next){
            cout << temp->data << " ";
        }
        cout << endl;
    }

};
class Graph{
    public:
    int V;
    AdjList *array;

    void createGraph(int s){
        V=s;
        array = new AdjList[V];
    }

    void addEdge(int src,int dest){
        if(src>V || src<0){
            cout << "Invalid" << endl;
            return;
        }
        array[src].addNode(dest);
        //array[dest].addNode(src);
    }

    void printGraph(){
        for(int i=0;i<V;i++){
            cout << i << " ";
            array[i].printList();
        }
    }

    void BFS(int s){
        bool check[V]={false};
        queue<int> q;
        q.push(s);
        check[s]=true;
        while(!q.empty()){
            s=q.front();
            cout << s << " ";
            q.pop();
            for(AdjListNode *temp=array[s].head;temp!=NULL;temp=temp->next){
                if(!check[temp->data]){
                    check[temp->data]=true;
                    q.push(temp->data);
                }
            }
       }
    }
    void DFS(int s){
        bool check[V]={false};
        check[s]=true;
        cout << s << " ";
        for(AdjListNode *temp=array[s].head;temp!=NULL;temp=temp->next){
            if(!check[temp->data]){
                check[temp->data]=true;
                DFSearch(check,temp->data);
            }
        }
    }
    void DFSearch(bool check[],int s){
        check[s]=true;
        cout << s << " ";
        for(AdjListNode *temp=array[s].head;temp!=NULL;temp=temp->next){
            if(!check[temp->data]){
                check[temp->data]=true;
                DFSearch(check,temp->data);
            }
        }
    }

    bool isCyclicUtil(int v,bool visited[],int parent){
        visited[v]=true;
        for(AdjListNode *temp=array[V].head;temp!=NULL;temp=temp->next){
            if(!visited[temp->data]){
                if(isCyclicUtil(temp->data,visited,v)){
                    return true;
                }
            } else if (temp->data!=parent){
                    return true;
                }
        }
        return false;
    }

    bool isCyclic(){
        bool visited[V];
        for(int i=0;i<V;i++) visited[i]=false;

        for(int u=0;u<V;u++){
            if(!visited[u]){
                if(isCyclicUtil(u,visited,-1)){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclicUtilDirected(int v,bool visited[],bool restack[]){
        if(visited[v]==false){
            visited[v]=true;
            restack[v]=true;
            for(AdjListNode *temp=array[v].head;temp!=NULL;temp=temp->next){
                if(!visited[temp->data]){
                    if(isCyclicUtilDirected(temp->data,visited,restack)){
                        return true;
                    }} else if (restack[temp->data]){
                        return true;
                }
            }
        }
        restack[v]=false;
        return false;
    }

    bool isCyclicDirected(){
        bool visited[V],restack[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            restack[i]=false;
        }

        for(int u=0;u<V;u++){
            if(!visited[u]){
                if(isCyclicUtilDirected(u,visited,restack)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
    Graph g;
    g.createGraph(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.BFS(3);
    //g.addEdge(1, 2);
    //g.addEdge(2, 0);
    //g.addEdge(2, 3);
    //g.addEdge(3, 3);
    //g.printGraph();
    //cout << endl;
    //cout << g.isCyclic();
   //g.BFS(0);
    //cout << g.isCyclicDirected();
   /* Graph g2;
    g2.createGraph(3);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    cout << g2.isCyclic();*/
    

}
