#define MAX 2

typedef struct {
    char *name;
    char *phone;
    char *address;
} Nasabah;

typedef struct sQeueu {
    int head;
    int tail;
    Nasabah data[MAX];
} Queue;

void initQueue(Queue *queue);
void inputData(Nasabah *nasabah);
void showProfile(Nasabah *nasabah);
void DisplayNasabah(Queue *queue);

int isFull(Queue *queue);
int isEmpty(Queue *queue);
int isOneElement(Queue *queue);
int NasabahQueue(Queue *q, Nasabah *data);
int NasabahDequeue(Queue *queue);
