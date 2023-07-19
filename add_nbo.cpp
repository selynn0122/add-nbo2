#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (!file1 || !file2) {
        printf("Error opening files.\n");
        return 1;
    }

    uint32_t num1, num2;

    fread(&num1, sizeof(num1), 1, file1);
    fread(&num2, sizeof(num2), 1, file2);

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

    fclose(file1);
    fclose(file2);

    return 0;
}

