/**
 * @file q3.c
 * @author Student
 * @brief User registration system with three different registration types
 * 
 * This program simulates a user registration system with three registration types:
 * 1. Username registration (max 10 characters)
 * 2. Phone number registration (11 digits starting with 13)
 * 3. Serial number registration (4-digit hex staring with A)
 * 
 * @version 0.1
 * @date 2025-11-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/**
 * @brief Main fuction that implements the registration system
 * 
 * The program randomly selects one of three registration types and prompts
 * the user for appropriate input. Each input is validated according to
 * specific criteria for that registration type.
 * 
 * @return int Return 0 on successful execution 
 */
int main(void)
{
    srand(time(NULL)); ///< Seed the random number generator with current time    

    int num = rand() % 3 + 1; ///< Generate random number 1-3 for registration type

    /**
     * @brief Construct a new switch object to handle different registration types
     * 
     * case 1: Username registration
     * case 2: Phone number registration
     * case 3: Serial number registration
     */

    switch(num){
        case 1:
            printf("Please input your name:");
            
            char username[20]; ///< Buffer for username input
                
            scanf("%19s", username); ///< Read username with buffer overflow protection
            
            /**
             * @brief Validate username length
             * 
             * Username must be no more than 10 characters long
             */
            if(strlen(username) <= 10){
                printf("Registration Successful\n");
            }else{
                printf("Registration Failed\n");
            }
    
            break;
        
        case 2:
            printf("Please input your phone number:");

            long long unsigned int phone_num; ///< Store 11-digit phone number

            int phone_counter = scanf("%llu", &phone_num); ///< Read phone number
            
            /**
             * @brief Validate phone number format
             * 
             * Phone number must be:
             * - Successfully read by scanf
             * - Exactly 11 digits (between 10^10 and 10^11-1)
             */
            if(phone_counter != 1 || phone_num < 10000000000LL || phone_num >= 100000000000LL){
                printf("Registration Failed\n");
                break;
            }else{
                int first_two_digits = phone_num / 1000000000LL; ///< Extract first two digits

                /**
                 * @brief Validate phone number starts with 13
                 */
                if(first_two_digits == 13){
                    printf("Registration Successful\n");
                    break;
                }else{
                    printf("Registration Failed\n");
                    break;
                }
            }

        case 3:
            printf("Please input your serial number:");

            unsigned int serial_num; ///< Store serial number

            int right_serial_num = scanf("%x", &serial_num); ///< Read hex serial number
            
            /**
             * @brief Validate serial number was successfully read
             */
            if(right_serial_num != 1){
                printf("Registration Failed\n");
                break;
            }
            
            /**
             * @brief Validate serial number format
             * 
             * Serial number must be:
             * - 4-digit hexadecimal (0x0000 to 0xFFFF)
             * - Start with hexadecimal digit A (0xAxxx)
             */
            if(serial_num<=0xFFFF){
                /**
                 * @brief Extract and validate highest 4 bits equal 0xA
                 * 
                 * Right shift by 12 bits to get the higheat 4 bits (nibble)
                 * Mask with 0xF to isolate those 4 bits
                 */
                if(((serial_num >> 12) & 0xF) == 0xA){
                    printf("Registration Successful\n");
                    break;
                }else{
                    printf("Registration Failed\n");
                    break;
                }
            }else{
                printf("Registration Failed\n");
                break;
            }

        default:{
            break;
        }            
    }
    
    return 0; ///< Successful program termination
}