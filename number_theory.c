#include <math.h>
#include "number_theory.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

void generateIntegerList(int*, int);
void initialiseBooleanArr(bool*, int);

/// @brief 
/// @param n 
/// @return 
int getIntegerLength(int n) {
    int length = 1;
    while(n > 9) {
        n /= 10.0;
        length++;
    }
    printf("The length is %d\n", length);
    return length;
}

void initialiseBooleanArr(bool* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = false;
    }
}

/// @brief Get all 'primes' up until n. A valid form of primality test for n <= 10 ^ 7
/// @param n 
/// @return 
int* sieveOfEratosthenes() {
    int n = 0;
    printf("Choose an n value: ");
    scanf("%d", &n);

    bool visited[n - 2];
    initialiseBooleanArr(visited, n - 2);
    
    // Create an array of length n - 2 to not include 0, 1
    int* integerList = (int*)malloc((n - 2) * sizeof(int));

    if (integerList == NULL) {
        perror("Did not allocate memory");
        return 1;
    }
    // First element in the list
    generateIntegerList(integerList, n);
    int p = integerList[0];
    int index = 0;
    while(p <= n) {
        for (int i = 0; i < n - 1; i++) {
            if (integerList[i] % p == 0 && integerList[i] != p) {
                visited[i] = true;
            }
        }
        p = getSmallestElement(integerList, p, visited, n - 2);
        if (p == INT_MIN){
            break;
        }
    }
    // Printing out the new list
    for (int i = 0; i <= (n - 2); i++) {
        if (!visited[i]) {
            printf("%d\n", integerList[i]);
        }
    }

    free(integerList);
}
int getSmallestElement(int* list, int prevP, bool* visited, int length) {
    for (int i = 0; i < length; i++) {
        if (prevP < list[i] && !visited[i]) {
            return list[i];
        }
    }
    return INT_MIN;
}

/// @brief 
/// @param integerList 
/// @param n 
void generateIntegerList(int* integerList, int n) {
    int p = 2;
    for (int i = 0; i <= (n - 2); i++) {
        integerList[i] = p++;
    }
}

/// @brief Uitilising a probalisitic algorithm
/// @param n 
/// @return 
bool isPrime(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
}

/// @brief 
/// @param n 
/// @return 
bool isDivisibleByThreeOrNine(int n) {
    int length = getIntegerLength(n);
    int sigDigit = n / pow(10, (length - 1));
    n = n - ((sigDigit) * pow(10, (length - 2)));
    sigDigit = n / pow(10, (length - 2));
    printf("Digit is %d\n", sigDigit);
    
    return true;
}
