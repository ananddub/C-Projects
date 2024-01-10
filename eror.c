#include <stdio.h>

void test(int, int);

int main() {
  test(4);
  return 1;
}
void test(int a, int b) { printf("hello world "); }
