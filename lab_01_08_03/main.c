#include <stdio.h>

#define mask_1 0b10101010101010101010101010101010
#define mask_2 0b01010101010101010101010101010101

void to_bin(unsigned int value)
{
    if (!value) return;
    to_bin(value / 2);
    printf("%d", value % 2);
}

int main(void)
{
    unsigned int number;
    scanf("%u", &number);
    unsigned int to_left = number << 1;
    unsigned int to_right = number >> 1;

    unsigned int new_number = (to_left & mask_1) | (to_right & mask_2);
    
    if (new_number)
    {
        to_bin(new_number);
    }
    else
    {
        printf("0");
    }
    printf("\n");

    return 0;
}

