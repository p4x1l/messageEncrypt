#include <stdio.h>

#define ALPHABET_SIZE 26

void encrypt(char* message, int key) {
    int i = 0;
    char ch;

    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key) % ALPHABET_SIZE + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key) % ALPHABET_SIZE + 'A';
        }

        message[i] = ch;
        i++;
    }
}

void decrypt(char* message, int key) {
    encrypt(message, ALPHABET_SIZE - key);
}

int main() {
    char message[] = "Hello, World!";
    int key = 3;

    printf("Original Message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
