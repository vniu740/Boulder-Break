#include <stdio.h>
#include <string.h>

void InitialiseStory(char* paragraph) {
    
    char temp[2000] = "There was an old wives tale that behind the waterfall at the\nedge of your town was a cave filled with luxurious goodies\nthat you could live off for the rest of your life. You\ndecided to go adventuring into the cave and suddenly fell\ndeep into its depths. At the bottom you discovered there was\nindeed treasure however you were stuck! Collect the treasure\nand escape from the cave using the boulders to\nget back home!";
    strcpy(paragraph, temp);

}



int main(void) 
{ 
  char story[2000]; 
  InitialiseStory(story); 
  printf("%s\n", story); 
 
  return 0; 
} 