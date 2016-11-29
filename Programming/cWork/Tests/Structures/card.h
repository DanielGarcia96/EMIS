struct card {
    int  pips;
    char suit;
};

void deal(struct card hand[]);
void print_hand(struct card hand[]);
int isRepeat(struct card hand[], int stopIndex);
void reroll(struct card hand[], int targetIdx);
