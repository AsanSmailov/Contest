#include <math.h>

std::tuple<int, int> reduce(int n, int m) {
    for (int i = abs(n); i > 1; i--) {
        if (n % i == 0 && m % i == 0) {
            n /= i;
            m /= i;
            return std::make_tuple(n, m);
        }
    }
    return std::make_tuple(n, m);
}

std::tuple<int, int, int> find_lcm(int n1, int n2) {
    int lcm = n1;
    int c1 = 1, c2 = 1;
    while (lcm % n2 != 0) {
        lcm += n1;
        c1++;
    }
    c2 = lcm / n2;
    return std::make_tuple(lcm, c1, c2);
}