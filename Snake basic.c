//Copyright © 2021 x_n.All Rights Reserved
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include<string.h>
#include"tcs.h"
int main()
{
    int k = 0;
    char userinput;
    do
    {
        float delay;
        float c;
        c = (row < col) ? row : col;
        delay = c * 5;
        system("cls");
        HideCursor();
        srand(time(0));
        int x, y;
        int nowx, nowy;
        int xtoward, ytoward;
        int bodylong = 1;
        char a[row][col];
        int b[row][col] = { 0 };
        resetnumber(a);
        getandwrightbodyposition(&x, &y, a);
        nowx = x; nowy = y;
        Node* p = (Node*)malloc(sizeof(Node));
        a[nowx][nowy] = body;
        p->string = &a[nowx][nowy];
        p->next = NULL;
        p->prev = NULL;
        Node* head = p;
        Node* last = p;
        b[nowx][nowy] = 1;
        p->cheeckbody = &b[nowx][nowy];
        firsttoward(&xtoward, &ytoward, nowx, nowy, a);
        getandwrightbodyposition(&x, &y, a);
        int f = 0;
        while (f == 0)
        {
            if (_kbhit())
            {
                userinput = getch();
                userinput = getch();
                chosetoward(userinput, &xtoward, &ytoward);
            }
            if (bodylong == (row - 2) * (col - 2))
                f = 1;
            else if (a[nowx + xtoward][nowy + ytoward] == jie)
                f = -1;
            else if (b[nowx + xtoward][nowy + ytoward] == 1)
                f = -1;
            else
            {
                if (a[nowx + xtoward][nowy + ytoward] == kong)
                {
                    nowx += xtoward; nowy += ytoward;
                    a[nowx][nowy] = *(head->string);
                    b[nowx][nowy] = 1;
                    Node* p = (Node*)malloc(sizeof(Node));
                    p->string = &a[nowx][nowy];
                    p->cheeckbody = &b[nowx][nowy];
                    p->next = head;
                    p->prev = NULL;
                    head->prev = p;
                    head = p;
                    Node* q = (Node*)malloc(sizeof(Node));
                    q = last;
                    *(last->string) = kong;
                    *(last->cheeckbody) = 0;
                    last = q->prev;
                    free(q);
                }
                else if (a[nowx + xtoward][nowy + ytoward] == body)
                {
                    nowx += xtoward; nowy += ytoward;
                    b[nowx][nowy] = 1;
                    Node* p = (Node*)malloc(sizeof(Node));
                    p->string = &a[nowx][nowy];
                    p->cheeckbody = &b[nowx][nowy];
                    p->next = head;
                    head->prev = p;
                    head = p;
                    if (delay > c / 2 * 5)delay -= (c * 5 - c / 2 * 5) / ((row - 2) * (col - 2) / 15);
                    bodylong++;
                    getandwrightbodyposition(&x, &y, a);
                }
            }
            redraw(a);
            Sleep(delay);
            printf("your score：%d", bodylong);
        }
        if (!k++)printf("\n使用键盘方向键（“←”，“→”，“↑”，“↓”）控制蛇身，其余任意键暂停/开始，不可碰壁、自身");
        printf("\n%s", f == 1 ? "you win" : "you died");
        printf("\n输入数字0后重新开始：");
        userinput = getch();
    } while (userinput == '0');
    return 0;
}
