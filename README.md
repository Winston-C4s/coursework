# coursework
A space game by using C language, a 19x19 space-themed text game
1.Build a map
The map size is 19x19, and because 19 is a prime number, it has a special sense of beauty and order..(CHECKED)
Each grid is initially empty.(CHECKED)
Output map(CHECKED)
Use text boxes (such as +--+) to display each grid..(CHECKED)
2.Different elements (protagonists, items, open spaces) are represented by different symbols, for example:
Space: .
Protagonist: H
Rubbish(PIECES):E	
3.Creating the Protagonist
The protagonist is a movable character who can move around the map..(CHECKED)
Set the starting position of the main character.(CHECKED)
The protagonist starts the adventure from the center of the map (position (9, 9))..(CHECKED)
4.Implemented WASD to control the protagonist's movement.(CHECKED)
Each player enters a character to move the protagonist:.(CHECKED)
W Up
A Left
S Down
D Right
#we need to be careful to avoid moving outside the map boundaries..(CHECKED,add the limit)

5.Randomly generated items.(CHECKED)
Items (junk or pieces ) appear randomly in the map..
When the player passes by the grid, it will be automatically picked up and one point will be awarded..(CHECKED)
#Make sure items don't overlap.(CHECKED)
#The random generated position must be a blank space (it cannot be repeated on the protagonist or other items)..(CHECKED)

_________________________________________________________________________
6.Setting difficulty and victory conditions(STILL WORKING ON IT)
At the beginning, a menu is displayed for the player to choose the difficulty:
Easy: Need to pick up 5 items
Normal: 10
Difficulty: 20
7. We need to make a fuel system for explore, if the player move the amount of fuel -1(STILL WORKING)
8.Set a target score based on player’s selection.
9.Victory Message
Every time you pick up an item, update the current score.
If the target score is reached, a success message will be displayed
