// hexdump.c
#include <stdio.h>

int main() {
  FILE *fp = fopen("TaoTeChing.txt", "rb");
  if (!fp) {
    perror("Open failed");
    return 1;
  }

  unsigned char buf[512];
  size_t n = fread(buf, 1, sizeof(buf), fp);
  fclose(fp);

  printf("File size: %zu bytes\n", n);
  printf("\nFirst 100 bytes (hex):\n");
  for (size_t i = 0; i < n && i < 100; i++) {
    if (i % 16 == 0)
      printf("\n%04zx: ", i);
    printf("%02x ", buf[i]);
  }

  printf("\n\nLast 50 bytes (hex):\n");
  size_t start = (n > 50) ? n - 50 : 0;
  for (size_t i = start; i < n; i++) {
    if ((i - start) % 16 == 0)
      printf("\n%04zx: ", i);
    printf("%02x ", buf[i]);
  }
  printf("\n");

  // Also print last part as text (careful with non-printable)
  printf("\nLast 50 chars (raw): '");
  for (size_t i = start; i < n; i++) {
    unsigned char c = buf[i];
    if (c >= 32 && c <= 126)
      putchar(c);
    else if (c == '\n')
      printf("\\n");
    else if (c == '\r')
      printf("\\r");
    else if (c == '\t')
      printf("\\t");
    else
      printf("?");
  }
  printf("'\n");

  return 0;
}