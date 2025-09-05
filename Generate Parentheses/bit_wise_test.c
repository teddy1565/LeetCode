#include <stdio.h>

int pow_int(int x, int y) {
    if (x == 0) {
        return 0;
    } else if (y == 0) {
        return 1;
    }

    int k = 1;
    for (int i = 0; i < y; i++) {
        k = k * x;
    }

    return k;

}

void printBits(unsigned int n, int len) {
    // 假設是 32 位元整數，從第 31 位開始
    for (int i = 0; i < len; i++) {
        // 使用右移運算符將第 i 個位元移到最右邊
        int bit = (n >> i) & 1;
        printf("%d ", bit); // 印出該位元
    }
    printf("\n");
}

void printBits_r(const int base_n, const int n, int len) {

    for (int i = 0; i < len; i++) {
        int bit = (base_n >> i) & 1;
        printf("%d ", bit);
    }
    printf("\n");

    for (int i = 0; i < len; i++) {
        int bit = (n >> i) & 1;
        printf("%d ", bit);
    }
    printf("\n");
    
}

unsigned int merge_n(const int base_n, const int n, const int len) {
    unsigned int ans = 0;
    for (int i = len; i >= 0; i--) {
        int n_bit = (n >> i) & 1;
        int base_n_bit = (base_n >> i) & 1;
        int bit = (n_bit + base_n_bit)%2;
        ans = ans << 1;
        ans = ans + bit;
    }
    return ans;
}

int main() {
    int num = 255; // 例如：42 (二進位 00101010)
    unsigned k = 15;
    k = (k >> 1);
    // printf("數值 %d 的位元表示：", num);
    int b = pow_int(2, 4) - 1;

    unsigned int sc = merge_n(num, k, 8);
    // printBits(num, 8);
    // printBits((15 >> 1), 8);
    // printBits((15 << 1), 8);
    // printBits((15 << 1) - (15 >> 0), 8);
    printBits((240 >> 1), 8);
    printBits((240 << 1), 8);
    printBits(~((240 >> 1) - (240 << 1)), 8);
    printf("=============\n");
    printBits((15 >> 1), 8);
    printBits((15 << 1), 8);
    printf("--------------\n");
    printBits(~((15 << 2) - (15 >> 1)), 8);
    printf("------------------\n");
    unsigned int right = (240 << 2);
    unsigned int left = (15 << 2) - (15 >> 1);
    printBits((240 << 0), 8);
    printBits(((15 << 1) - (15 >> 0)) << 0, 8);
    printf("-------------------\n");

    int sn = 15;
    for (int i = 0; i < 3; i++) {
        
        printBits(sn, 8);
        sn = sn + (8 * pow_int(2, i%3));
        // printBits(15 + (8), 8);
    }

    for (int i = 0; i < 3; i++) {
        
        printBits(sn, 8);
        sn = sn + (4 * pow_int(2, i%3));
        // printBits(15 + (8), 8);
    }


    // printBits(15 + (8), 8);
    // printBits(15 + (16), 8);
    // printBits(15 + (24), 8);
    // printBits(~(15 << 3), 8);
    // printBits((240 << 1) - (~(15 << 3)), 8);

    // printBits((15 << 1) - (15 >> 2), 8);
    // printBits(right - left, 8);
    // printBits(((15 << 1) - (15 >> 1)), 8);
    // printBits(sc, 8);
    
    
    // for (int i = 0; i < 16; i++) {
    //     unsigned int c = (pow_int(2, 4) - pow_int(2, (i/4)));// + (b>>i + i);
    //     printBits_r(240, c, 8);
    //     printf("---------------------------\n");
    // }
    // printBits(k);
    return 0;
}