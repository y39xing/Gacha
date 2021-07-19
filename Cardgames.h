////////////////////////////////////////////////////////////////////////////
// strcut used for the game;
// Card info:
struct card{
  int id;  // start from 1 to 1023 and card id 0 is null
  int rarity;
  char name[32];
};
// User profile;
struct user{
  int id;
  char name[16];
  int deck[1024];
  int coin;
};

////////////////////////////////////////////////////////////////////////////
// constant used for rarity
extern const int R; //1
extern const int SR; //2 
extern const int SSR;// 3
extern const int MAXLEN;
extern struct card game[1024];
///////////////////////////////////////////////////////////////////////////
void initialize(struct card* game,int password);
void add_card(struct card *game);
void change_card(struct card *game);
void print_card(struct card *game);
void print_list(struct card *game);
void save_list(void);
void load_list(void);

  
