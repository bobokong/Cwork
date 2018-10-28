/*
 ============================================================================
 Name        : work4.c
 Author      : Dongdong Kong
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print_num(char ch);

int main(void) {
    // printf("Enter ch: ");
    // ch = getchar();

    char chs[] = {'0', '9', 'a', ' ', 'Z'};
    // int len = sizeof(chs)/sizeof(chs[0]);

    printf("============== %s ===============\n", "5.1");
    /** 5.1 */
    // 1th solution
    // https://stackoverflow.com/questions/48367022/c-iterate-through-char-array-with-a-pointer
    // https://stackoverflow.com/questions/33829566/for-loop-with-pointer-in-c

    // char *p; // Pointer for characters
    // for (p = chs; *p == '\0'; p++) print_num(*p);

    // 2th solution
    // https://www.youtube.com/watch?v=Bf8a6IC1dE8
    int i = 0;
    for (i = 0; i < sizeof(chs); i++){
        print_num(chs[i]);
    }

    /** 5.2 */
    printf("============== %s ===============\n", "5.2");
    count_char(chs);

	return EXIT_SUCCESS;
}


/** 
 * 5.1 Print ASCII value of numberic and blank character, 
 * and print the original value for others
 */
void print_num(char ch){
    printf("The input: %c, and output: ", ch);

    if(ch>=48 && ch <= 57){
        printf("%d\n",ch);
    } else if(ch==' '){
        printf("32\n");
    } else {
        printf("%c\n",ch);
    }
}


/**
 * 5.2 Count the number of numeric character, '*' character and letter
 */
void count_char(char chs[]){
	int len = sizeof(chs);
    int n_num = 0, n_star = 0, n_letter = 0;

    int i = 0;
    char ch;
    for (i = 0; i < len; i++){
    	ch = chs[i];
        if (ch > 47 && ch < 58){
            n_num += 1;
        } else if (ch == '*'){
            n_star += 1;
        } else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
            n_letter += 1;
        }
    }

    printf("The number of: \n");
    printf("\tnumber character: %d\n", n_num);
    printf("\t'*'    character: %d\n"   , n_star);
    printf("\tletter character: %d\n", n_letter);
}
