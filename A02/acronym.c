#include <stdio.h>

int main() {
  int i = 0, j = 0;
  char phrase[1024];
  char acronym[100];

  printf("Enter a phrase: ");
  scanf("%[^\n]%*c", phrase);

  while(phrase[i] != '\0') {
    if(phrase[i] >= 65 && phrase[i] <= 90){
      acronym[j] = phrase[i];
      j+=1;
    }
    i+=1;
  }

  acronym[j] = '\0';
  printf("Your acronym is %s\n", acronym);

  return 0;
}

