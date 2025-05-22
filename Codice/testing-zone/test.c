#include <stdio.h>

int add_i(int a, int b) {
    return a + b;
}

float add_f(float a, float b) {
    return a + b;
}

double add_d(double a, double b) {
    return a + b;
}


#define add(a, b) _Generic(a, \
    int: add_i, \
    float: add_f, \
    double: add_d)(a, b)

int main(void) {
    int ai = 1, bi = 2;
    float af = 1.0, bf = 2.0;
    double ad = 1.0, bd = 2.0;

    printf("%d\n", add(ai, bi)); // 3
    printf("%f\n", add(af, bf)); // 3.0
    printf("%e\n", add(ad, bd)); // 3.0

    return 0;
}