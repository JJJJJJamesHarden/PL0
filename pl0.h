//
// Created by 张啸宇 on 2019-04-20.
//

#ifndef PL0_PL0_H
#define PL0_PL0_H

#include <cstdio>

/**
 * 关键字个数
 */
#define norw 14

/**
 * number的最大位数
 */
#define nmax 14

/**
 * 符号的最大长度
 */
#define al 10
/**
 * 最多的虚拟机代码数
 */
#define cxmax 200
/**
 * 符号
 */
enum symbol {
    nul, ident, number, plus, minus, times, slash, oddsym, eql, neq,
    lss, leq, gtr, geq, lparen, rparen, comma, semicolon, period, becomes,
    beginsym, endsym, ifsym, thensym, whilesym, writesym, readsym, dosym,
    callsym, constsym, varsym, procsym, zxy
};

/**
 * 输出分析的文件和首地址 首地址是虚拟机指针
 */
FILE *fa1;
/**
 * getch读取的字符
 */
char ch;
/**
 * 当前的符号
 */
enum symbol sym;
/**
 * 当前的ident,多出的一个字节用于存放0
 */
char id[al + 1];
/**
 * 当前的num
 */
int num;
/**
 * getch使用的计数器，cc表示当前字符(ch)的位置
 */
int cc, ll;
/**
 * 虚拟机代码指针，取值范围[0,cxmax-1]
 */
int cx;
/**
 * 读取行缓存区
 */
char line[81];
/**
 * 临时符号，多出的一个字节用于存放0
 */
char a[al + 1];

/**
 * 保留字
 */
char word[norw + 1][al];
/**
 * 保留字对应的符号值
 */
enum symbol wsym[norw];
/**
 * 单字符的符号值
 */
enum symbol ssym[256];
/**
 * 错误计数器
 */
int err;


FILE *fin;
FILE *fout;
char fname[al];
char list[32][257];
#define getchdo            if(-1 == getch()) return -1;
void error(int n);

int getsym();

int getch();

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
    strcpy(&(word[13][0]), "zxy");

    strcpy(&(list[0][0]), "nul");
    strcpy(&(list[1][0]), "标识符");
    strcpy(&(list[2][0]), "数字");
    strcpy(&(list[3][0]), "运算符");
    strcpy(&(list[4][0]), "运算符");
    strcpy(&(list[5][0]), "运算符");
    strcpy(&(list[6][0]), "slash");
    strcpy(&(list[7][0]), "基本字");
    strcpy(&(list[8][0]), "运算符");
    strcpy(&(list[9][0]), "运算符");
    strcpy(&(list[10][0]), "lss");
    strcpy(&(list[11][0]), "leq");
    strcpy(&(list[12][0]), "gtr");
    strcpy(&(list[13][0]), "geq");
    strcpy(&(list[14][0]), "界符");
    strcpy(&(list[15][0]), "界符");
    strcpy(&(list[16][0]), "界符");
    strcpy(&(list[17][0]), "界符");
    strcpy(&(list[18][0]), "界符");
    strcpy(&(list[19][0]), "运算符");
    strcpy(&(list[20][0]), "基本字");
    strcpy(&(list[21][0]), "基本字");
    strcpy(&(list[22][0]), "基本字");
    strcpy(&(list[23][0]), "基本字");
    strcpy(&(list[24][0]), "基本字");
    strcpy(&(list[25][0]), "基本字");
    strcpy(&(list[26][0]), "基本字");
    strcpy(&(list[27][0]), "基本字");
    strcpy(&(list[28][0]), "基本字");
    strcpy(&(list[29][0]), "基本字");
    strcpy(&(list[30][0]), "基本字");
    strcpy(&(list[31][0]), "基本字");
    strcpy(&(list[32][0]), "基本字");

//    strcpy(&(list[0][0]), "nul");
//    strcpy(&(list[1][0]), "ident");
//    strcpy(&(list[2][0]), "shu");
//    strcpy(&(list[3][0]), "plus");
//    strcpy(&(list[4][0]), "minus");
//    strcpy(&(list[5][0]), "times");
//    strcpy(&(list[6][0]), "slash");
//    strcpy(&(list[7][0]), "oddsym");
//    strcpy(&(list[8][0]), "eql");
//    strcpy(&(list[9][0]), "neq");
//    strcpy(&(list[10][0]), "lss");
//    strcpy(&(list[11][0]), "leq");
//    strcpy(&(list[12][0]), "gtr");
//    strcpy(&(list[13][0]), "geq");
//    strcpy(&(list[14][0]), "lparen");
//    strcpy(&(list[15][0]), "rparen");
//    strcpy(&(list[16][0]), "comma");
//    strcpy(&(list[17][0]), "semicolon");
//    strcpy(&(list[18][0]), "period");
//    strcpy(&(list[19][0]), "becomes");
//    strcpy(&(list[20][0]), "beginsym");
//    strcpy(&(list[21][0]), "endsym");
//    strcpy(&(list[22][0]), "ifsym");
//    strcpy(&(list[23][0]), "thensym");
//    strcpy(&(list[24][0]), "whilesym");
//    strcpy(&(list[25][0]), "writesym");
//    strcpy(&(list[26][0]), "readsym");
//    strcpy(&(list[27][0]), "dosym");
//    strcpy(&(list[28][0]), "callsym");
//    strcpy(&(list[29][0]), "constsym");
//    strcpy(&(list[30][0]), "varsym");
//    strcpy(&(list[31][0]), "procsym");

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
    wsym[13] = zxy;


}
#endif //PL0_PL0_H