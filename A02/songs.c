#include <stdio.h>
#include <string.h>

typedef struct song {
  char title[32];
  char artist[32];
  int duration[2];
  float danceability;
} song;


void print(struct song* songs, int size) {

  printf("Welcome to Steven Struct's Song List.\n");
  for (int i=0; i<size; i++) {
    printf("%d) %-20s     artist: %-20s     duration: %d:%-10d  danceability: %.02f\n", i, 
      songs[i].title, songs[i].artist, songs[i].duration[0], songs[i].duration[1], songs[i].danceability);
  }
  printf("=============================================\n");
}


int main() {

  const int array_size = 3;
  int id, time;
  char attribute[32];
  song song1, song2, song3;

  strcpy(song1.title, "Shout");
  strcpy(song1.artist, "Tears for Fears");
  song1.duration[0] = 4;
  song1.duration[1] = 11;
  song1.danceability = 0.50;

  strcpy(song2.title, "As it was");
  strcpy(song2.artist, "Harry Styles");
  song2.duration[0] = 2;
  song2.duration[1] = 47;
  song2.danceability = 0.70;

  strcpy(song3.title, "Wish you were here");
  strcpy(song3.artist, "Pink Floyd");
  song3.duration[0] = 5;
  song3.duration[1] = 34;
  song3.danceability = 0.30;

  song song_array[3] = {song1, song2, song3};

  print(song_array, array_size);
  printf("Enter a song id to edit [0,1,2]: ");
  scanf("%d", &id);

  if (id != 0 && id != 1 && id != 2) {
    printf("Invalid choice!\n");
    return 1;
  }
  else {
    printf("Which attribute do you wish to edit? [artist, title, duration, danceability]: ");
    scanf("%s", attribute);

    if(strcmp(attribute, "artist") == 0) {
      printf("Enter an artist: ");
      scanf(" %[^\n]%*c", attribute);
      strcpy(song_array[id].artist, attribute);
      print(song_array, array_size);
    }
    else if(strcmp(attribute, "title") == 0) {
      printf("Enter a title: ");
      scanf(" %[^\n]%*c", attribute);
      strcpy(song_array[id].title, attribute);
      print(song_array, array_size);
    }
    else if(strcmp(attribute, "duration") == 0) {
      printf("Enter a duration (minutes): ");
      scanf("%d", &time);
      song_array[id].duration[0] = time;
      printf("Enter a duration (seconds): ");
      scanf("%d", &time);
      song_array[id].duration[1] = time;
      print(song_array, array_size);
    }
    else if(strcmp(attribute, "danceability") == 0) {
      printf("Enter danceability: ");
      scanf("%f", &(song_array[id].danceability));
      print(song_array, array_size);     
    }
    else {
      printf("Invalid choice!\n");
      return 1;
    }
    
  }


  
  return 0;
}

