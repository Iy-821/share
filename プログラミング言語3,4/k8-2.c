#include <stdio.h>
#define N 10
void f(int x[], int n) {
    if (n == N) {
    return;
    } else {
        printf("%d ",x[N-1-n]);
        f(x,++n);
    }
}
int main() {
    int array[N];
    int i;
    for (i = 0; i < N; i++) {
        array[i] = i;
    }
    f(array, 0);

    return 0;
}
