/*----------------------------------------------
 * Author: Ferida Mohammed
 * Date: 9/27/24
 * Description: This program allows users to easily access the most danceable songs.
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct song {
  char title[32];
  char artist[32];
  int duration[2];
  float danceability;
  float energy;
  float tempo;
  float valence;
} song;

typedef struct node {
  song item;
  struct node* next;
} node;


void print_song(node* head) {

  int i = 0;
  for (node* n = head; n!= NULL; n = n->next) {
    printf("%d) %-25s      %-15s      (%d:%02d)     danceability: %-8.03f  E: %-8.03f  T: %-10.03f V: %.03f\n", 
      i, n->item.title, n->item.artist, n->item.duration[0], n->item.duration[1], n->item.danceability,
        n->item.energy, n->item.tempo, n->item.valence);
    i++;
  }
  printf("=============================================\n");
  printf("Dataset contains %d songs\n", i);
}


node* insert_front(song item, node* head) {                 // insert node at the beginning of linked list
  node* new_node = malloc(sizeof(node));
  if (new_node == NULL) {
    printf("Out of memory!\n");
    exit(1);
  }
  new_node->item = item;
  new_node->next = head;
  
  return new_node;

}

node* remove_node(node* head) {
  node* temp;
  float max = head->item.danceability;
  for (node* n = head->next; n!= NULL; n = n->next) {               // find maximum danceability
    if (n->item.danceability > max) {
      max = n->item.danceability;
    }
  }

  if (head->item.danceability == max) {                           // if the head is the song with max danceability

    printf(" %-25s      %-15s      (%d:%02d)     danceability: %-8.03f  E: %-8.03f  T: %-10.03f V: %.03f\n", 
        head->item.title, head->item.artist, head->item.duration[0], head->item.duration[1], head->item.danceability,
        head->item.energy, head->item.tempo, head->item.valence);

    temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  else {
    for (node* n = head; n->next!= NULL; n = n->next) {           // find the song with the max danceability & remove it
      temp = n->next;
      if (temp->item.danceability == max) {
        printf(" %-25s      %-15s      (%d:%02d)     danceability: %-8.03f  E: %-8.03f  T: %-10.03f V: %.03f\n", 
        temp->item.title, temp->item.artist, temp->item.duration[0], temp->item.duration[1], temp->item.danceability,
        temp->item.energy, temp->item.tempo, temp->item.valence);

        n->next = temp->next;
        free(temp);
        break;
      }   
    }
    return head;
  }
  
}

void clear_list(node* head) {                           // delete and free all nodes
  node* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}


int main() {
  int time;
  char input;
  char line[128];
  song temp;
  FILE *songlist;
  songlist = fopen("songlist.csv", "r");                  // open and read the csv file
  if(songlist == NULL) {
    printf("Error: unable to open file.\n");
    return 1;
  }

  
  fgets(line, sizeof(line), songlist);          //skips the second line in the file
  
  node* head = NULL; 
  while (fgets(line, sizeof(line), songlist)) {         // read all the songs into a linked list

    strcpy(temp.title, strtok(line, ","));
    strcpy(temp.artist, strtok(NULL, ","));

    time = atoi(strtok(NULL, ","));                   //time in ms
    temp.duration[0] = time/60000;             // the minutes in the time
    temp.duration[1] = (time % 60000)/1000;    //  the seconds in the time

    temp.danceability = atof(strtok(NULL, ","));
    temp.energy = atof(strtok(NULL, ","));
    temp.tempo = atof(strtok(NULL, ","));
    temp.valence = atof(strtok(NULL, ","));

    
    head = insert_front(temp, head);

    
  }
  fclose(songlist);                           // close the file

  print_song(head);

  while( 1 ) {
    printf("Press 'd' to show the most danceable song (any other key to quit): ");
    scanf(" %c", &input);
    if (input == 'd') {
      if (head != NULL) {
        printf("========================= Most danceable ==============================\n");
        head = remove_node(head);
        printf("========================================================================\n");
        print_song(head);
      }
      else {
        printf("Dataset contains 0 songs\n");
      }
    }
    else {
      clear_list(head);
      head = NULL;
      break;
    }
  }
  
  
  return 0;
}

