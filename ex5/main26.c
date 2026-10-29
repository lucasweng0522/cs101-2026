#include <stdio.h>

int multi(int i, int j) {
    if (j == 1) {
        printf("%d*%d=%d\t", i, j, i * j);
        return 0;
    } else {
        multi(i, j - 1);
        printf("%d*%d=%d\t", i, j, i * j);
    }
}


int print_rows(int i) {
    if (i > 9) {
        return 0;
    }
    multi(i, 9);
    printf("\n");
    print_rows(i + 1); 
}

int main() {
    print_rows(1);
    return 0;
}
