//
// Created by 张啸宇 on 2019-04-20.
//

#ifndef PL0_PL0_H
#define PL0_PL0_H

#include <cstdio>

/**
 * 关键字个数
 */
#define norw 13

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
    callsym, constsym, varsym, procsym,
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
char word[norw][al];
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

void init();
#endif //PL0_PL0_H