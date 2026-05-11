


//
// Created by Sancrist on 5/7/26.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long pthFactor(long long n, long long p) {
    // Allocating bspace for factors (sqrt(n) * 2 handles the max possible factors)
    long long *factors = (long long *)malloc(2 * sqrt(n) * sizeof(long long));
    long long count = 0;

    // Find factors up to sqrt(n)
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors[count++] = i;
        }
    }

    // Find the paired factors (n/i) in descending order to keep the final list sorted
    long long num_small = count;
    for (long long j = num_small - 1; j >= 0; j--) {
        if (factors[j] * factors[j] != n) {
            factors[count++] = n / factors[j];
        }
    }

    long long result = (p <= count) ? factors[p - 1] : 0;

    free(factors);
    return result;
}

// int main() {
//     long long n, p;
//
//     printf("Enter n (the number): ");
//     if (scanf("%lld", &n) != 1) return 1;
//
//     printf("Enter p (the factor index): ");
//     if (scanf("%lld", &p) != 1) return 1;
//
//     long long result = pthFactor(n, p);
//
//     if (result == 0) {
//         printf("0 (n has fewer than %lld factors)\n", p);
//     } else {
//         printf("The %lld-th factor is: %lld\n", p, result);
//     }
//
//     return 0;
// }
