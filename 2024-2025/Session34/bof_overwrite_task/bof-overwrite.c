#include <stdio.h>
#include <string.h>

void check_flag(unsigned int value) {
    if (value == 0xd00df00d) {
        printf("You changed the variable! FLAG{buffer_overflow_success}\n");
    } else {
        printf("Try again! Value is: 0x%x\n", value);
    }
}

void vuln() {
    char buffer[64];
    unsigned int secret = 0xdeadbeef;

    printf("Overflow the buffer and change the value of 'secret'\n");
    // Overflow attempt: reads more than buffer size
    fgets(buffer, 256, stdin);

    check_flag(secret);
}

int main() {
    vuln();
    return 0;
}
