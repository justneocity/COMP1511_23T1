//Program that enciphers and deciphers a message
//on feb 20, 2023
//by Aastha Sharma, z5444661
#include <stdio.h>
#include<stdlib.h>
struct message {
    char letter1;
    char letter2;
    char letter3;
    char letter4;
};

// You may find it helpful to add extra procedures here. Procedures that
// encipher/decipher the entire `msg` may be useful.
//
// Likewise, procedures that encipher/decipher single letters will help reduce
// code repetition. It is completely up to you whether to create these
// procedures, but we *highly* recommend you do for practice!
// Determines cyphering for a given msg and prints out the result
char encipher(char hehe, int n) {
    char final;
    if (hehe >= 'A' && hehe <= 'Z') {
        if (hehe % 'A' + n < 0) {
            final = ((hehe % 'A' + n) % 26) + 'A' + 26;
        } else {
            final = ((hehe % 'A' + n) % 26) + 'A';
        }
    } else if (hehe >= 'a' && hehe <= 'z') {
        if (hehe % 'a' + n < 0) {
            final = ((hehe % 'a' + n) % 26) + 'a' + 26;
        } else {
            final = ((hehe % 'a' + n) % 26) + 'a';
        }
    }
    return final;
}

char decipher(char hehe, int n) {
    char final;
    if (hehe >= 'A' && hehe <= 'Z') {
        if (hehe % 'A' - n < 0) {
            final = ((hehe % 'A' - n) % 26) + 'A' + 26;
        } else {
            final = ((hehe % 'A' - n) % 26) + 'A';
        }
    } else if (hehe >= 'a' && hehe <= 'z') {
        if (hehe % 'a' - n < 0) {
            final = ((hehe % 'a' - n) % 26) + 'a' + 26;
        } else {
            final = ((hehe % 'a' - n) % 26) + 'a';
        }
    }
    return final;
}

void determine_ciphering(struct message msg) {
    int num1, num2, num3, num4;
    printf("Would you like to encipher or decipher this message (e/d)? ");
    char choice;
    scanf(" %c", &choice);
    int i = 0;
    while (i < 4) {

    }
    if (choice == 'e') {
        printf("Enter numbers to encipher by: ");
        scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
        char ans1 = encipher(msg.letter1, num1);
        char ans2 = encipher(msg.letter2, num2);
        char ans3 = encipher(msg.letter3, num3);
        char ans4 = encipher(msg.letter4, num4);
        printf("%c%c%c%c\n", ans1, ans2, ans3, ans4);
    } else if (choice == 'd') {
        printf("Enter numbers to decipher by: ");
        scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
        char ans1 = decipher(msg.letter1, num1);
        char ans2 = decipher(msg.letter2, num2);
        char ans3 = decipher(msg.letter3, num3);
        char ans4 = decipher(msg.letter4, num4);
        printf("%c%c%c%c\n", ans1, ans2, ans3, ans4);
    }
}
//////////////////////////////////////////////////////////////////////////////
//
///////////////////// DO NOT EDIT THIS MAIN FUNCTION
///////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// This main function scans a message and then calls your determine_ciphering
// procedure, passing in the message.
int main(void) {
    struct message msg;
    // Scan message into `msg` struct
    printf("Message: ");
    scanf(
        "%c %c %c %c",
        &msg.letter1, &msg.letter2, &msg.letter3, &msg.letter4
    );
    // Call your determine_ciphering function and pass in the message.
    determine_ciphering(msg);
}

