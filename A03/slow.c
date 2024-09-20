/*----------------------------------------------
 * Author: Ferida Mohammed
 * Date: 9/17/2024
 * Description: This program turns a phrase into a slow speech
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int length, i, j, n;
  char text[32];
  char* slow;

  printf("Pause length: ");
  scanf("%d", &length);

  printf("Text: ");
  scanf("%s", text);

  slow = (char*) malloc(sizeof(char)*(strlen(text)*(1 + length)));
  
  j = 0;                                // used to index slow[]
  for(i = 0; i < strlen(text); i++) {
    slow[j] = text[i];
    j++;
    for (n = 0; n < length; n++){       // length of the pause
      slow[j] = '.';
      j++;
    }
  }
  slow[j] = '\0';

  printf("%s\n", slow);

  free(slow);
  return 0;
}

