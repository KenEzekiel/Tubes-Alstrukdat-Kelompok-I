#ifndef Utility_H
#define Utility_H

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\033[0;33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\033[0;36m"
#include <stdio.h>

void print_red(char* c);

void print_green(char* c);

void print_yellow(char* c);

void print_blue(char* c);

void print_magenta(char* c);

void print_cyan(char* c);

void print_image(FILE *fptr);

void displaySplashScreen();

#endif