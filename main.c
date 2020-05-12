#define CYAN printf("%s", "\033[96;1m")
#define RESET printf("%s", "\033[0m")
#define CRLF printf("%c", '\n')

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <time.h>

void cube();
int t_getchar();
void set_timer();
int rand_generate();

//*********************************************************
int main() {
    set_timer();
    cube();

    return 0;
}
//*********************************************************

//=========================================================
//game run
void cube() {
    system("clear");
    CYAN;
    printf("%s\n\n", "*** DICE GAME ***");
    printf("%s", "Drop dice? <y/n> ");
    int ask = t_getchar();
    CRLF;
    CRLF;
    int final = 0, temp;

    if (ask == 'y' || ask == 'Y')  {
        for(int i = 1; i <= 3; i++) {
            system("sleep 0.5s");
            temp = rand_generate();
            printf("%s %i%s %i", "Dice", i, ":", temp);
            CRLF;
            final += temp;
        }

        system("sleep 0.5s");
        printf("%s\n", "-----------------------------");
        printf("%s %i\n\n", "Total is:", final);
        RESET;
        printf("%s ", "Press <Enter> to continue game...");

        char x;
        scanf("%c", &x);
        cube();
    }

    RESET;
    CRLF;
    system("clear");
}
//=========================================================

//=========================================================
//getting char from terminal key press
int t_getchar() {
    int tchar;
    //---------------------------------------
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    tchar = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    //---------------------------------------

    return tchar;
}
//=========================================================

//=========================================================
//setting timer
void set_timer() {
    time_t tm;
    srand((unsigned) time(&tm));
}
//=========================================================

//=========================================================
//get random number
int rand_generate() {
    int n;
    n = rand() % 6;
    n = n + 1;
    return n;
}
//=========================================================
