#include <stdio.h>
#include <string.h>
#define INPUT 0x2BEF
#define INPUT2 0xBDAB

int lookup_result[2]; //0 - carry, 1 - recoded

int *lookup(int next, int current, int carry) {
        int compound = next * 4 + current * 2 + carry;
        lookup_result[0] = 0;
        lookup_result[1] = 0;
        switch(compound) {
                case 3:
                case 7:
                        lookup_result[0] = 1;
                case 5:
                case 6:
                        lookup_result[1] = -1;
                        lookup_result[0] = 1;
                        break;
                case 1:
                case 2:
                        lookup_result[1] = 1;
                        break;
        }
        return lookup_result;
}

int main() {
        /*
        read in the input char by char
        first carry in is 0
        match current bit and carry in with table
        output recided bit and carryout
        */
        int input = INPUT;
        int carry = 0, current= input & 1, next = input & 2;
        int *lookup_results;
        int output[32];
        memset(output, 0, 32*sizeof(int));
        int currentdigit = 0;
        while (input != 0) {
                current = input & 1;
                next = input & 2;
                lookup_results = lookup(next, current, carry);
                carry = lookup_results[0];
                output[currentdigit] = lookup_results[1];
                currentdigit++;
                input = input >> 1;
        }
        int i;
        for(i = 0; i < 32; i++) {
                printf("%d, ", output[i]);
        }
        return 0;
}
        
        