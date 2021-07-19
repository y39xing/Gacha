//////////////////////////////////////////////////////////////////////////
extern const int R; //1
extern const int SR; //2 
extern const int SSR;// 3
extern struct card game[1024];
extern const int MAXLEN;
///////////////////////////////////////////////////////////////////////////
extern const int R_prob;
extern const int SR_prob;
extern const int SSR_prob;
//////////////////////////////////////
struct cardpool *cardpool_create(void);
int random_number(void);
int find(struct card *game,int order, int rarity);
void oneroll(struct cardpool *pool);
void tenroll(struct cardpool *pool);
