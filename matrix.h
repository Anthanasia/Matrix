#ifndef complex
#define complex
#endif

typedef struct{
    int i;
    int j;
}Index;

typedef union{
    double reel;
    float variant;
    int entier;
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

