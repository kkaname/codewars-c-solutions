#include <stdio.h>

int beeramid(double bonus, double price);

int main(void) {
    double bonus, price;

    bonus = 1500.00;
    price = 2.00;
    int result = beeramid(bonus, price);
    printf("bonus = %.2f, price = %.2f, result = %d\n", bonus, price, result);

    bonus = 5000.00;
    price = 3.00;
    result = beeramid(bonus, price);
    printf("bonus = %.2f, price = %.2f, result = %d\n", bonus, price, result);

    return 0;
}

int beeramid(double bonus, double price) {
    if (bonus <= 0 || price <= 0) {
        return 0;
    }

    int level = 0;

    while ((double)level * (level + 1) * (2 * level + 1) / 6.0 * price <= bonus) {
        ++level;
    }

    return level - 1;
}
