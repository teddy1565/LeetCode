#include <stdio.h>

// 函數：計算第 n 個卡塔蘭數
// 使用 long long 來防止中間計算過程溢位
long long calculateCatalan(int n) {
    if (n < 0) {
        return 0; // n 不應為負數
    }
    if (n == 0) {
        return 1; // C_0 = 1
    }

    // C_n = (1/(n+1)) * C(2n, n)
    // 為了避免溢位，我們不直接計算階乘
    // 透過迭代計算 C(2n, n)
    // C(2n, n) = (2n * (2n-1) * ... * (n+1)) / n!
    
    long long result = 1;
    
    // 迴圈計算 C(2n, n)
    // i 從 1 到 n
    for (int i = 1; i <= n; i++) {
        // 為了保持計算的精確性並避免過早的整數除法截斷
        // 我們先做乘法再做除法
        // result = result * (2n - i + 1) / i; 是不安全的
        // 正確的方式是 result = result * (n + i) / i;
        result = result * (n + i) / i;
    }
    
    // 最後再除以 (n+1)
    return result / (n + 1);
}


// 更直接且高效的迭代公式: C_k = C_{k-1} * 2 * (2k-1) / (k+1)
long long calculateCatalanEfficient(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    long long c = 1;
    for (int i = 1; i <= n; i++) {
        // 務必先乘再除，並確保被乘數是 long long 型別以避免溢位
        c = c * 2 * (2 * (long long)i - 1) / (i + 1);
    }
    return c;
}


int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);

    if (n >= 0) {
        // long long total_rows = calculateCatalan(n);
        long long total_rows = calculateCatalanEfficient(n);
        printf("n = %d, rows = %lld\n", n, total_rows);
    } else {
        printf("Not avaliable\n");
    }

    return 0;
}