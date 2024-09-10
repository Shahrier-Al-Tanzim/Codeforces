#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int k = n % 2;

    switch(k) {
        case 1:
            printf("NO\n");
            goto out;
            break;
        case 0:
            goto alt;
            break;
    }

    alt:
        switch (n) {
            case 2:
                printf("NO\n");
                break;
            default:
                printf("YES\n");
                break;
        }

    out:
}