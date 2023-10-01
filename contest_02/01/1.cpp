#include <math.h>
int is_prime(int n){
     for (int i = 2; i <=sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    } return 1;
} 