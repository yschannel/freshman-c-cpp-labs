// make_test_file.c
#include <stdio.h>

int main() {
  FILE *fp = fopen("TaoTeChing.txt", "wb");
  if (!fp)
    return 1;

  fprintf(fp, "The Tao that can be spoken or described is not the “Immutable "
              "and Everlasting Tao”.\n");
  fprintf(fp, "The Name that can be named or spelt out is not the “immutable "
              "and everlasting Name”.\n");
  fprintf(fp, "That which is “unidentifiable and nameless” is the Originator "
              "of the Universe,\n");
  fprintf(fp, "whereas that which is “identifiable and with names” is the "
              "Mother of all things.\n");

  fclose(fp);
  printf("File created. Now run your wc.c on it.\n");
  return 0;
}