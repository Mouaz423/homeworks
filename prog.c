#include <stdio.h>
#include <string.h>
#define SZ 100

typedef struct {
    char b[SZ];
    int h, t, n;
} RB;

void put(RB *r, char c) {
    if (r->n < SZ) {
        r->b[r->t] = c;
        r->t = (r->t + 1) % SZ;
        r->n++;
    }
}

char get(RB *r) {
    if (r->n == 0) return 0;
    char c = r->b[r->h];
    r->h = (r->h + 1) % SZ;
    r->n--;
    return c;
}

int main() {
    RB r = {0};
    char s[SZ];

    printf("Enter name: ");
    if (fgets(s, SZ, stdin)) {
        s[strcspn(s, "\n")] = 0;
        strcat(s, "CE-ESY");

        for (int i = 0; s[i]; i++) put(&r, s[i]);

        printf("Output: ");
        while (r.n > 0) putchar(get(&r));
        putchar('\n');
    }
    return 0;
}
