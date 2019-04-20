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
        // printf("请输入要保存的文件名\n");
        //  scanf("%s", fname);
        //fa1 = fopen(fname, "w");
        init();
        err = 0;
        cc = cx = ll = 0;
        ch = ' ';
        while (ch != '.') {
            getsym();
            printf("\n");
        }
        // fclose(fa1);
        printf("分析完毕");

    } else {
        printf("找不到文件\n");
    }
    // printf("\n");
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
//        printf("%d", cx);
//        fprintf(fa1, "%d ", cx);
        ch = ' ';
        //处理一整行
        while (ch != 10) {
            if (EOF == fscanf(fin, "%c", &ch)) {
                line[ll] = 0;
                break;
            }
//            printf("%c", ch);
//            fprintf(fa1, "%c", ch);
            line[ll++] = ch;
        }
//        printf("\n");
//        fprintf(fa1, "\n");

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

        //搜索当前符号是否为保留字
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
                        if (sym != period) {
                            printf("%c   %s", ch, list[sym]);
                            getchdo;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void init() {
    int i;
    //设置单字符符号
    for (i = 0; i < 256; i++) {
        ssym[i] = nul;
    }
    ssym['+'] = plus;
    ssym['-'] = minus;
    ssym['*'] = times;
    ssym['/'] = slash;
    ssym['('] = lparen;
    ssym[')'] = rparen;
    ssym['='] = eql;
    ssym[','] = comma;
    ssym['.'] = period;
    ssym['#'] = neq;
    ssym[';'] = semicolon;

    strcpy(&(word[0][0]), "begin");
    strcpy(&(word[1][0]), "call");
    strcpy(&(word[2][0]), "const");
    strcpy(&(word[3][0]), "do");
    strcpy(&(word[4][0]), "end");
    strcpy(&(word[5][0]), "if");
    strcpy(&(word[6][0]), "odd");
    strcpy(&(word[7][0]), "procedure");
    strcpy(&(word[8][0]), "read");
    strcpy(&(word[9][0]), "then");
    strcpy(&(word[10][0]), "var");
    strcpy(&(word[11][0]), "while");
    strcpy(&(word[12][0]), "write");

    strcpy(&(list[0][0]), "nul");
    strcpy(&(list[1][0]), "ident");
    strcpy(&(list[2][0]), "number");
    strcpy(&(list[3][0]), "plus");
    strcpy(&(list[4][0]), "minus");
    strcpy(&(list[5][0]), "times");
    strcpy(&(list[6][0]), "slash");
    strcpy(&(list[7][0]), "oddsym");
    strcpy(&(list[8][0]), "eql");
    strcpy(&(list[9][0]), "neq");
    strcpy(&(list[10][0]), "lss");
    strcpy(&(list[11][0]), "leq");
    strcpy(&(list[12][0]), "gtr");
    strcpy(&(list[13][0]), "geq");
    strcpy(&(list[14][0]), "lparen");
    strcpy(&(list[15][0]), "rparen");
    strcpy(&(list[16][0]), "comma");
    strcpy(&(list[17][0]), "semicolon");
    strcpy(&(list[18][0]), "period");
    strcpy(&(list[19][0]), "becomes");
    strcpy(&(list[20][0]), "beginsym");
    strcpy(&(list[21][0]), "endsym");
    strcpy(&(list[22][0]), "ifsym");
    strcpy(&(list[23][0]), "thensym");
    strcpy(&(list[24][0]), "whilesym");
    strcpy(&(list[25][0]), "writesym");
    strcpy(&(list[26][0]), "readsym");
    strcpy(&(list[27][0]), "dosym");
    strcpy(&(list[28][0]), "callsym");
    strcpy(&(list[29][0]), "constsym");
    strcpy(&(list[30][0]), "varsym");
    strcpy(&(list[31][0]), "procsym");

    wsym[0] = beginsym;
    wsym[1] = callsym;
    wsym[2] = constsym;
    wsym[3] = dosym;
    wsym[4] = endsym;
    wsym[5] = ifsym;
    wsym[6] = oddsym;
    wsym[7] = procsym;
    wsym[8] = readsym;
    wsym[9] = thensym;
    wsym[10] = varsym;
    wsym[11] = whilesym;
    wsym[12] = writesym;


}