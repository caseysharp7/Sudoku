//
//  main.cpp
//  Sudoku
//
//  Created by Casey Sharp on 6/8/23.
//
#include <iostream>
#include <cstdlib>
#include <time.h>
char board[4][4] = {{'a', 'b', 'c', 'd'}, {'e', 'f', 'g', 'h'}, {'i', 'j', 'k', 'l'}, {'m', 'n', 'o', 'p'}};
int moveRow = 0;
int moveColumn = 0;
char moveNum = '1';
void showBoard(){
    std::cout << " ______ ______ \n";
    std::cout << "| " << board[0][0] << "  " << board[0][1] << " | " << board[0][2] << "  " << board[0][3] << " |\n";
    std::cout << "| " << board[1][0] << "  " << board[1][1] << " | " << board[1][2] << "  " << board[1][3] << " |\n";
    std::cout << " ______ ______ \n";
    std::cout << "| " << board[2][0] << "  " << board[2][1] << " | " << board[2][2] << "  " << board[2][3] << " |\n";
    std::cout << "| " << board[3][0] << "  " << board[3][1] << " | " << board[3][2] << "  " << board[3][3] << " |\n";
    std::cout << " ______ ______ \n";
}
void randomValues(){
    srand((unsigned) time(NULL));
    for(int i = 0; i < 4; i++){
        int num1 = rand() % 4;
        int num2 = rand() % 4;
        if(i == 0){
            board[num1][num2] = '1';
        } else if(i == 1){
            while(board[num1][num2] == '1'){
                num1 = 1 + rand() % 3;
                num2 = 1 + rand() % 3;
            }
            board[num1][num2] = '2';
        } else if(i == 2){
            while((board[num1][num2] == '1') || (board[num1][num2] == '2')){
                num1 = 1 + rand() % 3;
                num2 = 2 + rand() % 2;
            }
            board[num1][num2] = '3';
        } else{
            while((board[num1][num2] == '1') || (board[num1][num2] == '2') || (board[num1][num2] == '3')){
                num1 = 2 + rand() % 2;
                num2 = 1 + rand() % 3;
            }
            board[num1][num2] = '4';
        }
    }
}
bool checkRows(){
    int count = 0;
    for(int i = 0; i < 4; i++){
        if((board[i][moveColumn] != moveNum) && (board[moveRow][i] != moveNum)){
            count++;
        }
    }
    /*if(board[0][moveColumn] != moveNum &&
       board[1][moveColumn] != moveNum &&
       board[2][moveColumn] != moveNum &&
       (board[moveRow][] != moveNum)){
            return true;
    }*/
    if(count > 3){
        return true;
    }
    
    std::cout << "Row/Column violation\n";
    return false;
}
bool checkBoxes(){
    if((moveRow <= 1) && (moveColumn <= 1) &&
       board[0][0] != moveNum &&
       board[1][0] != moveNum &&
       board[0][1] != moveNum &&
       board[1][1] != moveNum){
        return true;
    } else if((moveRow <= 1) && (moveColumn > 1) &&
              board[0][2] != moveNum &&
              board[1][2] != moveNum &&
              board[0][3] != moveNum &&
              board[1][3] != moveNum){
        return true;
    } else if((moveRow > 1) && (moveColumn <= 1) &&
              board[2][0] != moveNum &&
              board[3][0] != moveNum &&
              board[2][1] != moveNum &&
              board[3][1] != moveNum){
        return true;
    } else if((moveRow > 1) && (moveColumn > 1) &&
              board[2][2] != moveNum &&
              board[2][3] != moveNum &&
              board[3][2] != moveNum &&
              board[3][3] != moveNum){
        return true;
    }
    std::cout << "Box violation\n";
    return false;
}
void humanMove(){
    std::cin >> moveRow;
    std::cin >> moveColumn;
    std::cin >> moveNum;
    moveRow--;
    moveColumn--;
    if(checkRows() && checkBoxes()){
        board[moveRow][moveColumn] = moveNum;
    } else{
        std::cout << "Invalid move\n";
        showBoard();
        humanMove();    }
    showBoard();
}
/*void computerMove(){
    
} */
bool winCondition(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((board[i][j] == 'a') || (board[i][j] == 'b') || (board[i][j] == 'c') || (board[i][j] == 'd') || board[i][j] == 'e' || board[i][j] == 'f' || board[i][j] == 'g' || board[i][j] == 'h' || board [i][j] == 'i' || board[i][j] == 'j' || board[i][j] == 'k' || board[i][j] == 'l' || board[i][j] == 'm' || board[i][j] == 'n' || board[i][j] == 'o' || board[i][j] == 'p'){
                std::cout << "Working\n";
                return true;
            }
        }
    }
    return false;
}
int main() {
    std::cout << "Pick the row number, then the column number, then the number you want\n";
    randomValues();
    showBoard();
    while(winCondition()){
        humanMove();
    }
    std::cout << "Congrats!\n";
}

