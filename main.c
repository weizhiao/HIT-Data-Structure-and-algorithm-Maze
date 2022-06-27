#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void Move(int* i, int* j, int n);
void Getmaze(int map[13][17], STACK S);
void InitializeMatrix(int map1[13][17], int map0[11][15]);

int main()
{
    STACK S = MakeNull();
    int map0[11][15] =
    {
        0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,
        1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,
        0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,
        1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,
        1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,
        0,0,1,1,0,1,1,1,0,1,0,0,1,1,1,
        0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,
        0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,
        1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,
        0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,
        0,1,0,0,1,1,1,1,1,0,1,1,1,1,1
    };
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%d ", map0[i][j]);
        }
        printf("\n");
    }
    int map1[13][17];
    InitializeMatrix(map1, map0);
    Getmaze(map1, S);
    ReverseStack(S);
    printf("(i,j)\n");
    PrintStack(S);
    printf("(11,15)\n");
    system("pause");
    return 0;
}

void Move(int* i, int* j, int v)
{
    switch (v)
    {
    case 1:
        (*j)++;
        break;
    case 2:
        (*i)++;
        (*j)++;
        break;
    case 3:
        (*i)++;
        break;
    case 4:
        (*i)++;
        (*j)--;
        break;
    case 5:
        (*j)--;
        break;
    case 6:
        (*i)--;
        (*j)--;
        break;
    case 7:
        (*i)--;
        break;
    case 8:
        (*i)--;
        (*j)++;
        break;
    }
}

void InitializeMatrix(int map1[13][17], int map0[11][15])
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            map1[i][j] = 1;
        }
    }
    for (int i = 1; i < 12; i++)
    {
        for (int j = 1; j < 16; j++)
        {
            map1[i][j] = map0[i - 1][j - 1];
        }
    }
}

void Getmaze(int map[13][17], STACK S)
{
    int mark[13][17];
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            mark[i][j] = 0;
        }
    }
    int i = 1, j = 1;
    int v = 1;
    while (1)
    {
        if (i == 11 && j == 15)
        {
            printf("Find maze:\n");
            break;
        }
        Push(S, i, j, v);
        Move(&i, &j, v);
        if (mark[i][j] == 0 && map[i][j] == 0)
        {
            mark[i][j] = 1;
            v = 1;
        }
        else
        {
            if (v == 8)
            {
                Pop(S);
                if (S->next == NULL)
                {
                    printf("Can't find maze\n");
                    break;
                }
                i = S->next->i;
                j = S->next->j;
                v = S->next->v + 1;
                Pop(S);
            }
            else
            {
                i = S->next->i;
                j = S->next->j;
                Pop(S);
                v++;
            }
        }
    }
}
