#include <math.h>
#include <iostream>
#include <string>
#include "../include/Searching_Algorithms.hpp"

using namespace std;
void gotoxy (int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
}
void Display()
{
    string dna[4]={
        "-. .-.   .-. .-.   .-. .-.   .",
        "||\\|||\\ /|||\\|||\\ /|||\\|||\\ /|",
        "|/ \\|||\\|||/ \\|||\\|||/ \\|||\\||",
        "~   `-~ `-`   `-~ `-`   `-~ `-"
    };
    int col=35,row;
    for(int i=0;i<dna[0].length();i++)
    {
        row=7;
        for(int j=0;j<4;j++)
        {
            gotoxy(col,row);
            cout<<dna[j][i];
            row++;
        }
        col++;
        Sleep(250);
    }
    
}
void StartDisplay()
{
    Display();
    gotoxy(25,11);
    cout<<"==================================================="<<endl;
    gotoxy(40,13);
    string name="DNA CORPUS";
    for(int i=0;i<name.length();i++)
    {
        cout<<name[i]<<" ";
        Sleep(500);
    }
    gotoxy(25,15);
    cout<<"==================================================="<<endl;
    gotoxy(40,16);
    cout<<"By: ";
    gotoxy(40,17);
    cout<<"Khawaja Abdullah Ghori" << endl << "Moiz Mustafa" << endl << "Umer Hussain";
    cout<<"\nPRESS ANY KEY To CONTINUE";
    getch();
    system("cls");
}
int main() {
    system("cls");
    StartDisplay();
	testFromFile();
    
}
