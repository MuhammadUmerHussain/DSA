#include <iostream>
using namespace std;
class node{
    public:
    string name;
    int total_processes , processes_in_each_cycle;
    int key;
    node *next;
    node(){
        name="";
        total_processes=0;
        processes_in_each_cycle=0;
        key=-1;
       next=NULL;
    }
    node(string x,int y,int z,int k){
        name=x;
        total_processes=y;
        processes_in_each_cycle=z;
        key=k;
        next=NULL;
    }
    node(string x,int y,int z,node *n,int k){
        name=x;
        total_processes=y;
        processes_in_each_cycle=z;
        next=n;
        key=k;
    }
};
class circular{
    public:
    node *tail;
    int size;

    circular(){
        tail=NULL;
        size=-1;
    }
    void InsertAtEnd(string x,int y,int z){
        size++;
        node *new_node = new node(x,y,z,NULL,size);		
	    if (tail == NULL){
			tail = new_node;
			tail->next = new_node;
			return;
		}
		new_node->next =tail->next;
		tail->next = new_node;
        tail=new_node;
    }
    void print(){
        node *temp=tail->next;
        for(int i=0;i<size+1;i++){
            cout << temp->name << endl;
            temp=temp->next;
        }
    }
    void remove(node *temp,node *prev){
        prev->next=temp->next;
        delete temp;
        size--;
    }
    void process(){
        node *temp=tail->next,*prev=tail;
        while(size>=0){
            cout << temp->name <<  endl;
            temp->total_processes=temp->total_processes-temp->processes_in_each_cycle;
            if(temp->total_processes<=0){
                remove(temp,prev);
            }
            prev=temp;
            temp=temp->next; 
        }
    }
};
int main(){
    circular c;
    int no;
    cin >> no;
    string n;
    int t,cycle;
    for(int i=0;i<no;i++){
        cin >> n;
        cin >> t;
        cin >> cycle;
        c.InsertAtEnd(n,t,cycle);
    }
    c.process();
}