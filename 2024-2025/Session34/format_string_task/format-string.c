#include <stdio.h>

void vuln() {
    char buffer[128];
    const char* flag = "FLAG{format_string_leak_success}";

    printf("Enter your input:\n");
    fgets(buffer, sizeof(buffer), stdin);
    printf(buffer); // Format string vulnerability
}

int main() {
    vuln();
    return 0;
}
