// -- PzDE* --
extern double PzDECenterX;
extern double PzDECenterY;
extern int PzDESeOff;
extern int PzDEEffectOff;
extern int PzDEEraseCount;
extern int PzDEJEraseCount;
extern int PzDEDeadXList[MAP_X_BOUND * MAP_Y_BOUND];
extern int PzDEDeadYList[MAP_X_BOUND * MAP_Y_BOUND];
extern int PzDEDeadColorList[MAP_X_BOUND * MAP_Y_BOUND];
extern int PzDEDeadCnt;
// ----
void PzEx_DoErase(Map_t *m);

void PzMain(void);

// -- �� --
#define RESRC_BGM_3DAYS "Puzzle\\��\\3days.mp3"
#define RESRC_BGM_TEIEN "Puzzle\\��\\BGM_�i���F�ܐF_�뉀.mp3"
#define RESRC_BGM_CAFE  "Puzzle\\��\\cafe.mp3"
#define RESRC_BGM_STORY "Puzzle\\��\\cover_story.mp3"      // -> D
#define RESRC_BGM_DANCE "Puzzle\\��\\dance_in_the_sky.mp3" // -> D
#define RESRC_BGM_EVE   "Puzzle\\��\\eve.mp3"
#define RESRC_BGM_SHIKI "Puzzle\\��\\k_sikisai.mp3"
#define RESRC_BGM_MITSU "Puzzle\\��\\mitukoi.mp3"
#define RESRC_BGM_POLP  "Puzzle\\��\\polp.mp3"
#define RESRC_BGM_SUI   "Puzzle\\��\\suikyou.mp3" // -> D
#define RESRC_BGM_D     "Puzzle\\��\\d.mp3"
#define RESRC_BGM_NIISAN "Puzzle\\��\\�`���C�ƃ\�R�s���ςȌZ����.mp3"
// ----

int PzutlGetTakasa(Map_t *m, int x);
int PzutlGetTakasaMin(Map_t *m);
