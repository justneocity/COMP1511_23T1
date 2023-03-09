// Message Cipher
// by Sarah Cheng (z5479654)
// on 26/02/2023
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define ENCIPHERING true
#define DECIPHERING false
#define UP_ASCII_POS 64
#define LOW_ASCII_POS 96
struct message {
 char char1;
 char char2;
 char char3;
 char char4;
};
char new_letter(bool is_enciphering, char letter, int number) {
 bool is_upper = isupper(letter);
 // takes the position of the uppercase letter
 int current_position = toupper(letter) - 64;
 if (is_enciphering) {
 // goto is not permitted T-T
 while (number != 0) {
 if (number > 0) {
 // equivalent to the last letter (a)
 if (current_position == 27)
 current_position = 1;
 current_position++;
 number--;
 }
 else {
 // equivalent to the last letter (z)
 if (current_position == 0)
 current_position = 26;
 current_position--;
 number++;
 }
 }
 }
 else {
 while (number != 0) {
 if (number > 0) {
 if (current_position == 0)
 current_position = 26;
 current_position--;
 number--;
 }
 else {
 if (current_position == 27)
 current_position = 1;
 current_position++;
 number++;
 }
 }
 }

 char encoded_letter;
 if (is_upper)
 encoded_letter = current_position + UP_ASCII_POS;
 else
 encoded_letter = current_position + LOW_ASCII_POS;
 return encoded_letter;
}
void encode(bool is_enciphering, struct message msg) {
 int number1;
 int number2;
 int number3;
 int number4;
 scanf("%d %d %d %d", &number1, &number2, &number3, &number4);
 struct message new_message;
 new_message.char1 = new_letter(is_enciphering, msg.char1, number1);
 new_message.char2 = new_letter(is_enciphering, msg.char2, number2);
 new_message.char3 = new_letter(is_enciphering, msg.char3, number3);
 new_message.char4 = new_letter(is_enciphering, msg.char4, number4);

 printf("%c%c%c%c \n",
 new_message.char1, new_message.char2,
 new_message.char3, new_message.char4);
}
// Determines ciphering for a given message and prints out the result
void determine_ciphering(char letter1, char letter2, char letter3, char letter4) {

 struct message Message;
 Message.char1 = letter1;
 Message.char2 = letter2;
 Message.char3 = letter3;
 Message.char4 = letter4;
 printf("Would you like to encipher or decipher this message (e/d)? ");

 char selected_option;
 scanf(" %c", &selected_option);

 if (selected_option == 'e') {
 printf("Enter numbers to encipher by: ");
 encode(ENCIPHERING, Message);
 }
 else {
 printf("Enter numbers to decipher by: ");
 encode(DECIPHERING, Message);
 }

}
////////////////////////////////////////////////////////////////////////////////
///////////////////// DO NOT EDIT THIS MAIN FUNCTION ///////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(void) {
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