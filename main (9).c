#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAP_SIZE 19

typedef enum {//---set the things might appear in the cell(use enum is better than int,althought it got limit, but is more clear)
    EMPTY,PLAYER,PIECES,METEOR//---The space cell,the player itself, and the pieces, and now?we got meteor
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
                case METEOR: printf("O "); break;//---so . is equal to pieces
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
//----------for summon METEOR
void placeMeteors(int count) {
    int placed = 0;
    while (placed < count) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        if (map[y][x].type == EMPTY) {
            map[y][x].type = METEOR;
            placed++;
        }
    }
}
//-----------the player's movement
void playermovement(int *score, int *totalpieces, int *fuel){//---still trying
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
    (*fuel)--; 
    printf("Remaining fuel: %d\n", *fuel);
    if (*fuel <= 0) {
        printf("Unfortunately, you ran out of fuel, now you'll be missing into the deep space\n");
        exit(0);
    }
if (map[newY][newX].type == PIECES) {//----if the pieces is touched by the player, add the score and show how many scores you still need 
        (*score)++;
         (*fuel)+=7; 
        printf("You collected a pieces, and your fuel rechared (%d/%d)\n, Fuel +7\n", *score, *totalpieces);//--print your current score
    }
    if (map[newY][newX].type == METEOR) {//----if the meteor is touched by the player, the fuel decrease 
         (*fuel)-=5; 
        printf("Welp. you got hit by the meteor, Fuel -5\n");//--print to warn the player they got hit
    }



//---for moving the player
    if (map[playerPos.y][playerPos.x].type == PLAYER) {//---if the player is on the current position
    map[playerPos.y][playerPos.x].type = EMPTY;//----set the original coordinate that player stayed back to EMPTY after the player move
}
    playerPos.x = newX;//---allow player to move left and right(to update the coordinate)
    playerPos.y = newY;//---allow player to move up and down(to update the coordinate)
   if (map[newY][newX].type != METEOR) {
    map[newY][newX].type = PLAYER;
}//---to locate the current position of the player and replace the original spot with the player, but if it's meteor, it won't be replace 
}
int main() {
    int totalmeteor;
    int totalpieces;//----set the totalpieces 
    int choice;//--- set the choice
    int fuel = 20;//---set the "steps the user allow to move"

printf("Please select a difficulty:\n");//---ask user to enter the value to decide which mode they want to 
printf("1. Easy (40 pieces/less meteor)\n");//--tell the user the easy mode is equal to 40 pieces
printf("2. Normal (30 pieces/more meteor)\n");;//--tell the user the normal mode is equal to 30 pieces
printf("3. Hard (20 pieces/you gonna get crash by the neteor)\n");;//--tell the user the hard mode is equal to 20 pieces
printf("4. Custom (your own number)\n");//---user can input the pieces they want if they enter 4(Custom)
printf("Enter your choice: ");//--------Enter the choice of mode
scanf("%d", &choice);

switch (choice) {//----use the switch to set the cases for us to change the mode
    case 1://---1 = case 1, which is the easy mode 
        totalpieces = 40;
        totalmeteor = 5;
        break;
    case 2://---2 = case 2, which is the normal mode 
        totalpieces = 30;
        totalmeteor = 10;
        break;
    case 3://---3 = case 3, which is the hard mode 
        totalpieces = 20;
        totalmeteor = 15;
        break;
    case 4://------4 = case 4, which is the custom mode
        printf("How many pieces do you want to collect?: ");//---ask the user to enter the amount of the pieces
        scanf("%d", &totalpieces);//----scan the number of the pieces user enter
        printf("And how dangerous this area is?(the number of the meteor:");
        scanf("%d", &totalmeteor);
        break;
    default:
        printf("nah, I don’t recognize that choice, so I’ll just default to Normal.\n");//---if the user entered a number which is not provided, set it into normal mode
        totalpieces = 30;
        totalmeteor = 10;
}
    
    int score = 0;//---set the basic score, which is from zero
    int *ptr_totalpieces = &totalpieces;//---to set the pieces player input is equal to the pieces we need to collect
    srand(time(NULL)); //---to make sure the object is ramdonly summond 
    setMap();
    placePlayer();
    placePIECES(totalpieces);//-------to set the number of the pieces
    placeMeteors(totalmeteor);
    while(score < *ptr_totalpieces){
    printMap();
    playermovement(&score, ptr_totalpieces, &fuel);
    }
    printf("---------------------------------------\n");
    printf("good job, you've collected your Pieces\n");
    printf("Congratulations, You collected all the pieces (%d)\n", *ptr_totalpieces);
    printf("---------------------------------------\n");
    return 0;
}
