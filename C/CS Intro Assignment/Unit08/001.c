#include <stdio.h>
int main() {
  int x[] = {1, 2, 3, 4};
  int *pa, *pb, addr;
  pa = x;
  pb = &x[0];
  /* %p Prints an address in hex digits. */
  printf("pa=%p, pb=%p\n", pa, pb);
  addr = (int)pa;
  printf("pa+1=%p, value_of_pa_plus_sizeof(int)=%X\n", pa + 1,
         addr + 1 * sizeof(int));
}
