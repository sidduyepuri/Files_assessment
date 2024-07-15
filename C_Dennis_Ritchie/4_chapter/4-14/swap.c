/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
 * Author: Yepuri Siddu
 * Created: 20 April, 2024
 * Modified: 20 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

// Macro for swapping two variables of type t
#define swap(t, x, y) \
  {                   \
    t temp;           \
    temp = x;         \
    x = y;            \
    y = temp;         \
  };

int main(void)
{
  int x = 2, y = 3;

  // Print original values
  printf("Original: x = %d, y = %d\n", x, y);

  // Swap values using the swap macro
  swap(int, x, y);

  // Print values after swapping
  printf("After swap: x = %d, y = %d\n", x, y);

  return 0;
}

