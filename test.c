#include <stdio.h>
#include <stdlib.h>

int getint() { int a; char ch; if(scanf("%d", &a) == 0) { printf("Error: cannot enter non-numeric input.\n"); exit(1); } else if(scanf("%c", &ch) == EOF) { printf("Error: unexpected end of input.\n"); exit(1); } return a; }
void putint(int a) { printf("%d\n", a); }
int divide(int x, int y) { if(y == 0) { printf("Error: cannot divide by 0.\n"); exit(1); } return x / y; }

int main() {
int a = getint();
int b = 3;
int c = divide(b, (a - 1));
a = b;
c = 1;
b = (c + 3);
putint (c);
}
