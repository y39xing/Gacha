
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Cardgames.h"
#include "cardpool.h"
#include<unistd.h> 
//////////////////////////////////////////////////////
int main(void){
  struct cardpool *pool = cardpool_create();
  while(1){
    printf("Please choose function: \n");
    printf("1. 1 roll \n");
    printf("2. 10 rolls \n");
    printf("3. EXIT \n");
    int a;
    scanf("%d",&a);
    if(a == 1){
      printf("\n");
      oneroll(pool);
      printf("\n");
    } else if(a == 2) {
      printf("\n");
      tenroll(pool);
      printf("\n");
    } else if (a == 3){
      break;
    }
    if (a == 7){
      while(1){
    int command = -1;
    printf("Please choose one function(enter corresponding number):\n");
    printf("0.Initialize card pool(Password needed)\n");
    printf("1.Add a card\n");
    printf("2.Change a card\n");
    printf("3.Print a card\n");
    printf("4.Print the cardlist\n");
    printf("5.Save Cardlist\n");
    printf("6.Load Cardlist\n");
    printf("7.Exit\n");
    scanf("%d",&command);
    if (command == 0){
      initialize(game,1);
    } else if (command == 1){
      add_card(game);
    } else if (command == 2){
      change_card(game);
    } else if (command == 3){
      print_card(game);
    } else if (command == 4){
      print_list(game);
    } else if (command == 5){
      save_list();
    } else if (command == 6){
      load_list();
      printf("\nLoad Success\n\n");
    } else {
      break;
    }
  }
    }
  }
  free(pool);
}
  