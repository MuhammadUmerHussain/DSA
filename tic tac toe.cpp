#include <iostream>
using namespace std;
class TicTacToe{
    int arr[3][3];
    public:
    TicTacToe(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                arr[i][j]=0;
            }
        }
    }

    void input(){
        
    }
    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool checkFull(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==0){
                return false;
            }
        }
    }
    return true;
}
    bool checkEmpty(){
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                return false;
            }
        }
    }
    return true;
    }

    bool checknoOne(){
        int noOfOnes=0,noOFTwo=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]==1){
                    noOfOnes++;
                } else if(arr[i][j]==0){
                    noOFTwo++;
                }
            }
        }
        if(noOfOnes==1){
            return true;
        } 
         else return false;
    }

    bool playerOneTurn(){
    //    cout << "player 1: " << endl;
    //print();
//cout << endl;
    if(checkWin(2)){
        cout << "2"; 
        return true;
    }
    if(check(1,1)) return playerTwoTurn();
    if(check(2,1)) return playerTwoTurn();
    if(checkOne(1,1,0)) return playerTwoTurn();
    if(checkOne(1,1,2)) return playerTwoTurn();
    return false;
}
    bool playerTwoTurn(){
    //     cout << "player 2: " << endl;
    //print();
    //cout << endl;
    if(checkWin(1)){
        cout << "1"; 
        return true;
    }
    if(check(2,2)) return playerOneTurn();
    if(check(1,2)) return playerOneTurn();
    if(checkOne(2,2,0)) return playerOneTurn();
    if(checkOne(2,2,1)) return playerOneTurn();
    return false;
}

    void game(){
    
    int check=checkValidity();
    if(check == 1){
        playerOneTurn();
    }else if (check==2){
        playerTwoTurn();
    } else cout << "-1";
    }

    bool checkWin(int val){
    for(int i=0;i<3;i++) if(checkColumm(i,val,val,val,val)) return true;
    for(int i=0;i<3;i++) if(checkRow(i,val,val,val,val)) return true;
    if(checkDiagonalLeft(val,val,val,val)) return true;
    if(checkDiagonalRight(val,val,val,val)) return true;
    if(checkFull()|| checkEmpty() || checknoOne()) cout << "0" ;
    return false;
    }
    int checkValidity(){
    int noOfOnes=0, noOfTwo=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==1){
                noOfOnes++;
            } else if (arr[i][j]==2) {
                noOfTwo++;
            }
        }
    }
    if(noOfTwo==noOfOnes){
        return 1;
    } if (noOfOnes-1==noOfTwo){
        return 2;
    } else return -1;
}
    bool check(int val,int put){
    for(int i=0;i<3;i++) if(checkRow(i,val,put,0,val)) return true;
    for(int i=0;i<3;i++) if(checkColumm(i,val,put,0,val)) return true;
    if(checkDiagonalLeft(val,put,0,val)) return true;
    if(checkDiagonalRight(val,put,0,val)) return true;
    return false;

}
    bool checkOne(int val,int put,int val2){
        for(int i=0;i<3;i++) if(checkRow(i,val,put,0,val2)) return true;
        for(int i=0;i<3;i++) if(checkColumm(i,val,put,0,val2)) return true;
        if(checkDiagonalLeft(val,put,0,val2)) return true;
        if(checkDiagonalRight(val,put,0,val2)) return true;
        for(int i=0;i<3;i++) if(checkRow(i,val2,put,0,val)) return true;
        for(int i=0;i<3;i++) if(checkColumm(i,val2,put,0,val)) return true;
        if(checkDiagonalLeft(val2,put,0,val)) return true;
        if(checkDiagonalRight(val2,put,0,val)) return true;
        return false;
    }

    int checkRow(int i,int val,int put,int def,int val2){

    if(arr[i][0]==val && arr[i][1]==val2 && arr[i][2]==def){
        arr[i][2]=put;
        return 1;
   } else if(arr[i][0]==val && arr[i][1]==def && arr[i][2]==val2){
       arr[i][1]=put;
       return 1;
   } else if(arr[i][0]==def && arr[i][1]==val && arr[i][2]==val2){
       arr[i][0]=put;
       return 1;
   }
   return 0;

}
    int checkColumm(int i,int val,int put,int def,int val2){

    if(arr[0][i]==val && arr[1][i]==val2 && arr[2][i]==def){
        arr[2][i]=put;
        return 1;
    } else if(arr[0][i]==val && arr[1][i]==def && arr[2][i]==val2){
        arr[1][i]=put;
        return 1;
    } else if(arr[0][i]==def && arr[1][i]==val && arr[2][i]==val2){
        arr[0][i]=put;
        return 1;
   }
   return 0;

}
    int checkDiagonalRight(int val,int put,int def,int val2){

    if(arr[0][0]==val && arr[1][1]==val2 && arr[2][2]==def){
        arr[2][2]=put;
        return 1;
   } else if(arr[0][0]==val && arr[1][1]==def && arr[2][2]==val2){
       arr[1][1]=put;
       return 1;
   } else if(arr[0][0]==def && arr[1][1]==val && arr[2][2]==val2){
       arr[0][0]=put;
       return 1;
   } 
   return 0;

}
    int checkDiagonalLeft(int val,int put,int def,int val2){

    if(arr[0][2]==val && arr[1][1]==val2 && arr[2][0]==def){
        arr[2][0]=put;
        return 1;
   } else if(arr[0][2]==val && arr[1][1]==def && arr[2][0]==val2){
       arr[1][1]=put;
       return 1;
   } else if(arr[0][2]==def && arr[1][1]==val && arr[2][0]==val2){
       arr[0][2]=put;
       return 1;
   }
   return 0;

}
};
int main(){
    TicTacToe t;
    t.input();
    t.game();
}
