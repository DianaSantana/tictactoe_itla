
#include <stdio.h>
#include <stdlib.h>
char table[3][3];
char actualPlayer = 'X';
void initialize(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            table[i][j] = '_';
        }
    }
}
bool thereWinner(){
    //horizontal
    char playerFound = table[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(table[i][j] =='_'){
                break;
            }
            if(playerFound != table[i][j]){    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            if(table[i][j] == '_'){
                return false;
            }
        }
    }
                break;
            }
            playerFound = table[i][j];
            if(j == 2){
                printf("The winner is %c", playerFound);
                return true;
            }
        }
    }
    //vertical
    playerFound = table[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(table[j][i] =='_'){
                break;
            }
            if(playerFound != table[j][i]){
                break;
            }
            playerFound = table[j][i];
            if(j == 2){
                printf("The winner is %c", playerFound);
                return true;
            }
        }
    }
    // Diagonal from left to right
    playerFound = table[0][0];
    for(int i=0; i<3; i++){
        if(table[i][i] =='_'){
            break;
        }
        if(playerFound != table[i][i]){
                break;
        }
        playerFound = table[i][i];
        if(i == 2){
            printf("The winner is %c", playerFound);
            return true;
        }
    }
    //diagonal from right to left
    playerFound = table[0][2];
    for(int i=2; i>=0; i--){
        if(table[2-i][i] =='_'){
            break;
        }
        if(playerFound != table[2-i][i]){
                break;
        }
        playerFound = table[2-i][i];
        if(i == 0){
            printf("The winner is %c", playerFound);
            return true;
        }
    }
    return false;
}
void displayBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c\t", table[i][j]);
        }
        printf("\n");
    }
}bool thereTie(){
    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            if(table[i][j] == '_'){
                return false;
            }
        }
    }
    printf("A tie \n");
    return true;
}

int main(){
    initialize();
    while(!thereWinner() && !thereTie()){
        displayBoard();
        int row = 0;
        int column = 0;
        printf("In what row you want to play %c: ", actualPlayer);
        scanf("%d", &row);
        printf("In what column you want to play %c: ", actualPlayer);
        scanf("%d", &column);
        if(table[row][column] != '_'){
            printf("That box is already taken, try again\n");
        }else{
            table[row][column] = actualPlayer;
            if(actualPlayer == 'X'){
                actualPlayer = 'O';
            }else{
                actualPlayer = 'X';
            }
        }
    }
    printf("\n");
    displayBoard();
    printf("\n");
    system("pause");
}
