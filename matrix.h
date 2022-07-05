#ifndef complex
#define complex
#endif

typedef struct{
    int i;
    int j;
}Index;

typedef union{
    double reel;
    complex double cmplxD;
    float variant;
    complex float cmplxF;
    int entier;
    complex int cmplxI;
}Data;

typedef struct Tabs{
    Data data;
    Index ref;
    struct Tabs *next;
}Tab;

typedef struct{
    Tab *start;
    Tab *end;
    int countX;
    int countY;
    int count;
}matrix;


#define _Tab_           Tab *
#define _Ref_           matrix *

void add_i(matrix, int, int, ...);
void add_d(matrix, int, int, ...);
void add_f(matrix, int, int, ...);
void add_ic(matrix, int, int, ...);
void add_dc(matrix, int, int, ...);