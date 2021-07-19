
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
//////////////////////////////////////////////////////////////////////////
extern const int R; //1
extern const int SR; //2 
extern const int SSR;// 3
extern struct card game[1024];
extern const int MAXLEN;
///////////////////////////////////////////////////////////////////////////
const int R_prob = 79;
const int SR_prob = 18;
const int SSR_prob = 3;

struct cardpool{
  int max_id;
  int rarity[3];
  int up[4];
};

struct cardpool *cardpool_create(void){
  load_list();
  int max = 0;
  int R_C = 0;
  int SR_C = 0;
  int SSR_C = 0;
  for(int i = 1;i < MAXLEN; ++i){
    if (game[i].id == 0){
      max = i - 1;
      break;
    }
    if (game[i].rarity == R){
      ++R_C;
    } else if (game[i].rarity == SR){
      ++SR_C;
    } else if (game[i].rarity == SSR){
      ++SSR_C;
    } 
  }
  struct cardpool *pool = malloc(sizeof(struct cardpool));
  pool->max_id = max;
  pool->rarity[0] = R_C;
  pool->rarity[1] = SR_C;
  pool->rarity[2] = SSR_C;
  if(R_C == 0 || SR_C == 0 || SSR_C == 0){
    printf("ERROR: Not enough cards\n");
  }
  return pool;
}

int random_number(void) {
    int a;
    srand((unsigned)time(NULL));
    a = rand();
    return a;
}

int find(struct card *game,int order, int rarity){
  int count = 0;
  for(int i = 1; i < MAXLEN; ++i){
    if (game[i].rarity == rarity){
      ++count;
    }
    if (count == order){
      return i;
      break;
    }
    if (i == MAXLEN -1){
      printf("ERROR: Card Order Exceeds\n\n");
    }
  }
  return -1;
}

void oneroll(struct cardpool *pool){
  int number1 = random_number();
  int rarity = number1 % 100;
  sleep(1);
  int number2 = random_number();
  int result = -1;
  if (rarity <= 78){
    int order = number2 % (pool->rarity[0]) + 1;
    result =find(game,order,R);
  } else if (rarity >78 && rarity <= 96){
    int order = number2 % (pool->rarity[1]) + 1;
    result = find(game,order,SR);
  } else if (rarity >= 97){
    int order = number2 % (pool->rarity[2]) + 1;
    result = find(game,order,SSR);
  }
  int id = result;
  if(id <= 0 || id >= 1024){
    printf("ERROR: Card not found\n\n");
    return;
  }
  if(game[id].id == 0){
    printf("ERROR: Card not found\n\n");
  } else {
    printf("    ");
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

void tenroll(struct cardpool *pool){
  for(int i = 1; i <= 9; ++i){
    oneroll(pool);
  }
  int number1 = random_number();
  int rarity = number1 % 100;
  sleep(1);
  int number2 = random_number();
  int result = -1;
 if ( rarity <= 96){
    int order = number2 % (pool->rarity[1]) + 1;
    result = find(game,order,SR);
  } else if (rarity >= 97){
    int order = number2 % (pool->rarity[2]) + 1;
    result = find(game,order,SSR);
  }
  int id = result;
  if(id <= 0 || id >= 1024){
    printf("ERROR: Card not found\n\n");
    return;
  }
  if(game[id].id == 0){
    printf("ERROR: Card not found\n\n");
  } else {
    printf("    ");
  if(game[id].rarity == SR){
      printf("SR     ");
    } else if(game[id].rarity == SSR){
      printf("SSR    ");
    }
    printf("%s\n",game[id].name);
  }
}
