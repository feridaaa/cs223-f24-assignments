/*----------------------------------------------
 * Author: Ferida Mohammed
 * Date: 9/17/2024
 * Description: This program reads songs from a text file into an array
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


void print_song(song* songs, int size) {

  printf("Welcome to Dynamic Donna's Danceability Directory.\n");
  for (int i=0; i<size; i++) {
    printf("%d) %-25s     artist: %-15s     duration: %d:%02d     danceability: %-8.03f  E: %-8.03f  T: %-10.03f V: %.03f\n", 
      i, songs[i].title, songs[i].artist, songs[i].duration[0], songs[i].duration[1], songs[i].danceability,
        songs[i].energy, songs[i].tempo, songs[i].valence);
  }
  printf("=============================================\n");
}


int main() {
  int size, time, i;
  char line[128];
  song *song_array;
  FILE *songlist;
  songlist = fopen("songlist.csv", "r");
  if(songlist == NULL) {
    printf("Error: unable to open file.\n");
    return 1;
  }

  fgets(line, sizeof(line), songlist);
  size = atoi(strtok(line, ","));
  
  song_array = malloc(sizeof(song) * size);
  
  fgets(line, sizeof(line), songlist);          //skips the second line in the file
  
  i = 0;
  while (fgets(line, sizeof(line), songlist)) {

    strcpy(song_array[i].title, strtok(line, ","));
    strcpy(song_array[i].artist, strtok(NULL, ","));

    time = atoi(strtok(NULL, ","));                   //time in ms
    song_array[i].duration[0] = time/60000;             // the minutes in the time
    song_array[i].duration[1] = (time % 60000)/1000;    //  the seconds in the time

    song_array[i].danceability = atof(strtok(NULL, ","));
    song_array[i].energy = atof(strtok(NULL, ","));
    song_array[i].tempo = atof(strtok(NULL, ","));
    song_array[i].valence = atof(strtok(NULL, ","));

    i++;
  }
  print_song(song_array, size);

  free(song_array);
  fclose(songlist);
  return 0;
}
