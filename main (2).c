#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAP_SIZE 19

typedef enum {//---set the things might appear in the cell(use enum is better than int,althought it got limit, but is more clear)
    EMPTY,PLAYER,PIECES//---The space cell,the player itself, and the pieces
} CellType;

typedef struct {
    CellType type;
} Cell;//----to make sure each cell only contain one object, empty, player or rubbish

Cell map[MAP_SIZE][MAP_SIZE];//---set the map size is 19x19
void setMap() {//---a function of setting the Map
    for (int i = 0; i < MAP_SIZE; i++) {//--for x range 
        for (int j = 0; j < MAP_SIZE; j++) {//--for y range
            map[i][j].type = EMPTY;//--fill the x and y(i and j) with empty
        }
    }
}
//---for setting the player, pieces and the space itself
void printMap() {
    for (int i = 0; i < MAP_SIZE; i++) {//--for x range
        for (int j = 0; j < MAP_SIZE; j++) {//--for i range
            switch (map[i][j].type) {//---allow the empty to change type to player and pieces
                case EMPTY:   printf(". "); break;//---so . is equal to empty
                case PLAYER:  printf("H "); break;//---so H is equal to player
                case PIECES: printf("E "); break;//---so . is equal to pieces
            }
        }
        printf("\n");
    }
}
typedef struct {
    int x;//--set x value
    int y;//--set y value
} Position;

Position playerPos;
//------to set the player's position 
void placePlayer() {
    playerPos.x = MAP_SIZE / 2;//---to make sure the coordinate of the player spawn is at X/2 which is 19/2
    playerPos.y = MAP_SIZE / 2;//---to make sure the coordinate of the player spawn is at Y/2 which is 19/2
    map[playerPos.y][playerPos.x].type = PLAYER;//--to declear the center is for the player
}
//-------for summon pieces
void placePIECES(int count) {//--set the pieces and the number of pieces equal to count
    int placed = 0;//---default set is 0
    while (placed < count) {//--if the pieces placed is lower than count, keep placing
        int x = rand() % MAP_SIZE;//--at random range of x
        int y = rand() % MAP_SIZE;//--at random range of y
        if (map[y][x].type == EMPTY) {//---to make sure the original location is space so we can put the pieces
            map[y][x].type = PIECES;//--to check the pieces is placed 
            placed++;//---if the pieces is placed, keep placing until the number placed is equal to count 
        }
    }
}
void playermovement(int *score, int *totalpieces){//---still trying
char move;
printf("Move by using W/A/S/D:");//---tell user to enter the w/a/s/d to move the player
scanf(" %c",&move);//---scan the chatacter user entered
int newX = playerPos.x;//--set a player coordinate in x axis
int newY = playerPos.y;//--set a player coordinate in y axis
switch(move){
    case 'W': case'w':newY--; break;//-----allow the player to move up
    case 'S': case's':newY++; break;//-----allow the player to move down
    case 'A': case'a':newX--; break;//-----allow the plater to move left
    case 'D': case'd':newX++; break;//-----allow the player to move right
    default:printf("Can't move!\n");//----if the word user emter is not w/a/s/d, than print this
    return;//----back to the last stage
}
if (newX < 0 || newX >= MAP_SIZE || newY < 0 || newY >= MAP_SIZE) {//--if the player try to move outside the page
    printf("It's too dangerous for me to move outside the space\n");//---print this and move back to the last stage
    return;
}
if (map[newY][newX].type == PIECES) {//----if the pieces is touched by the player, add the score and show how many scores you still need 
        (*score)++;
        printf("You collected a pieces (%d/%d)\n", *score, *totalpieces);//--print your current score
    }
//—---------------------------for moving the player
    map[playerPos.y][playerPos.x].type = EMPTY;//----set the original coordinate that player stayed back to EMPTY
    playerPos.x = newX;//---allow player to move left and right(to update the coordinate)
    playerPos.y = newY;//---allow player to move up and down(to update the coordinate)
    map[newY][newX].type = PLAYER;//---to locate the curent position of the player 
}


int main() {
    srand(time(NULL));

    int totalPieces = 10;
    int score = 0;

    setMap();
    placePlayer();
    placePIECES(totalPieces);
    while (score < totalPieces) {
        printMap();
        playermovement(&score, &totalPieces);
    }
    printf("\n----------------------------\n");
    printf("GOOD JOB\n");
    printf("----------------------------\n");
    return 0;
}
