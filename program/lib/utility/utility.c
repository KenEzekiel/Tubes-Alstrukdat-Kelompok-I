#include <stdio.h>
#include "utility.h"

void print_red(char* c) {
    printf("%s%s", RED, c);
    printf("%s", NORMAL);
}

void print_green(char* c) {
    printf("%s%s", GREEN, c);
    printf("%s", NORMAL);
}

void print_yellow(char* c) {
    printf("%s%s", YELLOW, c);
    printf("%s", NORMAL);
}

void print_blue(char* c) {
    printf("%s%s", BLUE, c);
    printf("%s", NORMAL);
}

void print_magenta(char* c) {
    printf("%s%s", MAGENTA, c);
    printf("%s", NORMAL);
}

void print_cyan(char* c) {
    printf("%s%s", MAGENTA, c);
    printf("%s", NORMAL);
}

void print_image(FILE *fptr)
/* Mencetak ASCII art yang disimpan dalam .txt */
{
    char read_string[50];

    while(fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s",read_string);
}

void displaySplashScreen(char *filename) {
    FILE *fptr = NULL;
    fptr = fopen(filename,"r");
    print_image(fptr);
}