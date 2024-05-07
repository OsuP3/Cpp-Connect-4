#include <iostream>
#include <vector>
using namespace std;

void PrintBoard(vector<char> board){// 6 vertical, 7 horizontal
    //cout<<"| | | | | | | |\n| | | | | | | |\n| | | | | | | |\n| | | | | | | |\n| | | | | | | |\n| | | | | | | |";
    for(int i = 0; i < 42; i++){
        cout<<"|"<<board.at(i)<<"|"<<board.at(i+1)<<"|"<<board.at(i+2)<<"|"<<board.at(i+3)<<"|"<<board.at(i+4)<<"|"<<board.at(i+5)<<"|"<<board.at(i+6)<<"|\n";
        i = i +6 ;
    }
    cout<<" 1 2 3 4 5 6 7 "<<endl;
}

string Result(vector<char> board){
    vector<char> four = {};


    for(int i = 0; i < 6; i++){//check horizontals
        for(int k = 0; k < 3; k++){
            four.push_back(board.at(k+(7*i)));
            four.push_back(board.at(k+1+(7*i)));
            four.push_back(board.at(k+2+(7*i)));
            four.push_back(board.at(k+3+(7*i)));
            if(four.at(0) != ' ' && four.at(0) == four.at(1) && four.at(1) == four.at(2) && four.at(2) == four.at(3)){
                cout<<"\n"<<four.at(0);
                return " Wins!";
            }
            four = {};
        }
        four = {};
    }
    for(int i = 0; i < 7; i++){//check verticals
        for(int k = 0; k < 3; k++){
            four.push_back(board.at(i+(k*7)));
            four.push_back(board.at(i+7+(k*7)));
            four.push_back(board.at(i+14+(k*7)));
            four.push_back(board.at(i+21+(k*7)));
            if(four.at(0) != ' ' && four.at(0) == four.at(1) && four.at(1) == four.at(2) && four.at(2) == four.at(3)){
                cout<<"\n"<<four.at(0);
                return " Wins!";
            }
            four = {};
        }
        four = {};
    }
    for(int i = 0; i < 4; i++){//check diagonals
        for(int k = 0; k < 3; k++){
            four.push_back(board.at(i+(7*k)));
            four.push_back(board.at(i+8+(7*k)));
            four.push_back(board.at(i+16+(7*k)));
            four.push_back(board.at(i+24+(7*k)));
            if(four.at(0) != ' ' && four.at(0) == four.at(1) && four.at(1) == four.at(2) && four.at(2) == four.at(3)){
                cout<<"\n"<<four.at(0);
                return " Wins!";
            }
            four = {};
        }

        for(int k = 0; k < 3; k++){//check diagonals
            four.push_back(board.at(6-i+(7*k)));
            four.push_back(board.at(5-i+7+(7*k)));
            four.push_back(board.at(4-i+14+(7*k)));
            four.push_back(board.at(3-i+21+(7*k)));
            if(four.at(0) != ' ' && four.at(0) == four.at(1) && four.at(1) == four.at(2) && four.at(2) == four.at(3)){
                cout<<"\n"<<four.at(0);
                return " Wins!";
            }
            four = {};
        }

        four = {};
        }
    for(int i = 0; i < 7; i++){
            if(board.at(i) == ' '){
            return "none";
            }
        }

    return "DRAW";
}


int main()
{
    int column = 0;
    char player;
    vector<char> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    PrintBoard(board);

    player = 'X';

    while(Result(board) == "none"){\
        column = 0;

        while(column < 1 || column > 7){
            cout<<"pick a column 1-7"<<endl;
            cin>>column;
        }

        for(int i = 0; i < 7; i++){
            if(i == 6){
                column = 0;
                cout<<"column full, enter different column"<<endl;
                while(column < 1 || column > 7){
                    cout<<"pick a column 1-7"<<endl;
                    cin>>column;
                }
                i = 0;
            }
            if(board.at(34 + column) == ' '){
                board.at(34 + column) = player;
                break;
            }
            column = column - 7;
        }
        PrintBoard(board);
        if(player == 'X')player = 'O';
        else player = 'X';
    }

    cout<<Result(board)<<endl;
    return 0;
}
