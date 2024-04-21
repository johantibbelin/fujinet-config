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
    printf("%ce", 27);
  } else {
    printf("%cf", 27);
  }
}

void cursor_pos(unsigned char x, unsigned char y)
{
  printf("%cY%c%c", 27, y+32, x+32);
}
#endif /* BUILD_ATARI16BIT */
