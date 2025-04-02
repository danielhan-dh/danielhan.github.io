//Name: Daniel Han
//Date: 2/28/2023
//Decription: Displays a full menu with options for manipulating
//binary, hexadecimal, octal, and decimal numbers. Uses the bit value
//structures of C types to accomplish this.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "calc.h"


// convert bin str to short; return value
unsigned short get_binary_op (bin_str bin){
    int exp = 1, curr, bit = strlen(bin.bin);
    unsigned short mode = 0;
    for(curr = bit - 1; curr > -1; curr--){
        if(bin.bin[curr] == '1')
            mode = mode + exp;
        exp = exp * 2;
    }
    return mode;
}


// convert val to binary str for output
void convert_to_binary (short val, bin_str bin){
    int i = 0; bin_str temp;
    unsigned short value;
    value = val;
    //Storing the value of binary conversion into a temporary bin_str
    while(value > 0){
        temp.bin[i] = value % 2 + '0';
        value /= 2;
        i++;
    }
    //Copying temporary bin_str into main bin while also placing spaces
    //at set intervals for readability
    for(int k = 0, j = 18; j >= 0 && k < 100; k++, j--){
        if(j == 4 || j == 9 || j == 14){
            bin.bin[j] = ' '; 
            j--;
        }
        if(k >= i)
            bin.bin[j] = '0';  
        else
            bin.bin[j] = temp.bin[k];
    }
    bin.bin[19] = '\0';
    printf("%s", bin.bin);
}


// read in numeric value in mode; return value
short get_operand(char mode){
    short val; bin_str bin;
    switch(mode){
        case 'H':
            printf("Enter hex value: ");
            scanf("%hx", &val);
            break;
        case 'O':
            printf("Enter octal value: ");
            scanf("%ho", &val);
            break;
        case 'D':
            printf("Enter decimal value: ");
            scanf("%hd", &val);
            break;
        case 'B':
            printf("Enter binary value: ");
            scanf("%s", &bin);
            val = get_binary_op(bin);
            break;
    }
    //printf("\n");
    return val;
}


// print out base values and str for mode
void print_bases (short val, char mode){
    //Determines what mode the user set and display the correct string
    char str[4]; bin_str bin;
    switch(mode){
        case 'H':
            strcpy(str, "Hex\0");
            break;
        case 'O':
            strcpy(str, "Oct\0");
            break;
        case 'D':
            strcpy(str, "Dec\0");
            break;
        case 'B':
            strcpy(str, "Bin\0");
            break;
    }
    printf("\n");
    //printing out the menu for the bases
    printf("****************************************\n");
    printf("* Base Values:         Input Mode: ");
    printf("%s", str);
    printf(" *\n");
    printf("*   Binary  :  ");
    convert_to_binary(val, bin);
    printf("     *\n");
    printf("*   Hex     :  ");
    printf("%04hX", val);
    printf("                    *");
    printf("\n");
    printf("*   Octal   :  ");
    printf("%06ho", val);
    printf("                  *");
    printf("\n");
    printf("*   Decimal :  ");
    printf("%-10hd", val);
    printf("              *\n");
    printf("****************************************\n\n");
}


// print menu; get option until valid; return option
char print_menu (void){
    //printing out the options and ui
    printf("Please select one of the following options:\n");
    printf("\n");
    printf("B  Binary Mode             &  AND with Value           +  Add to Value\n");
    printf("O  Octal Mode              |  OR  with Value           -  Subtract from Value\n");
    printf("H  Hexadecimal Mode        ^  XOR with Value           N  Negate Value\n");
    printf("D  Decimal Mode            ~  Complement Value\n");
    printf("\n");
    printf("C  Clear Value            <  Shift Value Left\n");
    printf("S  Set Value              >  Shift Value Right\n");
    printf("\n");
    printf("Q Quit\n");
    printf("\n");
    printf("Option: ");
}


// call get_operand to get value in mode
// to add to val; detect pos/neg overflow
void add (short *val, char mode) {
    short int op = get_operand(mode);
    short int res;
    res = *val + op;
    //Checking if the addition has positive or negative overflow
    if((*val > 0 && op > 0) && res < 0)
        printf("Positive Overflow\n");
    if((*val < 0 && op < 0) && res > 0)
        printf("Negative Overflow\n");
    *val += op;
}


// similar to add, but subtract
void subtract (short *val, char mode) {
    short int op = get_operand(mode);
    short int res;
    res = *val - op;
    //Checking if subtraction has positive or negative overflow
    if((*val > 0 && op < 0) && res < 0 && abs(op) < *val)
        printf("Positive Overflow\n");
    if((*val < 0 && op > 0) && res > 0 && abs(op) > *val)
        printf("Negative Overflow\n");
    *val -= op;
}


// main menu loop; execute option or call 
// appropriate function
int main (void){
    //This initializes the loop until user exits
    //Also takes in input and executes correct functions
    char mode = 'D'; short int val = 0; char option[11]; int exit = 0; char str[5]; 
    int shift;
    while(exit != 1){
        print_bases(val, mode);
        print_menu();
        scanf("%s", &option);
        option[0] = toupper(option[0]);
        //checking if the user input is a valid option
        if(strlen(option) != 1){
            printf("\n");
            printf("Invalid option: ");
            printf("%s", option);
            printf("\n\n");
        }
        else{
            switch(option[0]){
                //getting which mode
                case 'B':
                    printf("Mode is Binary\n");
                    mode = 'B';
                    break;
                case 'O':
                    printf("Mode is Octal\n");
                    mode = 'O';
                    break;
                case 'H':
                    printf("Mode is Hexadecimal\n");
                    mode = 'H';
                    break;
                case 'D':
                    printf("Mode is Decimal\n");
                    mode = 'D';
                    break;
                case 'C':
                    val = 0;
                    printf("\n");
                    break;
                //Outputting text for different modes
                case 'S': 
                    val = get_operand(mode);
                    break;
                case '&':
                    val &= get_operand(mode);
                    break;
                case '|':
                    val |= get_operand(mode);
                    break;
                case '^':
                    val ^= get_operand(mode);
                    break;
                case '+':
                    add(&val, mode);
                    break;
                case '-':
                    subtract(&val, mode);
                    break;
                case '<':
                    printf("Enter number of positions to left shift value: ");
                    scanf("%d", &shift);
                    val = val << shift;
                    break;
                case '>':
                    printf("Enter number of positions to right shift value: ");
                    scanf("%d", &shift);
                    val = val >> shift;
                    break;
                case '~':
                    val = ~val;
                    break;
                case 'N':
                    val = -val;
                    break;
                case 'Q':
                    exit = 1;
                    break;
                default: //Default option if string input is not contained within the valid options
                    printf("\n");
                    printf("Invalid option: ");
                    printf("%s", option);
                    printf("\n\n");
            }
        }
    }
}