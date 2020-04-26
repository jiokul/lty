#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void create_int(int tetn,int maxn,int digt,int barck,int lit,int file)//生成整数的题目
{
    int testnum=tetn; //题目数量
    int maxnum=maxn;//最大数
    int symbolnum[4] = { 1,2,3,4 };//运算符数
    int digitnum=digt;//题目数字个数
    int bracketflag=barck;//是否有括号
    int littleflag=lit;//是否有小数
    int fileflag=file;//是否输出到文件ma once
    int i, nu, sy;
    int bf = -2;//匹配括号
    int num1 = testnum;
    int num2 = digitnum;
    int n;
    printf("*------------------------------------------------*\n");
    printf("*                  生成题目如下                  *\n");
    FILE* fp1 = fopen("D:test_question.txt", "w");
    while (num1 > 0)
    {
        if (bracketflag == 1)//判断是否有括号
        {
            bf = n = rand() % (digitnum - 1) - 1;
        }
        printf("*  (%d) ", testnum - num1 + 1);
        if (fileflag == 1)
        {
            fprintf(fp1, "(%d) ", testnum - num1 + 1);
        }
        nu = n = rand() % maxnum;;
        if (bf == -1)//左括号位置
        {
            printf("(");
        }
        printf("%d", nu);
        if (fileflag == 1)
        {
            if (bf == -1)
            {
                fprintf(fp1, "(");
            }
            fprintf(fp1, "%d", nu);
        }
        for (i = 0; i < num2 - 1; i++)
        {
            int n, flag = 1;
            while (flag)
            {
                n = rand() % 4;
                if (symbolnum[n] != 0)
                {
                    flag = 0;
                }
            }
            sy = n + 1;
            nu = n = rand() % maxnum;
            switch (sy)
            {
            case 1:
                printf("+");
                if (fileflag == 1)
                {
                    fprintf(fp1, "+");
                }
                break;
            case 2:
                printf("-");
                if (fileflag == 1)
                {
                    fprintf(fp1, "-");
                }
                break;
            case 3:
                printf("×");
                if (fileflag == 1)
                {
                    fprintf(fp1, "×");
                }
                break;
            case 4:
                printf("÷");
                if (fileflag == 1)
                {
                    fprintf(fp1, "÷");
                }
                break;
            }
            if (i == bf)//左括号位置
            {
                printf("(");
            }
            printf("%d", nu);
            if ((i == 0 && bf == -1) || (i == (bf + 1)))//右括号位置
            {
                printf(")");
            }
            if (fileflag == 1)
            {
                if (i == bf)
                {
                    fprintf(fp1, "(");
                }
                fprintf(fp1, "%d", nu);
                if ((i == 0 && bf == -1) || (i == (bf + 1)))
                {
                    fprintf(fp1, ")");
                }
            }
        }
        num1--;//控制数值个数
        printf("=\n");
        if (fileflag == 1)
        {
            fprintf(fp1, "=\n");
        }
    }
    fclose(fp1);
}
