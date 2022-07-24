typedef struct{
    int i;
    int j;
}Index;
typedef struct Tabs{
    double data;
    Index ref;
    struct Tabs *next;
    struct Tabs *prev;
}Tab;
typedef struct{
    Tab *start;
    Tab *end;
    int countX;
    int countY;
    int count;
}matrix;

#define _Tab_         Tab *
#define _Ref_         matrix *
#define all               1
#define diag            0

const char *rows = "-rows";
const char *cols = "-cols";


extern double trace(matrix );
extern int equal(matrix , matrix );
extern void dim(matrix matrice, int row, int col);
extern matrix copy(matrix );
extern matrix screen(matrix matrice, int row, int col);
extern double deter(matrix );
extern void append(matrix matrice, double data, int i, int j);
extern void add(matrix matrice,  int row, ...);
extern void print(matrix );