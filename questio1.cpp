#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool left(string arr[],int i,int j,string word,int x){
    if(x==word.length())
        return true;
    if(arr[i][j]=='*'){
       for(int z=x;z<word.length();z++){
            if(arr[i][j-1]==word[z]){
                if(left(arr,i,j-1,word,z)){
                    return true;
                }
            }
        }
    }
    if(arr[i][j]==word[x] || arr[i][j]=='+')
        if(left(arr,i,j-1,word,x+1))
            return true;
    return false;
}
bool right(string arr[],int i,int j,string word,int x){
    if(x>=word.length())
        return true;
    if(arr[i][j]=='*'){
        for(int z=x;z<word.length();z++){
            if(arr[i][j+1]==word[z]){
                if(right(arr,i,j+1,word,z)){
                    return true;
                }
            }
        }
    }
    if(arr[i][j]==word[x] || arr[i][j]=='+')
        if(right(arr,i,j+1,word,x+1))
            return true;
    return false;
}
bool up(string arr[],int i,int j,string word,int x){
    if(x==word.length())
        return true;
    if(arr[i][j]=='*'){
        for(int z=x;z<word.length();z++){
            if(arr[i-1][j]==word[z]){
                if(up(arr,i-1,j,word,z)){
                    return true;
                }
            }
        }
    }
    if(arr[i][j]==word[x] || arr[i][j]=='+')
        if(up(arr,i-1,j,word,x+1))
            return true;
    return false;
}
bool down(string arr[],int i,int j,string word,int x){
    if(x>=word.length())
        return true;
    if(arr[i][j]=='*'){
        for(int z=x;z<word.length();z++){
            if(arr[i+1][j]==word[z]){
                if(down(arr,i+1,j,word,z)){
                    return true;
                }
            }
        }
    }
    if(arr[i][j]==word[x] || arr[i][j]=='+'){
        if(down(arr,i+1,j,word,x+1))
            return true;
    }
    return false;
}
bool check(string arr[],int i,int j,string word){
    if(up(arr,i,j,word,0)){
        cout << i-1 << " " << j << " " << 'U' << endl;
    } 
    if(right(arr,i,j,word,0)){
        cout << i-1 << " " << j << " " << 'R' << endl;
    }
    if(down(arr,i,j,word,0)){
        cout << i-1 << " " << j << " " << 'D' << endl;
    } 
    if(left(arr,i,j,word,0)){
        cout << i-1 << " " << j << " " << 'L' << endl;
    } 
    else return false;
}
void WordFinder(string arr[],int row,int col,string word){
    for(int i=0;i<row+1;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==word[0] || arr[i][j]=='+'){
                check(arr,i,j,word);
            }
        }
    }
}
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
int main() {
    
    int row,col;
    
    cin >> row;
    cin >> col;

    
    string arr[row+1];
    
    for(int i=0;i<row+1;i++){
        getline(cin, arr[i]);
        arr[i]=removeSpaces(arr[i]);
    }
    
    int no;
    
    cin >> no;
    
    string words[no+1];
    
    for(int i=0;i<no+1;i++){
        getline(cin, words[i]);
        words[i]=removeSpaces(words[i]);
    }
    
    for(int i=1;i<no+1;i++){
        WordFinder(arr,row,col,words[i]);
    }

	return 0;
}
