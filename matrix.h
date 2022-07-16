
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
#define all           "all"
#define rows          "-rows"
#define cols          "-cols"
#define diag          "diag"
#define xy            "-xy"
