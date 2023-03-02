////////////////////////////////////////////
///                 STRUCTS              ///
////////////////////////////////////////////

#include <stdio.h>

enum opal_card_type {
    ADULT,
    STUDENT,
    CONCESSION,
};

// STEP 1: DEFINITION   

// Example struct of a person with 3 fields
struct person {
    int shoe_size;
    double height;
    char first_name_initial;
    enum opal_card_type card_type;
};

int main(void) {

    // STEP 2: DECLARATION
    // --insert here--
    struct person tom;
    struct person bob;
    /*      
       ⬇           ⬇
       type        name given to variable
    (of variable)*/  

    // STEP 3: INITIALISATION
    // ---insert here---
    tom.shoe_size = 10;
    tom.height = 15.1;
    tom.first_name_initial = 't';
    tom.card_type= STUDENT;

    bob.shoe_size = 9;
    bob.height = 160.0;
    bob.first_name_initial = 'b';
    bob.card_type = CONCESSION;

    // Print out values for each person
    printf("%d, %.3lf, %c\n", 
        tom.shoe_size, tom.height, tom.first_name_initial);

    printf("%d, %.2lf, %c\n", 
        bob.shoe_size, bob.height, bob.first_name_initial);
    return 0; 
}

