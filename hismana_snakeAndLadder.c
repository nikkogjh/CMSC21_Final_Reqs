/* 
Snake and Ladder by Nikko Gabriel J. Hismaña
-two players, one dice to roll
-displays 10x10 grid
-No input apart from pressing enter to roll dice
-bounce back rule: if player rolls beyond 100, they return, based on: https://www.ymimports.com/pages/how-to-play-snakes-and-ladders
-snake and ladders positions based on this photo: https://st.depositphotos.com/1508955/4164/v/950/depositphotos_41642213-stock-illustration-snakes-and-ladders-board-game.jpg
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// FUNCTION DECLARATION:
int rollDice(); // Dice Roll number randomizer function - randomly produce number bet 1-6
void displayBoard(); // Displays the board after each dice roll
char * showPosition(); // Prints out the position on the board
int movePlayer(); // Moves player position, checks if they land on a snake or a ladder

// MAIN FUNCTION:
int main() {


    //two players, stores their board position in array
    int player[2] ={0,0}; 
    int i = 0; //iteration variable for taking turns bet player 1 and 2

    // flag for winner, to exit do-while loop
    int 
    winner = 0;

    // snake and ladders board numbers as array
    int board[100] = {10,9,8,7,6,5,4,3,2,1,11,12,13,14,15,16,17,18,19,20,30,29,28,27,26,25,24,23,22,21,31,32,33,34,35,36,37,38,39,40,50,49,48,47,46,45,44,43,42,41,51,52,53,54,55,56,57,58,59,60,70,69,68,67,66,65,64,63,62,61,71,72,73,74,75,76,77,78,79,80,90,89,88,87,86,85,84,83,82,81,91,92,93,94,95,96,97,98,99,100,}; 

    displayBoard(board,player);

    do {
        
        printf("Player %d turn! Press enter to roll dice!", i+1);
        getc(stdin); 

        int roll = rollDice();

        // computes player position
        player[i] = player[i] + roll; 
        printf("Player %d rolled a %d!\n", i+1, roll);

        //moves the player in the board, and uses movePlayer function to check if landing on snake or ladder
        player[i] = movePlayer(player[i]); 

        //bounce back if rolls beyond 100
        if (player[i] > 100) {
            player[i] = player[i] - roll;
            printf("OVERSHOOT! Player %d is still in position %d!\n", i+1, player[i]);
            displayBoard(board,player);
        } else if (player[i] < 100) {
            printf("Player %d is now in position %d!\n", i+1, player[i]);
            displayBoard(board,player);
        } else if (player[i] == 100) {
            printf("Player %d is now in position 100!\n", i+1);
            displayBoard(board,player);
            winner = 1;
        }
        i++; // swap to player 2

        // after player 2 turn (when i = 3), swap back to player 1
        if (i+1>2) { 
            i = 0;
        }
    } while(winner != 1); // play game until game is not yet over, and no winner yet

    //announce winner
    if (player[0] == 100) {
        printf("PLAYER 1 (X) WINS!\n");
        player[0] = 100;
        displayBoard(board,player);
    } else if (player[1] == 100) {
        printf("PLAYER 2 (O) WINS!\n");
        player[0] = 100;
        displayBoard(board,player);
    }
    printf(" ========= END OF GAME! ========= ");
    getc(stdin); //bugfix: to avoid closing window as soon as winner is announced
    return 0;
}


// FUNCTION DEFINITIONS

void displayBoard(int board[], int player[]) {

    printf("=======================================================================\n ");
    printf("\t\t\tSnakes and Ladders\n");
    printf("=======================================================================\n ");

    for(int i=99; i >= 0; i--) { // iteration is 99 since board[99]=100
        if(i%10 == 0){ //prints new line when divisible by 10 iteration reached
            printf("| %4s |\n", showPosition(board[i],player)); // %4s to have a padding of
            printf("=======================================================================\n");
        } else {
            printf("| %4s ", showPosition(board[i],player));
        }
    }

    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    
    printf("Snakes:\n");
    printf("98 to 79, 95 to 75, 93 to 73, 87 to 36\n");
    printf("64 to 60, 62 to 19, 54 to 34, 17 to 7\n");
    printf("\n");
    printf("Ladders:\n");
    printf("88 to 99, 72 to 91, 51 to 67, 28 to 84\n");
    printf("21 to 42, 9 to 31, 4 to 14, 1 to 38\n\n");
}

int rollDice() {
    return rand() % 6 + 1; // modulo 6 to get (0-5), then +1 to get (1-6)
}

char * showPosition(int boardPosition, int playerPosition []) {
    //mark  player 1 and player 2 on same board position
    if(playerPosition[0] == boardPosition && playerPosition[1] == boardPosition){
        return "XO";
    }
    //mark player 1 position
    if(playerPosition[0] == boardPosition){
        return "X";
    }    
    //mark player 2 position
    if(playerPosition[1] == boardPosition){
        return "O";
    }
    char buffer[20]; // buffer array to store converted string for itoa() function
    return itoa(boardPosition,buffer,10); // bugfix: type-casting function: convert int to str
}


int movePlayer(int player){
    //bugfix: changed from Switch to if statements
    //LADDERS
    if(player == 1){
        player = 38;
        printf("Landed on ladder, climb from 1 to 38!\n");
    }
    if(player == 4){
        player = 14;
        printf("Landed on ladder, climb from 4 to 14!\n");
    }
    if(player == 9){
        player = 31;
        printf("Landed on ladder, climb from 9 to 31!\n");
    }
    if(player == 21){
        player = 42;
        printf("Landed on ladder, climb from 21 to 42!\n");
    }
    if(player == 28){
        player = 84;
        printf("Landed on ladder, climb from 28 to 84!\n");
    }
    if(player == 51){
        player = 67;
        printf("Landed on ladder, climb from 51 to 67!\n");
    }
    if(player == 72){
        player = 91;
        printf("Landed on ladder, climb from 72 to 91!\n");
    }
    if(player == 88){
        player = 99;
        printf("Landed on ladder, climb from 88 to 99!\n");
    }
    //SNAKES
    if(player == 98){
        player = 79;
        printf("Landed on snake! Drop from 98 to 79!\n");
    }
    if(player == 95){
        player = 75;
        printf("Landed on snake! Drop from 95 to 75!\n");
    }
    if(player == 93){
        player = 73;
        printf("Landed on snake! Drop from 93 to 73!\n");
    }
    if(player == 87){
        player = 36;
        printf("Landed on snake! Drop from 87 to 36!\n");
    }
    if(player == 64){
        player = 60;
        printf("Landed on snake! Drop from 64 to 60!\n");
    }
    if(player == 62){
        player = 19;
        printf("Landed on snake! Drop from 62 to 19!\n");
    }
    if(player == 54){
        player = 34;
        printf("Landed on snake! Drop from 54 to 34!\n");
    }
    if(player == 17){
        player = 7;
        printf("Landed on snake! Drop from 17 to 7!\n");
    }
    return player;
}