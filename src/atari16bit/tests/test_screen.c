#ifdef BUILD_ATARI16BIT
#include "../screen.h"

void test_screen_functions()
{
    printf("Test of screen functions, this shold not be seen.\n");
    screen_clrscr();
    printf("This is shown after screen is cleared.\n\r");
    screen_print_inverse("This is in inverse.\n\r");
    screen_gotoxy(5,5);
    printf("5,5");
    screen_gotoxy(10,10);
    screen_print_inverse("10,10");
}
#endif /* BUILD_ATARI16BIT */