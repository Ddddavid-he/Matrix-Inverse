//
//  main.c
//  Matrix Inverse
//
//  Created by Ddddavid on 2020/2/7.
//  Copyright © 2020 TD190202. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tool.h"


int main() {
    printf("           逆矩阵计算器\n");

    void input(int n, int* o);
    int n, i, j;
    int* pg = NULL;
    float* rc = NULL;
    int* o = NULL, * temp = NULL;
    //    void *p0,*p1,*p2;

Step:
    printf("请输入矩阵阶数：");
    scanf_s("%d", &n);
    if (n <= 0) {
        printf("Wrong n, you should make it a positive. Retry.\n");
        getchar();
        goto Step;
    }
    printf("\n");
    
    //初始化
    n0 = n;
    o = (int*)calloc(sizeof(int), n * n);
    pg = (int*)calloc(sizeof(int), n * n);
    rc = (float*)calloc(sizeof(float), n * n);
    temp = (int*)calloc(sizeof(int), (n - 1) * (n - 1));

    input(n, o);
    for (i = 0; i < n * n; i++)
        *(pg + i) = *(o + i);
    //    o=p0;pg=p1;rc=p2;
    if (value_d(n, pg) == 0) {
        printf("此矩阵不存在逆矩阵。\n");
        return 0;
    }
    if (n == 1) {
        if (*o == 0) {
            printf("此矩阵不存在逆矩阵。\n");
        }
        else  {
            *rc = 1/(*o);
            output(n, o, rc);
        }
    }
    else {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                reform2(pg, temp, n, i, j);
                *(rc + i * n + j) = (int)powf(-1, i + j) * value_d(n - 1, temp) / value_d(n, pg);
            }
        output(n, o, rc);
    }
    free(pg);
    free(temp);
    return 0;
}
