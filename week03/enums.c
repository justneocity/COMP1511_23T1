#include <stdio.h>

// STEP 1: DEFINITION
enum opal_card_type {
    ADULT,
    STUDENT,
    CONCESSION,
};

/* This is the same as:
#define ADULT 0
#define STUDENT 1
#define CONCESSION 2
*/

// What if we want to start enumeration not at 0?

int main(void) {

    // STEP 2: DECLARATION
    enum opal_card_type card_type;
    int random = 1
    /*               
        ⬇                 ⬇
    type or variable     name given to variable */

    // STEP 3: INITIALISATION
    card_type = 1;
    if (card_type == STUDENT) {
        ...
    }
    
    
}