#include<stdio.h>
#include<stdlib.h>


int add_bits(int a, int b) {

    int carry;
    while (b != 0)
    {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
    

}



int main() {

    printf("55 + 57 = %d, %d", (55 + 27), add_bits(55, 27));
}