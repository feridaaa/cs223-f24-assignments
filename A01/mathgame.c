/***************************************************
 * mathgame.c
 * Author: Ferida Mohammed 
 * Implements a math game
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int round, num1, num2, i, sum;
  int score = 0;
  
  printf("Welcome to Math Game!\n");
  printf("How many rounds do you want to play?\n");
  scanf("%d", &round);

  for (i = 0; i < round; i++){
    
    num1 = rand() % 10;
    num2 = rand() % 10;
    printf("%d + %d = ?\n", num1, num2);
    scanf("%d", &sum);

    if (sum == (num1 + num2)){
      printf("Correct!\n");
      score += 1;
    }
    else {
      printf("Incorrect :(\n");
    }
  }

  printf("You answered %d/%d correctly.\n", score, round);

  return 0;
}
