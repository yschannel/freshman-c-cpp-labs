#include <stdio.h>
int main() {
  double all = 0.0;
  for (int i = 0; i < 15; i++) {
    printf("score:");
    int s;
    scanf("%d", &s);
    printf("study:");
    float t;
    scanf("%f", &t);
    all += t * (4.0 - 3.0 * (100 - s) * (100 - s) / 1600);
  }
  printf("/nGPA:%.2lf", all / 29.9);
  return 0;
}