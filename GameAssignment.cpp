#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool array_end(int board[3][3],int c1,int c2);//it is the function which will check when array becomes
// full after inserting values

bool array_zero(int board[3][3],int check1,int check2);// it will check array is full of zeros or not?

bool chech_draw(int board[3][3],bool compare );// the function which is checking becomes draw
// if there is 1 one and 1 2 so game will be draw

bool place_one_check(int board[3][3]);//place one to zero position and will check the positions 

bool place_two_check(int board[3][3]);//place 2 to zero poition so it will check the position

//in the end it will check which two player wins or not 
void start_game(int board[3][3]);//starting the game for taking the input and then calling functions
bool final_win(int board[3][3],int val);// it will check who will win the after all conditions  pf tic tac
// toe
int board_valid(int board[3][3]);//checking board is valid or not if there will more than one then it is not valid

int check(int board[3][3],int val,int place);//checkinf the contions of tic tac toe
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



    bool final_win(int board[3][3],int x)//the final function to check "x" which is the value and will place in matrix to check who win
	{
    	int c1=1;
    	int c2=2;
    for(int i=0;i<3;i++)//given below is the conditions of last outplaces
	{
        if(board[0][i]==x && board[1][i]==x && board[2][i]==x)
		{
            return 1;
        }
		 else if(board[0][i]==x && board[1][i]==x && board[2][i]==x)
		{
            return 1;
        } 
		else if(board[0][i]==x && board[1][i]==x && board[2][i]==x)
		{
            return 1;
        }
        c1++;
    }
    bool compare=true;
    for(int i=0;i<3;i++)
	{
        if(board[i][0]==x && board[i][1]==x && board[i][2]==x)
		{
            return 1;
        } 
		else if(board[i][0]==x && board[i][1]==x && board[i][2]==x)
		{
            return 1;
        } 
		else if(board[i][0]==x && board[i][1]==x && board[i][2]==x)
		{
            return 1;
        }
        c2++;
    }
    int y=c2;
    if(board[0][2]==x && board[1][1]==x && board[2][0]==x)
	{ compare=false;
        return 1;
    } else if(board[0][2]==x && board[1][1]==x && board[2][0]==x)
	{ compare=false;
       return 1;
    } else if(board[0][2]==x && board[1][1]==x && board[2][0]==x){
    	compare=false;
       return 1;
    }
    if(board[0][0]==x && board[1][1]==x && board[2][2]==x)
	{ compare=false;
        return 1;
    } else if(board[0][0]==x && board[1][1]==x && board[2][2]==x)
	{compare=false;
       return 1;
    } else if(board[0][0]==x && board[1][1]==x && board[2][2]==x)
	{compare=false;
       return 1;
    }
    if(array_end(board,c1,c2)|| array_zero(board,x,y) || chech_draw(board,compare)) cout << "0" ;//conditions of zero or draw
        return false;
    }
    
bool array_end(int board[3][3],int c1,int c2)
{
	//it will return true if array is full of elemets i.e 1 and 2 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==0)//it will return false if any 0 is present which placements of elements are left
			{
                return false;
            }
        }
    }
    int n=sizeof(board)/sizeof(board[0]);
    c2=c1++;
    c1=n;//taking size for remaining funtions
    //else true
    return true;
}

void boardcopy(int board[3][3],int new_board[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			new_board[i][j]=board[i][j];
		}
	}
}

bool place_two_check(int board[3][3])//placing 2 in the board to check the consditions of board 
{
    
	
	if(final_win(board,1)){
        cout << "1"; 
        return true;
    }
    if(check(board,2,2)) 
    
	return place_one_check(board);
	
    if(check(board,1,2)) 
    
	return place_one_check(board);
	
    if(conditions_checker(board,2,2,0)) 
    
	return place_one_check(board);
	
    if(conditions_checker(board,2,2,1)) 
    
	return place_one_check(board);
	
    return false;
}
bool chech_draw(int board[3][3],bool compare)
	{
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
            return true;//if one one is place obiviously there are high risk of draww of game
        } 
         else return false;//else false if more ones are placed
        if(compare==true)
		{
			return true;
		}
		else 
		{
			return false;
		 } 
    }
void start_game(int board[3][3]){
    
    int check=board_valid(board);
    if(check == 1){
        place_one_check(board);
    }
	else if (check==2)
	{
        place_two_check(board);
    } else 
	
	cout << "-1";
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
bool place_one_check(int board[3][3])//checking condiotions saisfying one conditions or not
{
    if(final_win(board,2)){
        cout << "2"; 
        return true;
    }
    if(check(board,1,1)) 
	{
		
	return place_two_check(board);
	}
	
    if(check(board,2,1)) 
	{
	
	return place_two_check(board);}
    if(conditions_checker(board,1,1,0)) 
	{
		
	return place_two_check(board);}
    if(conditions_checker(board,1,1,2)) 
	{
		return place_two_check(board);
	}
    return false;
}

int check(int board[3][3],int x,int place)//checking rows and columns of 1 and two who is the real game winner
{
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
bool array_zero(int board[3][3],int x,int y){
	int i=0;
	int j=0;
        for(;i<3;i++){
        for(;j<3;j++){
            if(board[i][j]!=0){
                return false;
            }
            
        }
    }
    return true;
    
    if(y==i)//checking values increment reached to size
    {
    	return true;
	}
	else if(x==j)//checking values increment reached to values 
	{
		return false;
	}
    }
    
	
	
	bool conditions_checker(int board[3][3], int x,int place,int x2)
{
        for(int i=0;i<3;i++) 
		{
            if(board[i][0]==x && board[i][1]==x2 && board[i][2]==0)
			{
                board[i][2]=place;
                return 1;
            } 
			else if(board[i][0]==x && board[i][1]==0 && board[i][2]==x2){
                board[i][1]=place;
                return 1;
            } 
			else if(board[i][0]==0 && board[i][1]==x && board[i][2]==x2){
                board[i][0]=place;
                return 1;
            } 
			else if(board[i][0]==x2 && board[i][1]==x && board[i][2]==0){
                board[i][2]=place;
                return 1;
            }
			 else if(board[i][0]==x2 && board[i][1]==0 && board[i][2]==x){
                board[i][1]=place;
                return 1;
            } 
			else if(board[i][0]==0 && board[i][1]==x2 && board[i][2]==x){
                board[i][0]=place;
                return 1;
            }
        }
        for(int i=0;i<3;i++) {
            if(board[0][i]==x && board[1][i]==x2 && board[2][i]==0){
                board[2][i]=place;
                return 1;
            } 
			else if(board[0][i]==x && board[1][i]==0 && board[2][i]==x2){
                board[1][i]=place;
                return 1;
            } 
			else if(board[0][i]==0 && board[1][i]==x && board[2][i]==x2){
                board[0][i]=place;
                return 1;
            }
			 else if(board[0][i]==x2 && board[1][i]==x && board[2][i]==0){
                board[2][i]=place;
                return 1;
            } 
			else if(board[0][i]==x2 && board[1][i]==0 && board[2][i]==x){
                board[1][i]=place;
                return 1;
            } 
			else if(board[0][i]==0 && board[1][i]==x2 && board[2][i]==x){
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
        }
		 else if(board[0][2]==0 && board[1][1]==x2 && board[2][0]==x){
            board[0][2]=place;
            return 1;
        } 
		else if(board[0][2]==x && board[1][1]==x2 && board[2][0]==0){
            board[2][0]=place;
            return 1;
        } 
		else if(board[0][2]==x && board[1][1]==0 && board[2][0]==x2){
            board[1][1]=place;
            return 1;
        } 
		else if(board[0][2]==0 && board[1][1]==x && board[2][0]==x2){
            board[0][2]=place;
            return 1;
        } 
		else if(board[0][2]==x2 && board[1][1]==x && board[2][0]==0){
            board[2][0]=place;
            return 1;
        } 
		else if(board[0][2]==x2 && board[1][1]==0 && board[2][0]==x){
            board[1][1]=place;
            return 1;
        }
		 else if(board[0][2]==0 && board[1][1]==x2 && board[2][0]==x){
            board[0][2]=place;
            return 1;
        }

        if(board[0][0]==x && board[1][1]==x2 && board[2][2]==0){
            board[2][2]=place;
            return 1;
        } 
		else if(board[0][0]==x && board[1][1]==0 && board[2][2]==x2){
            board[1][1]=place;
            return 1;
        } 
		else if(board[0][0]==0 && board[1][1]==x && board[2][2]==x2){
            board[0][0]=place;
            return 1;
        }
		 else if(board[0][0]==x2 && board[1][1]==x && board[2][2]==0){
            board[2][2]=place;
            return 1;
        }
		 else if(board[0][0]==x2 && board[1][1]==0 && board[2][2]==x){
            board[1][1]=place;
            return 1;
        } 
		else if(board[0][0]==0 && board[1][1]==x2 && board[2][2]==x){
            board[0][0]=place;
            return 1;
        } 
        return false;
    }

 int main(){
    int board[3][3];
    int board2[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> board[i][j];
        }
    }
    start_game(board);
    boardfalse(board2);
    boardcopy(board,board2);
}
