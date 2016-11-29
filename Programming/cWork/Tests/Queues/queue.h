typedef struct {
    int bit_map;
    struct QNode * pNext;
} QNode;

typedef struct {
    int iCount;
    int iStartIdx;
    QNode *pHead;
} QueueImp;

typedef QueueImp* Queue;

//Queue Function Prototypes
Queue allocateQueue(int new_bit);
void addElement(Queue queue, int new_bit);
int pop(Queue queue);
void freeQueue(Queue queue);

//Debugging Function Prototypes
void printElements(Queue queue);
