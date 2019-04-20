//
// Created by 张啸宇 on 2019-04-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  type类别表:
         1 : 关键字
         2 : 界符
	     3 : 运算符
	     4 : 数字
         5 : 变量
         6 : 不合法
 */
typedef struct word {
    int type;
    char value[20];
} Word;

/**
 * 13 个保留字
 * 05 个界符
 * 11 个运算符
 * 10 个数字
 */
char keyword[39][20] = {"begin", "call", "const", "do", "end", "if", "odd", "procedure", "read", "then", "var", "while",
                        "write",
                        ".", ";", ",", "(", ")",
                        "+", "-", "*", "/", "=", "<", ">", "<=", ">=", ":=", "#",
                        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};


int main() {
    char ch, temp_word[20] = "";
    int word_cnt = 0, j = 0, k = 0, key = 0, type = 0;
    FILE *file;
    Word source_words[100];

    file = fopen("/Users/xiaoyuu/CLionProjects/PL0/nasm.txt", "r");
    if (!file) {
        printf("can't open file C_program.txt\n");
        exit(1);
    }
    printf("源程序如下:");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);

        if (ch == ' ' || ch == 10 || ch == 9 || ch == '	') {
            continue;
        }

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            temp_word[key++] = ch;
            temp_word[key] = '\0';
            continue;
        }

//        if (strcmp(temp_word, "") != 0) {
//            strcpy(source_words[word_cnt++].value, temp_word);
//            strcpy(temp_word, "");
//            key = 0;
//        }

        temp_word[0] = ch;
        if (temp_word[0] == ':' || temp_word[0] == '>' || temp_word[0] == '<')
            ch = static_cast<char>(fgetc(file));
        if (ch == '=') {
            temp_word[1] = ch;
            temp_word[2] = '\0';
        } else {
            temp_word[1] = '\n';
        }

        strcpy(source_words[word_cnt++].value, temp_word);//将非字母数字符号拷贝到结构数组中
        strcpy(temp_word, "");
        key = 0;//回到临时数组的开始位置
    }

    for (j = 0; j < word_cnt; j++) {
        for (k = 0; k < 39; k++) {
            if ((strcmp(source_words[j].value, keyword[k])) == 0) {
                if (k >= 0 && k < 13)
                    source_words[j].type = 1;
                else if (k >= 13 && k < 18)
                    source_words[j].type = 2;
                else if (k >= 18 && k < 29)
                    source_words[j].type = 3;
                else if (k >= 29 && k < 39)
                    source_words[j].type = 4;
                break;
            } else {
                source_words[j].type = 2;//变量
            }

        }
    }
    printf("\n词法分析结果如下:\n");
    for (int i = 0; i < word_cnt; ++i) {
        printf("(%d,'%s')\n", source_words[i].type, source_words[i].value);
    }
    //输出保留字
    printf("\n保留字表：\n\n");
    for (j = 0; j < word_cnt; j++) {
        if (source_words[j].type == 1) {
            printf("%s ", source_words[j].value);
        }

    }
    //分隔符表
    printf("\n分隔符表：\n\n");
    for (j = 0; j < word_cnt; j++) {
        if (source_words[j].type == 2) {
            printf("%s ", source_words[j].value);
        }

    }
    //运算符表
    printf("\n运算符表：\n\n");
    for (j = 0; j < word_cnt; j++) {
        if (source_words[j].type == 3) {
            printf("%s ", source_words[j].value);
        }

    }
    //数字表
    printf("\n数字表：\n\n");
    for (j = 0; j < word_cnt; j++) {
        if (source_words[j].type == 4) {
            printf("%s  ", source_words[j].value);
        }
    }

    //变量表
    printf("\n变量表：\n");
    for (j = 0; j < word_cnt; j++) {
        if (source_words[j].type == 5) {
            printf("%s ", source_words[j].value);
        }
    }

    printf("\n");


}