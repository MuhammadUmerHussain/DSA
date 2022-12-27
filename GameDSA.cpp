#include <iostream>
using namespace std;
bool array_end(int board[3][3]);//it is the function which will check when array becomes
// full after inserting values

bool array_zero(int board[3][3]);// it will check array is full of zeros or not?

bool chech_draw(int board[3][3]);// // the function which is checking becomes draw
// if there is 1 one and 1 2 so game will be draw


bool place_one_check(int board[3][3]);//place one to zero position and will check the positions 

bool place_two_check(int board[3][3]);//place 2 to zero poition so it will check the position

//in the end it will check which two player wins or not 

void start_game(int board[3][3]);//starting the game for taking the input and then calling functions

bool final_win(int board[3][3],int val);// // it will check who will win the after all conditions  pf tic tackoi jeeta?


int board_valid(int board[3][3]);////checking board is valid or not if there will more than one then it is not valid

int check(int board[3][3],int val,int put);//checkinf the contions of tic tac toe

bool checkOne(int board[3][3], int val,int put,int val2);

bool conditions_checker(int board[3][3], int val,int place,int val2);// checking the possibilties of tic tac toe 
int ones1=0;

int two2=0;


bool boardfalse(int new_board[3][3])//new board to copy old one
{
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			new_board[i][j]=0;
		}
	}
}

bool checkOne(int board[3][3], int x,int place,int x2){
        for(int i=0;i<3;i++) {
            if(board[i][0]==x && board[i][1]==x2 && board[i][2]==0){
                board[i][2]=place;
                return 1;
            } else if(board[i][0]==x && board[i][1]==0 && board[i][2]==x2){
                board[i][1]=place;
                return 1;
            } else if(board[i][0]==0 && board[i][1]==x && board[i][2]==x2){
                board[i][0]=place;
                return 1;
            } else if(board[i][0]==x2 && board[i][1]==x && board[i][2]==0){
                board[i][2]=place;
                return 1;
            } else if(board[i][0]==x2 && board[i][1]==0 && board[i][2]==x){
                board[i][1]=place;
                return 1;
            } else if(board[i][0]==0 && board[i][1]==x2 && board[i][2]==x){
                board[i][0]=place;
                return 1;
            }
        }
        for(int i=0;i<3;i++) {
            if(board[0][i]==x && board[1][i]==x2 && board[2][i]==0){
                board[2][i]=place;
                return 1;
            } else if(board[0][i]==x && board[1][i]==0 && board[2][i]==x2){
                board[1][i]=place;
                return 1;
            } else if(board[0][i]==0 && board[1][i]==x && board[2][i]==x2){
                board[0][i]=place;
                return 1;
            } else if(board[0][i]==x2 && board[1][i]==x && board[2][i]==0){
                board[2][i]=place;
                return 1;
            } else if(board[0][i]==x2 && board[1][i]==0 && board[2][i]==x){
                board[1][i]=place;
                return 1;
            } else if(board[0][i]==0 && board[1][i]==x2 && board[2][i]==x){
                board[0][i]=place;
                return 1;
            }
        }    
         if(board[0][2]==x && board[1][1]==x2 && board[2][0]==0){
            board[2][0]=place;
            return 1;
        }
		 else if(board[0][2]==x && board[1][1]==0 && board[2][0]==x2)
		 {
            board[1][1]=place;
            return 1;
        } 
		else if(board[0][2]=0 && board[1][1]==x && board[2][0]==x2)
		{
            board[0][2]=place;
            return 1;
        }
		 else  if(board[0][2]==x2 && board[1][1]==x && board[2][0]==0){
            board[2][0]=place;
            return 1;
        }
		 else if(board[0][2]==x2 && board[1][1]==0 && board[2][0]==x)
		{
            board[1][1]=place;
            return 1;
        } else if(board[0][2]==0 && board[1][1]==x2 && board[2][0]==x){
            board[0][2]=place;
            return 1;
        } else if(board[0][2]==x && board[1][1]==x2 && board[2][0]==0){
            board[2][0]=place;
            return 1;
        } else if(board[0][2]==x && board[1][1]==0 && board[2][0]==x2){
            board[1][1]=place;
            return 1;
        } else if(board[0][2]==0 && board[1][1]==x && board[2][0]==x2){
            board[0][2]=place;
            return 1;
        } else if(board[0][2]==x2 && board[1][1]==x && board[2][0]==0){
            board[2][0]=place;
            return 1;
        } else if(board[0][2]==x2 && board[1][1]==0 && board[2][0]==x){
            board[1][1]=place;
            return 1;
        } else if(board[0][2]==0 && board[1][1]==x2 && board[2][0]==x){
            board[0][2]=place;
            return 1;
        }

        if(board[0][0]==x && board[1][1]==x2 && board[2][2]==0){
            board[2][2]=place;
            return 1;
        } else if(board[0][0]==x && board[1][1]==0 && board[2][2]==x2){
            board[1][1]=place;
            return 1;
        } else if(board[0][0]==0 && board[1][1]==x && board[2][2]==x2){
            board[0][0]=place;
            return 1;
        } else if(board[0][0]==x2 && board[1][1]==x && board[2][2]==0){
            board[2][2]=place;
            return 1;
        } else if(board[0][0]==x2 && board[1][1]==0 && board[2][2]==x){
            board[1][1]=place;
            return 1;
        } else if(board[0][0]==0 && board[1][1]==x2 && board[2][2]==x){
            board[0][0]=place;
            return 1;
        } 
        return false;
    }
    bool final_win(int board[3][3],int x){
    for(int i=0;i<3;i++){
        if(board[0][i]==x && board[1][i]==x && board[2][i]==x){
            return 1;
        } else if(board[0][i]==x && board[1][i]==x && board[2][i]==x){
            return 1;
        } else if(board[0][i]==x && board[1][i]==x && board[2][i]==x){
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        if(board[i][0]==x && board[i][1]==x && board[i][2]==x){
            return 1;
        } else if(board[i][0]==x && board[i][1]==x && board[i][2]==x){
            return 1;
        } else if(board[i][0]==x && board[i][1]==x && board[i][2]==x){
            return 1;
        }
    }
    if(board[0][2]==x && board[1][1]==x && board[2][0]==x){
        return 1;
    } else if(board[0][2]==x && board[1][1]==x && board[2][0]==x){
       return 1;
    } else if(board[0][2]==x && board[1][1]==x && board[2][0]==x){
       return 1;
    }
    if(board[0][0]==x && board[1][1]==x && board[2][2]==x){
        return 1;
    } else if(board[0][0]==x && board[1][1]==x && board[2][2]==x){
       return 1;
    } else if(board[0][0]==x && board[1][1]==x && board[2][2]==x){
       return 1;
    }
    if(array_end(board)|| array_zero(board) || chech_draw(board)) cout << "0" ;
        return false;
    }
bool array_end(int board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

bool chech_draw(int board[3][3]){
        int counter1=0,counter2=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==1){
                    counter1++;
                } else if(board[i][j]==0){
                    counter2++;
                }
            }
        }
        if(counter1==1){
            return true;
        } 
         else return false;
    }
bool place_one_check(int board[3][3]){
    if(final_win(board,2)){
        cout << "2"; 
        return true;
    }
    if(check(board,1,1)) 
	{
		
	return place_two_check(board);
	}
	
    if(check(board,2,1)) {
	return place_two_check(board);}
    if(checkOne(board,1,1,0)) 
	{
		
	return place_two_check(board);}
    if(checkOne(board,1,1,2)) 
	{
		return place_two_check(board);
	}
    return false;
}
bool place_two_check(int board[3][3]){
    if(final_win(board,1)){
        cout << "1"; 
        return true;
    }
    if(check(board,2,2)) return place_one_check(board);
    if(check(board,1,2)) return place_one_check(board);
    if(checkOne(board,2,2,0)) return place_one_check(board);
    if(checkOne(board,2,2,1)) return place_one_check(board);
    return false;
}
void start_game(int board[3][3]){
    
    int check=board_valid(board);
    if(check == 1){
        place_one_check(board);
    }else if (check==2){
        place_two_check(board);
    } else cout << "-1";
    }

int board_valid(int board[3][3]){
    int counter1=0, counter2=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==1){
                counter1++;
            } else if (board[i][j]==2) {
                counter2++;
            }
        }
    }
    if(counter2==counter1){
        return 1;
    } if (counter1-1==counter2){
        return 2;
    } else return -1;
}
int check(int board[3][3],int x,int place){
    for(int i=0;i<3;i++) {
        if(board[i][0]==x && board[i][1]==x && board[i][2]==0){
            board[i][2]=place;
            return 1;
        } else if(board[i][0]==x && board[i][1]==0 && board[i][2]==x){
            board[i][1]=place;
            return 1;
        } else if(board[i][0]==0 && board[i][1]==x && board[i][2]==x){
            board[i][0]=place;
            return 1;
        }
    }
    for(int i=0;i<3;i++){
         if(board[0][i]==x && board[1][i]==x && board[2][i]==0){
            board[2][i]=place;
            return 1;
        } else if(board[0][i]==x && board[1][i]==0 && board[2][i]==x){
            board[1][i]=place;
            return 1;
        } else if(board[0][i]==0 && board[1][i]==x && board[2][i]==x){
            board[0][i]=place;
            return 1;
        }
    }
    if(board[0][0]==x && board[1][1]==x && board[2][2]==0){
        board[2][2]=place;
        return 1;
    } else if(board[0][0]==x && board[1][1]==0 && board[2][2]==x){
       board[1][1]=place;
       return 1;
    } else if(board[0][0]==0 && board[1][1]==x && board[2][2]==x){
       board[0][0]=place;
       return 1;
    } 
    if(board[0][2]==x && board[1][1]==x && board[2][0]==0){
        board[2][0]=place;
        return 1;
   } else if(board[0][2]==x && board[1][1]==0 && board[2][0]==x){
       board[1][1]=place;
       return 1;
   } else if(board[0][2]==0 && board[1][1]==x && board[2][0]==x){
       board[0][2]=place;
       return 1;
   }
    return false;

}
bool array_zero(int board[3][3]){
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=0){
                return false;
            }
        }
    }
    return true;
    }

 int main(){
    int board[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> board[i][j];
        }
    }
    start_game(board);
}
