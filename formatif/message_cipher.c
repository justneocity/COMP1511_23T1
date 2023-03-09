// Message Cipher 
// message_cipher.c
// This program was written by Anna Dong (z5476230) 
// on 24/02/23 
// scans in a message and either enciphers or deciphers it 

#include <stdio.h>

// to convert the charcater into its index form 
int translate(char c) {      
    //if character is uppercase     
    if (c <= 'Z') {         
        return c - 'A';     
    } else {         
        return c - 'a';     
    } 
}

char encipher(char letter, int num) {     
    // getting rid of overlaps     
    if (num > 26 || num < -26) {         
        num = num % 26;     
    }     
    // feature to deal with wrapping around alphabet     
    // when result is past z     
    if ((translate(letter)) + num > 26) {         
        letter = ('A' - 1) + num - ('Z' - letter);         
        //when result is before a     
    } else if ((translate(letter)) + num < 0) {         
        letter = ('Z' + 1) + num - ('A' - letter);     
    } else {         
        letter += num;     
    }     
    return letter; 
}

// Determines ciphering for a given message and prints out the result 
void determine_ciphering(char letter1, char letter2, char letter3, char letter4)  {     
    //encrypt or decrypt     
    char eord = 'e';     
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;    
    //decipher: 1 is false (enciphering), -1 is true (deciphering)     
    int decipher = 1;      
    printf("Would you like to encipher or decipher this message (e/d)? ");     
    scanf(" %c", &eord);     
    if (eord == 'd') {         
        decipher = -1;         
        printf("Enter numbers to decipher by: ");    
    } else {         
        printf("Enter numbers to encipher by: ");     
    }      
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);     
    letter1 = encipher(letter1, num1 * decipher);     
    letter2 = encipher(letter2, num2 * decipher);     
    letter3 = encipher(letter3, num3 * decipher);     
    letter4 = encipher(letter4, num4 * decipher);     
    printf("%c%c%c%c\n", letter1, letter2, letter3, letter4); 
}

// DO NOT EDIT THIS MAIN FUNCTION //
// This main function scans a message and then calls your determine_ciphering 
// procedure, passing in the message. 

int main(void) {    
    // Have a think about how we might implement this with a struct message     
    // once we've covered structs in the Thursday lecture!     
    char letter1;     
    char letter2;     
    char letter3;     
    char letter4;     
    // Scan message into the four characters     
    printf("Message: ");     
    scanf(         
        "%c %c %c %c",         
        &letter1, &letter2, &letter3, &letter4     
    );

    // Call your determine_ciphering function and pass in the message.     
    determine_ciphering(letter1, letter2, letter3, letter4); 
}