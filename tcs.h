//Copyright © 2021 x_n.All Rights Reserved
#define  jie '#'
#define  kong ' ' 
#define  body '*'
#define  row 20
#define  col 50
void redraw(char* a);
void resetnumber(char* a);
int randnumber(int x);
int checknumberright(int x, int y, char* a);
void getandwrightbodyposition(int* x, int* y, char* a);
void chosetoward(int m, int* x, int* y);
void firsttoward(int* xtoward, int* ytoward, int nowx, int nowy, char* a);
static  void  SetPos(int  x, int  y);
void HideCursor(void);
typedef struct _node
{
    char* string;
    int* cheeckbody;
    struct _node* next;
    struct _node* prev;
}Node;
void HideCursor(void)
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
static  void  SetPos(int  x, int  y)
{
    COORD  point = { x ,  y }; 
    HANDLE  HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(HOutput, point);
}
void firsttoward(int* xtoward, int* ytoward, int nowx, int nowy, char* a)
{
    int f = 0;
    char(*p)[col] = a;
    while (f == 0)
    {
        if (rand() % 2)
        {
            *xtoward = pow(-1, rand() % 2);
            *ytoward = 0;
        }
        else
        {
            *ytoward = pow(-1, rand() % 2);
            *xtoward = 0;
        }
        if (p[nowx + *xtoward][nowy + *ytoward] == kong)
            f = 1;
    }
}
void chosetoward(int m, int* x, int* y)
{
    int xtoward = *x, ytoward = *y;
    switch (m)
    {
    case 72:xtoward = -1; ytoward = 0; break;
    case 80:xtoward = 1; ytoward = 0; break;
    case 75:xtoward = 0; ytoward = -1; break;
    case 77:xtoward = 0; ytoward = 1; break;
    }
    *x = xtoward;
    *y = ytoward;
}
void getandwrightbodyposition(int* x, int* y, char* a)
{
    char(*p)[col];
    int m;
    int n;
    p = a;
    do
    {
        m = randnumber(row - 2);
        n = randnumber(col - 2);
    } 
    while (checknumberright(m, n, p) == 1);
    p[m][n] = body;
    *x = m;
    *y = n;
}
int checknumberright(int x, int y, char* a)
{
    int re = 0;
    char(*p)[col];
    p = a;
    if (p[x][y] != kong)
        re = 1;
    return re;
}
int randnumber(int x)
{
    return rand() % x + 1;
}
void resetnumber(char* a)
{
    char(*p)[col];
    p = a;
    for (int i = 0; i <= row - 1; i++)
        for (int j = 0; j <= col - 1; j++)
            p[i][j] = kong;
    for (int i = 0; i <= col; i++)
        p[0][i] = jie;
    for (int i = 1; i <= row - 2; i++)
    {
        p[i][0] = jie;
        p[i][col - 1] = jie;
    }
    for (int i = 0; i <= col - 1; i++)
        p[row - 1][i] = jie;
}
void redraw(char* a)
{
    SetPos(0, 0);
    char(*p)[col];
    p = a;
    for (int i = 0; i <= row - 1; i++)
    {
        for (int j = 0; j <= col - 1; j++)
            printf("%c", p[i][j]);
        printf("\n");
    }
}
