#define    ROYAL_FLUSH    7
#define    STRAIGHT_FLUSH 6
#define    FULL_HOUSE     5 #define    FLUSH          4
#define    TWO_PAIRS      3
#define    PAIR           2
#define    HIGH_CARD      1

#define    roll()  (rand() % 52) + 1

struct card {
    int pips;
    char suit;
    char dealt;
};

typedef    struct card       card;

struct player {
    card hand[2];
    int dollars;
};

typedef    struct player     player;

struct card_list {
    card               card;
    struct card_list   *next;
};

typedef    struct card_list  card_list;

struct community {
    card_list *cards;
    int pot;
};

typedef    struct community  community;

struct deck {
    card allcards[56];
};

typedef    struct deck    deck;

void printHand(card hand[]);
void deal(card hand[]);
void addToLineUp(card *communityCards);
int roundWin(int players, ...);
void loadDeck(deck dk);
