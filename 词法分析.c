//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<limits.h>
//
//
//enum symbol sym;
//enum symbol ssym[256];
//enum symbol wsym[13] = {beginsym, callsym, constsym, dosym, endsym, ifsym, oddsym, procsym, readsym, thensym, varsym,
//                        whilesym, writesym};
//char line[256], a[257], ch = ' ';
//char word[13][257], id[256], list[32][257];
//int cc = 0, ll = 0, num;
//
//
//void main() {
//    FILE *fin = fopen("input.txt", "r");  //其中"r"是表示 读
//    init();
while (ch != '.') {
getsym(fin);
printf("\n");
}
//    printf(".      period");
//}
//
//int getch(FILE *fin) {
//    if (cc == ll) {
//        if (feof(fin)) {
//            printf("program incomplete");
//            return -1;
//        }
//        ll = 0;
//        cc = 0;
//        // printf("%c",ch);
//        //  fprintf(fal,"%d",cx);
//        ch = ' ';
//        while (ch != 10) {
//            if (fscanf(fin, "%c", &ch) == EOF) {
//                line[ll] = 0;
//                break;
//            }
//            //printf("%c",ch);
//            // fprintf(fal,"%c",ch);
//            line[ll] = ch;
//            ll++;
//        }
//        // printf("\n");
//        //fprintf(fal,"\n");
//    }
//    ch = line[cc];
//    cc++;
//    return 0;
//}
//
//int getsym(FILE *fin) {
//    int i, j, k;
//    while (ch == ' ' || ch == 10 || ch == 9) { getch(fin); }
//    if (ch >= 'a' && ch <= 'z') {
//        k = 0;
//        do {
//            if (k < 257) {
//                a[k] = ch;
//                k++;
//            }
//            getch(fin);
//        } while (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9');
//        a[k] = 0;
//        strcpy(id, a);
//        i = 0;
//        j = 12;
//        do {
//            k = (i + j) / 2;
//            if (strcmp(id, word[k]) <= 0) j = k - 1;
//            if (strcmp(id, word[k]) >= 0) i = k + 1;
//        } while (i <= j);
//        if (i - 1 > j) {
//            sym = wsym[k];
//        } else {
//            sym = ident;
//        }
//        printf("%s    %s", a, list[sym]);
//    } else {
//        if (ch >= '0' && ch <= '9') {
//            k = 0;
//            num = 0;
//            sym = number;
//            do {
//                num = 10 * num + ch - '0';
//                k++;
//                getch(fin);
//            } while (ch >= '0' && ch <= '9');
//            k--;
//            if (k > INT_MAX) error(30);
//            printf("%d    %s", num, list[sym]);
//        } else {
//            if (ch == ':') {
//                getch(fin);
//                if (ch == '=') {
//                    sym = becomes;
//                    printf(":=    %s", list[sym]);
//                    getch(fin);
//                } else {
//                    sym = nul;
//                    printf(":%c   %s", ch, list[sym]);
//                }
//            } else {
//                if (ch == '<') {
//                    getch(fin);
//                    if (ch == '=') {
//                        sym = leq;
//                        printf("<=    %s", list[sym]);
//                        getch(fin);
//                    } else {
//                        sym = lss;
//                        printf("<    %s", list[sym]);
//                    }
//                } else {
//                    if (ch == '>') {
//                        getch(fin);
//                        if (ch == '=') {
//                            sym = geq;
//                            printf(">=    %s", list[sym]);
//                            getch(fin);
//                        } else {
//                            sym = gtr;
//                            printf(">    %s", list[sym]);
//                        }
//                    } else {
//                        sym = ssym[ch];
//                        if (sym != period) {
//                            printf("%c   %s", ch, list[sym]);
//                            getch(fin);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}
