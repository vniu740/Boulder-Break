#include <stdio.h>

#define CAVE_SIZE 10

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout) {  

    int counter = 0;

    for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
            cave[i][j] = layout[counter];
            counter++;
        }
    }
}

int main(void) {

    char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0}; 
    InitialiseCave(cave, layout);

    for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
            printf("%c", cave[i][j]);
        }
    }
}

