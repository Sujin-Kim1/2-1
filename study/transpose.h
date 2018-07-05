#define MAX_COL 6

typedef struct 
{
    int row;
    int col;
    int val;
} term;

void transpose(term a[], term b[]);
void fastTranspose(term a[], term b[]);
void init(term a[]);