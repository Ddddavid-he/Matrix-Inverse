//  tool.h
//  Matrix Inverse
//
//  Created by Ddddavid on 2020/2/21.
//  Copyright © 2020 TD190202. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifndef tool_h
#define tool_h

int n0;

//检验输入是否正确
int examine(int n, int* m0) {
    int i, j, x;
    printf("输入的行列式为:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%-4d", *m0);
            m0++;
        }
        printf("\n");
    }

    printf("\n是否正确？\n#1 正确\n#2 有误\n");
    int t;
Choose:
    scanf_s("%d", &t);
    if ((t == 1 || t == 2) == 0) {
        printf("输入错误，请输入1或2\n");
        goto Choose;
    }
    else if (t == 1)
        x = 0;
    else
        x = 1;                              //wrong

    return x;

}


//输入模块
void input(int n, int* o) {
    int examine(int, int*);
    int i, j, t;
    i = 1;
    if (i == 1) goto First;

Choose1:    printf("#1 重新输入\n#2 更改个别数字\n");
    scanf_s("%d", &t);
    if (t == 1) goto First;
    else if (t == 2) {
    Choose2:        printf("请输入需要更改的数字位置（行，列）：\n");
        scanf_s("%d,%d", &i, &j);
        printf("输入正确数字：");
        scanf_s("%d", (o + (i - 1) * n + j - 1));
    Choose3:        if (examine(n, o) == 1) goto Choose2;
    }
    else if (t != 1 && t != 2) {
        printf("输入错误，请重试\n");
        goto Choose1;
    }
    if (examine(n, o) == 1) goto Choose1;

First:          printf("请输入矩阵\n");
    for (i = 0; i < n; i++) {
        printf("第%d行：", i + 1);
        for (j = 0; j < n; j++) {
            scanf_s("%d", o + i * n + j);
        }
    }
    i++;
    if (examine(n, o) == 1) goto Choose1;
}

//输出模块
void output(int n, int* o, float* rc) {
    int i, j;
    printf("原矩阵为：\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%-4d", *o);
            o++;
        }
        printf("\n");
    }
    printf("逆矩阵为：\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (*(rc + i * n + j) < 0) {
                printf("%-6.2f", *(rc + i * n + j));
            }
            else {
                printf(" %-6.2f", *(rc + i * n + j));
            }
        }
        printf("\n");
    }
}



//
//行列式模块
//求行列式值
int value_d(int n, int* pg) {
    int valuef(int, int*);
    int i, v = 0;
    int* m = NULL;
    for (;;) {
        m = (int*)calloc(sizeof(int), n * n);
        if (m != NULL) break;
        printf("加载中...");
    }
    for (i = 0; i < n * n; i++) {
        *(m + i) = *(pg + i);
    }
    v = valuef(n, m);         //求行列式的值
    free(m);
    return v;
}


//拉普拉斯定理计算
int valuef(int n, int* p0) {
    void reform(int*, int*, int, int);
    int value = 0, sign = 1, c;
    int* p = NULL;
    if (n > 2) {
        for (c = 0; c < n; c++) {//第一行元素
            p = (int*)calloc(sizeof(int), (n - 1) * (n - 1));//子行列式地址
            reform(p0, p, n, c);
            sign = (int)pow(-1, c + 2);//符号
            value = value + sign * (*(p0 + c)) * valuef(n - 1, p);
        }
    }
    else if (n == 2)
        value = (*p0) * (*(p0 + 3)) - (*(p0 + 1)) * (*(p0 + 2));

    else if (n == 1)
        value = *p0;

    return value;
}

//重组行列式
void reform(int* p_i, int* p_o, int n, int c) {//（输入，输出，阶，去除列）
    int i, j, r, k = 0;
    for (i = 1; i < n; i++) {
        r = n * i;//n为母行列式的阶数
        for (j = 0; j < n; j++) {
            if (j == c) continue;
            *(p_o + k) = *(p_i + r + j);
            k++;//indicator
        }
    }

}

//重组行列式2
void reform2(int* p_i, int* p_o, int n, int r, int c) {//（输入，输出，阶，去除行，去除列）
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
        if (i == r) continue;       //n为母行列式的阶数
        for (j = 0; j < n; j++) {
            if (j == c) continue;
            *(p_o + k) = *(p_i + i * n + j);
            k++;//indicator
        }
    }

}



#endif /* tool_h */
