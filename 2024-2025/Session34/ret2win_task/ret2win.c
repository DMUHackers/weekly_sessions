#include <stdio.h>
#include <string.h>

void win() {
    printf("You called win()! Here's your flag: FLAG{ret2win_success}\n");
}

void vuln() {
    char buffer[64];
    printf("Enter some text:\n");
    // Intentionally reading too much to allow overflow
    fgets(buffer, 256, stdin);
}

int main() {
    vuln();
    printf("Returning from main...\n");
    return 0;
}
