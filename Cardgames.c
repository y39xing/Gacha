// This is a module for creating a card game.

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Cardgames.h"
#pragma warning(disable : 4996)
#include<unistd.h> 
////////////////////////////////////////////////////////////////////////////
// constant used for rarity
const int R = 1; //1
const int SR = 2 ; //2 
const int SSR = 3;// 3
const int MAXLEN = 1024;
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
struct card game[1024] = {0};

// Never call initialize when playing
void initialize(struct card* game,int password){
    if (password == 1){
      printf("\nPlease enter password:\n");
      int ps = 0;
      scanf("%d", &ps);
    if (ps == 123456){
      for(int i = 0 ; i < MAXLEN; ++i){
        game[i].id = 0;
        game[i].rarity = 0;
      }
      printf("Initialization success\n\n");
    } else {
      printf("ERROR: Incorrect Password\n\n");       
      return;
    }
   } else {
    for(int i = 0 ; i < MAXLEN; ++i){
      game[i].id = 0;
      game[i].rarity = 0;
    }
  }
}

void add_card(struct card *game){
  assert(game);
  for(int i = 1; i < MAXLEN; ++i){
    if (game[i].id == 0){
      game[i].id = i;
      printf("\nAdd card success ==> Card ID: %04d\n",i);
      printf("Please give rarity(1 or 2 or 3):\n");
      scanf("%d",&game[i].rarity);
      printf("Please give name(< 32 letters):\n");
      scanf("%s",game[i].name);
      printf("\nAdd card success\n\n");
      break;
    }
    if (i == MAXLEN - 1){
      printf("\nAdd card ERROR: MAXLEN is reached\n\n");
      break;
    }
  }
}

void change_card(struct card *game){
  assert(game);
  int id = -1;
  printf("\nPlease enter id:\n");
  scanf("%d",&id);
 if(id <= 0 || id >= 1024){
    printf("ERROR: Card not found\n\n");
    return;
  }
  if (game[id].id == 0){
    printf("ERROR: Card uncreated ==> Card ID: %04d\n",id);
  } else {
    printf("Card Overwriting Starts ==> Card ID: %04d\n",id);
    printf("Please give rarity(1 or 2 or 3):\n");
    scanf("%d",&game[id].rarity);
    printf("Please give name(< 32 letters):\n");
    scanf("%s",game[id].name);
    printf("\nChange card success\n\n");
  }
}

void print_card(struct card *game){
  assert(game);
  printf("\nPlease enter card id:\n");
  int id = -1;
  scanf("%d",&id);
  if(id <= 0 || id >= 1024){
    printf("ERROR: Card not found\n\n");
    return;
  }
  if(game[id].id == 0){
    printf("ERROR: Card not found\n\n");
  } else {
    printf("ID %04d:    ",id);
    if(game[id].rarity == R){
      printf("R      ");
    } else if(game[id].rarity == SR){
      printf("SR     ");
    } else if(game[id].rarity == SSR){
      printf("SSR    ");
    }
    printf("%s\n",game[id].name);
  }
} 

void print_list(struct card *game){
  printf("\n");
  for(int i = 1; i < MAXLEN; ++i){
    if (game[i].id == 0){
      printf("       End of card list\n\n");
      break;
    } else {
      printf("ID %04d:    ",i);
      if(game[i].rarity == R){
        printf("R      ");
      } else if(game[i].rarity == SR){
        printf("SR     ");
      } else if(game[i].rarity == SSR){
        printf("SSR    ");
      }
      printf("%s\n",game[i].name);
    }
  }
}
void save_list(){
  FILE *fp;
  fp = fopen("game","w");
  for(int i = 1; i < MAXLEN; ++i){
    if (game[i].id == 0){
      fprintf(fp,"END\n");
      break;
    } else {
      fprintf(fp,"ID %d    ",i);
      if(game[i].rarity == R){
        fprintf(fp,"R      ");
      } else if(game[i].rarity == SR){
        fprintf(fp,"SR     ");
      } else if(game[i].rarity == SSR){
        fprintf(fp,"SSR    ");
      }
      fprintf(fp,"%s\n",game[i].name);
    }
  }
  printf("\nSave Success\n\n");
}

void load_list(){
  initialize(game,0);
  FILE *fp;
  fp = fopen("game","r");
  while(1){
    char temp[32];
    fscanf(fp,"%s",temp);
    if (strcmp(temp,"END") ==0){
      break;
    }
    if (strcmp(temp,"ID") ==0){
      int id = -1;
      char rarity[4];
      char name[32];
      fscanf(fp,"%d",&id);
      fscanf(fp,"%s",rarity);
      fscanf(fp,"%s",name);
      game[id].id = id;
      if(strcmp(rarity,"R") ==0){
        game[id].rarity = R;
      } else if(strcmp(rarity,"SR") ==0){
        game[id].rarity = SR;
      } else if(strcmp(rarity,"SSR") ==0){
        game[id].rarity = SSR;
      }
      strcpy(game[id].name,name);
    }
  }
}

  