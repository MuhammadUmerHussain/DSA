#include <iostream>
#include <string>
using namespace std;
class LineNode{
    public:
    string Line_no;
    LineNode *next;

    LineNode(){
        Line_no="";
        next=NULL;
    }
    LineNode(string n){
        Line_no=n;
        next=NULL;
    }
};
class WordNode{
    public:
    string word;
    LineNode *head;
    WordNode *left;
    WordNode *right;

    WordNode(){
        word="";
        head=NULL;
        left=NULL;
        right=NULL;
    }

    WordNode(string w){
        word=w;
        head=NULL;
        left=NULL;
        right=NULL;
    }

    void addNoNode(string n){
        if(head==NULL){
            head= new LineNode(n);
            return;
        }
        LineNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new LineNode(n);
    }

    void print(){
        cout << word << " ";
        LineNode *temp=head;
        while(temp!=NULL){
            cout << temp->Line_no << " ";
            temp=temp->next;
        }
        cout << endl;
    }
};
class index{
    string *sentence_No;
    string *sentences;
    int Sentences_size;
    public:
    WordNode *root;

    bool compare(string x,string y){
        for(int i=0;i<x.size();i++){
            if(x[i]>y[i]){
                return true;
            } else if(x[i]<y[i]){
                return false;
            }
        }
    }

    void addWord(string w){
        if(root==NULL){
            root=new WordNode(w);
            return;
        }
        WordNode *temp=root , *prev=NULL;
        while(temp!=NULL){
            prev=temp;
            if(compare(temp->word,w)){
                temp=temp->left;
            } else temp=temp->right;
        }
        if(compare(prev->word,w)){
            prev->left=new WordNode(w);
        } else prev->right= new WordNode(w);
    }

    void addSentences(string arr[],string arr2[],int size){
        Sentences_size=size;
        sentences= new string [size];
        sentence_No= new string[size];
        for(int i=0;i<size;i++){
            sentence_No[i]=arr[i];
            sentences[i]=arr2[i];
        }
    }

    bool searchInSentence(string s,string w){
        bool compare=false;
        for(int i=0;i<s.size();i++){
            if(s[i]==w[0]){
                compare=true;
                for(int j=1;j<w.size();j++){
                    if(s[i+j]==w[j]){
                        compare=true;
                    } else {
                    	compare=false;
                    	break;
					}
                }
                if(compare) return true;
            }
        }
        return false;
    }

    void searchAndAdd(WordNode *r){
        if(r==NULL) return;
        for(int i=0;i<Sentences_size;i++){
            if(searchInSentence(sentences[i],r->word)){
                r->addNoNode(sentence_No[i]);
            }
        }
        searchAndAdd(r->left);
        searchAndAdd(r->right);
    }

    void InorderPrint(WordNode *r){
        if(r==NULL) return;
        InorderPrint(r->left);
        r->print();
        InorderPrint(r->right);
    }
};
int main(){
    index in;
    int size;
    cin >> size;
    cin.ignore();
    string word;
    for(int i=0;i<size;i++){
        getline(cin,word);
        in.addWord(word);
    }
    cin >> size;
    cin.ignore();
    string arr[size];
    string arr2[size];
    for(int i=0;i<size;i++){
        cin >> word;
        cin.ignore();
        arr[i]=word;
        getline(cin,word);
        arr2[i]=word;
    }
    in.addSentences(arr,arr2,size);
    in.searchAndAdd(in.root);
    in.InorderPrint(in.root);
}
