/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

// Task One: InitialiseStory
void InitialiseStory(char* paragraph) 
{
    char temp[2000] = "There was an old wives tale that behind the waterfall at the\nedge of your town was a cave filled with luxurious goodies\nthat you could live off for the rest of your life. You\ndecided to go adventuring into the cave and suddenly fell\ndeep into its depths. At the bottom you discovered there was\nindeed treasure however you were stuck! Collect the treasure\nand escape from the cave using the boulders to\nget back home!";
    strcpy(paragraph, temp);
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]) {
    
    for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {

            if(cave[i][j] == '1') {
                printf("#");
                if (j == CAVE_SIZE - 1) {
                    printf("\n");
                }
            } else if (cave[i][j] == '0') {
                printf(" ");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}
            } else if (cave[i][j] == 'E') {
				printf(" ");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}
			} else if (cave[i][j] == 'P') {
				printf("X");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}	
			} else if (cave[i][j] == 'H') {
				printf("*");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}	
			} else if (cave[i][j] == 'T') {
				printf("+");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}	
			} else if (cave[i][j] == 'B') {
				printf("O");
				if (j == CAVE_SIZE - 1) {
                    printf("\n");
				}	
			}

        }
    }
}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout) {  

    int counter = 0;

    for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
            cave[i][j] = layout[counter];
            counter++;
        }
    }
}

// TASK $
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{

int eCounter = 0;

	for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {

			if((i == 0) || (i == CAVE_SIZE - 1) || (j == 0) || (j == CAVE_SIZE - 1)) {
				
				if((cave[i][j] != '1') && (cave[i][j] != 'E')) {
					return 0;
				}
			}
		}
	}

	return 1;
}

// TASK 5
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int eCounter = 0;

	for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
		
				if(cave[i][j] == 'E') {
					 eCounter++;
				} 
		}
	}

	if(eCounter == 1) {
		return 1;
	}
	
	return 0;
}

//TASK 6
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int eRow;
	int eCol;

	for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
		
			if(cave[i][j] == 'E') {
				eRow = i;
				eCol = j;
			}
		}
	}

	if(((eRow == 0) || (eRow == CAVE_SIZE - 1)) && ((eCol > 0) && (eCol < CAVE_SIZE - 1))) {
		return 1;
	} 

	if(((eCol == 0) || (eCol == CAVE_SIZE - 1)) && ((eRow > 0) && (eRow < CAVE_SIZE - 1))) {
		return 1;
	} 

	return 0;
}

//TASK 7
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	int playerCount = 0;
	for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
			if(cave[i][j] == 'P') {
				playerCount++;
			}
		}
	} 
							
	

	if(((row >= 0) && (row <= CAVE_SIZE - 1)) && ((col >= 0) && (col <= CAVE_SIZE - 1))) {
		
		if(cave[row][col] == '0') {

			if((element[0] == 'p') && playerCount == 0) {
				cave[row][col] = 'P';
			} else if(element[0] == 'h') {
				cave[row][col] = 'H';
			} else if(element[0] == 't') {
				cave[row][col] = 'T';
			} else if(element[0] == 'b') {
				cave[row][col] = 'B';
			}

		}
	}

}

// TASK 8
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int temp[100][100] = {0};

	for (int row = 0; row < CAVE_SIZE; row++) {
		for(int col = 0; col < CAVE_SIZE; col++) {
			temp[col][CAVE_SIZE - 1 - row] = cave[row][col];
		}
	}

	for (int row = 0; row < CAVE_SIZE; row++) {
		for(int col = 0; col < CAVE_SIZE; col++) {
			cave[row][col] = temp[row][col];
		}
	}


}

// TASK 9
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{

	int turns = 0;
	int pPosRow;
	int pPosCol;
	int obstacle = 0;
	int counter;
	int returnValue;

	if(move == 'a') {
		turns = 3;
		RotateCave(cave);
	} else if (move == 's') {
		turns = 2;
		RotateCave(cave);
		RotateCave(cave);
	} else if (move == 'd') {
		turns = 1;
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
	} 

	for(int i = 0; i < CAVE_SIZE; i++) {
        for(int j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 'P') {
				pPosRow = i;
				pPosCol = j;
			}
		}
	}

	counter = pPosRow - 2;

	if(cave[pPosRow][pPosCol] != '1') {

		// if player's next move is into an empty space
		if (cave[pPosRow - 1][pPosCol] == '0') {
			cave[pPosRow][pPosCol] = '0';
			cave[pPosRow - 1][pPosCol] = 'P';
			returnValue = 0;
		}

		// if player's next move is to push a boulder.
		if (cave[pPosRow - 1][pPosCol] == 'B') {
			while (obstacle == 0) {
				
				// if boulder roles into a hole
				if(cave[counter][pPosCol] == 'H') {
					cave[pPosRow - 1][pPosCol] = '0';
					cave[counter][pPosCol] = '0';
					returnValue = 0;
					obstacle = 1;
				}

				// if wall or treasure is in boulder's path
				if((cave[counter][pPosCol] == '1') || (cave[counter][pPosCol] == 'T') ) {
					cave[counter + 1][pPosCol] = 'B';
					cave[pPosRow - 1][pPosCol] = '0';
					returnValue = 0;
					obstacle = 1;
				}

				// if boulder is in boulders path
				if (cave[counter][pPosCol] == 'B') {
					if ((cave[counter][pPosCol] == 'B') && (cave[counter + 1][pPosCol] == 'B')) {
						returnValue = 0;
						obstacle = 1;
					} else {
					cave[counter + 1][pPosCol] = 'B';
					cave[pPosRow - 1][pPosCol] = '0';
					returnValue = 0;
					obstacle = 1;
					}
				}
			counter--;
			}
		}

		// if player's next move is into a hole.
		if(cave[pPosRow - 1][pPosCol] == 'H') {
			cave[pPosRow][pPosCol] = '0';
			returnValue = 1;
		}

		// if player's next move is into the Exit
		if(cave[pPosRow - 1][pPosCol] == 'E') {
			cave[pPosRow][pPosCol] = '0';
			cave[pPosRow - 1][pPosCol] = 'P';
			returnValue = 2;
		}

		// if player's next move is onto a treasure 
		if(cave[pPosRow - 1][pPosCol] == 'T') {
			cave[pPosRow][pPosCol] = '0';
			cave[pPosRow - 1][pPosCol] = 'P';
			returnValue = 0;
		}

		// if player's next move is onto a wall
		if(cave[pPosRow - 1][pPosCol] == '1') {
			returnValue = 0;
		}
	}

	if(turns == 3) {
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);	
	} else if (turns == 2) {
		RotateCave(cave);
		RotateCave(cave);
	} else if (turns == 1) {
		RotateCave(cave);
	}

	if(returnValue == 2) {
		return 2;
	} else if(returnValue == 1) {
		return 1;
	} else if(returnValue == 0) {
		return 0;
	}

	return 0;

}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111"; 
  int cave[CAVE_SIZE][CAVE_SIZE] = {0}; 
 
  InitialiseCave(cave, layout); 
 
  AddItem(cave, 5, 5, "boulder"); 
  AddItem(cave, 5, 6, "boulder"); 
  AddItem(cave, 5, 7, "boulder"); 
  AddItem(cave, 2, 2, "player"); 
 
  printf("Original position:\n"); 
  PrintCave(cave); 
 
  printf("First rotation:\n"); 
  RotateCave(cave); 
  PrintCave(cave); 
 
  printf("Second rotation:\n"); 
  RotateCave(cave); 
  PrintCave(cave); 
 
  printf("Third rotation:\n"); 
  RotateCave(cave); 
  PrintCave(cave); 
 
  printf("Fourth rotation:\n"); 
  RotateCave(cave); 
  PrintCave(cave); 


  return 0;
}