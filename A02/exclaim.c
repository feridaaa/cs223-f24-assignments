#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int i, random;
  char word[32];
  char replace[4] = {'@', '!', '#', '*'};

  printf("Enter a word: ");
  scanf("%s", word);

  for(i = 0; i < strlen(word); i++) {
    if(word[i] >= 97 && word[i] <= 122) {  // 97 = 'a' and 122 = 'z'; checks for lowercase
      random = rand() % 4;   
      word[i] = replace[random];
    }  
  }

  printf("OMG! %s\n", word);

  return 0;
}
