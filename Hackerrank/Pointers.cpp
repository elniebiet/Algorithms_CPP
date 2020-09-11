#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    int _a = *a;
    int _b = *b;

    *a = (_a + _b);

    *b = abs(_a - _b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
