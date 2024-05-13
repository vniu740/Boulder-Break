#include <stdio.h>

#define CAVE_SIZE 10

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]) {
  #define CAVE_SIZE 10  
    for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {

            if(cave[i][j] == 1) {
                printf("#");
                if (j == CAVE_SIZE - 1) {
                    printf("\n");
                }
            } else if (cave[i][j] == 0) {
                printf(" ");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}
            } else if (cave[i][j] == 'E') {
				printf(" ");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}
			}
        }
    }
}

int main(void) {

int cave[CAVE_SIZE][CAVE_SIZE] = {
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};
PrintCave(cave);


}