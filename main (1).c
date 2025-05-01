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

int main() {
    srand(time(NULL)); //---to make sure the object is ramdonly summond 
    setMap();
    placePlayer();
    placePIECES(10);//-------to set the number of the pieces
    printMap();
    

    return 0;
}
