#ifdef BUILD_ATARI16BIT
/**
 * FujiNet Config for Adam
 * 
 * Cursor routines
 */

#include <stdio.h>
#include "cursor.h"

void cursor(bool t)
{
  if (t) {
    printf("%c[?25h", 27);
  } else {
    printf("%c[?25l", 27);
  }
}

void cursor_pos(unsigned char x, unsigned char y)
{
  printf("%c[%d;%dH", 27, y+1, x+1);
}
#endif /* BUILD_ATARI16BIT */
