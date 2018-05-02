#include <stdio.h>
#include <string.h>
#define INPUT 0x2BEF
#define INPUT2 0xBDAB

//int lookup_result[2]; //0 - carry, 1 - recoded

int *lookup(int next, int current, int carry, int lookup_result[]) {
        int compound = next * 4 + current * 2 + carry;
        lookup_result[0] = 0;
        lookup_result[1] = 0;
        switch(compound) {
                case 3:
                case 7:
                        lookup_result[0] = 1;
                        break;

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

void convert(int input, int output[]) {
        int carry = 0;
        int current = input & 1;
        int next = (input & 2) >> 1;
        int lookup_results[2];
      
        int currentdigit = 0;
        while (input != 0) {
                current = input & 1;
                next = (input & 2) >> 1;
                lookup(next, current, carry, lookup_results);
                carry = lookup_results[0];
                output[currentdigit] = lookup_results[1];
                currentdigit++;
                input = input >> 1;
        }
}

int main() {
        /*
        read in the input char by char
        first carry in is 0
        match current bit and carry in with table
        output recided bit and carryout
        */
        int output[32];
        memset(output, 0, 32*sizeof(int));
        
        convert(INPUT, output);
        int i;
        for(i = 31; i >= 0; i--) {
                printf("%d, ", output[i]);
        }
        printf("\n");
        convert(INPUT2, output);
        for(i = 31; i >= 0; i--) {
                printf("%d, ", output[i]);
        }
        return 0;
}
        
        