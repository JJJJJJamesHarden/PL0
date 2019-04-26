//
// Created by 张啸宇 on 2019-04-19.
//
#include <cstring>
#include "pl0.h"

int main() {
    printf("请输入要分析的文件名\n");
    scanf("%s", fname);
    fin = fopen(fname, "r");
    if (fin) {
        init();
        err = 0;
        cc = cx = ll = 0;
        ch = ' ';
        while (true) {
            if (getsym() == -1)break;
            printf("\n");
        }
    }
    return 0;
}

void error(int n) {
    char space[81];
    memset(space, 32, 81);
    space[cc - 1] = 0;
    printf("****%s!%d\n", space, n);
    fprintf(fa1, "****%s1%d\n", space, n);
    err++;
}

int getch() {
    if (cc == ll) {
        if (feof(fin)) {
            printf("Program incomplete");
            return -1;
        }
        ll = 0;
        cc = 0;
        ch = ' ';
        //处理一整行 不等于换行
        while (ch != 10) {
            if (EOF == fscanf(fin, "%c", &ch)) {
                line[ll] = 0;
                break;
            }
            line[ll++] = ch;
        }
    }
    //到行末尾读下一行
    ch = line[cc++];
    return 0;
}

bool isAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

bool isBlank(char c) {
    return c == ' ' || c == 10 || c == 9;
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int getsym() {
    int i, j, k;
    //忽略空格换行和Tab
    while (isBlank(ch)) {
        getchdo;
    }
    //以字母开头的标识符
    if (isAlpha(ch)) {
        k = 0;
        do {
            if (k < al) {
                a[k++] = ch;
            }
            getchdo;
        } while (isAlpha(ch) || isNumber(ch));
        a[k] = 0;
        strcpy(id, a);
        i = 0;
        j = norw - 1;

        //二分查找当前符号是否为保留字
        do {
            k = (i + j) / 2;
            if (strcmp(id, word[k]) <= 0) {
                j = k - 1;
            }
            if (strcmp(id, word[k]) >= 0) {
                i = k + 1;
            }
        } while (i <= j);

        if (i - 1 > j) {
            //基本字
            sym = wsym[k];
        } else {
            //标识符
            sym = ident;
        }
        printf("%s    %s", a, list[sym]);
    } else {
        //数字
        if (isNumber(ch)) {
            k = 0;
            num = 0;
            sym = number;
            do {
                num = 10 * num + ch - '0';
                k++;
                getchdo;
            } while (isNumber(ch));
            k--;
            if (k > nmax) {
                error(30);
            }
            printf("%d    %s", num, list[sym]);
        } else {

            if (ch == ':') {
                getchdo;
                if (ch == '=') {
                    sym = becomes;
                    printf(":=    %s", list[sym]);
                    getchdo;
                } else {
                    sym = nul;
                    printf(":%c   %s", ch, list[sym]);
                }
            } else {
                if (ch == '<') {
                    getchdo;
                    if (ch == '=') {
                        sym = leq;
                        printf("<=    %s", list[sym]);
                        getchdo;
                    } else {
                        sym = lss;
                        printf("<    %s", list[sym]);
                    }
                } else {
                    if (ch == '>') {
                        getchdo;
                        if (ch == '=') {
                            sym = geq;
                            printf(">=    %s", list[sym]);
                            getchdo;
                        } else {
                            sym = gtr;
                            printf(">    %s", list[sym]);
                        }
                    } else {
                        sym = ssym[ch];
                        if (sym >= 0 && sym < 32) {
                            printf("%c   %s", ch, list[sym]);
                        } else {
                            printf("错误  %c", ch);
                        }
                        if (sym == period) {
                            return -1;
                        }
                        getchdo;
                    }
                }
            }
        }
    }
    return 0;
}