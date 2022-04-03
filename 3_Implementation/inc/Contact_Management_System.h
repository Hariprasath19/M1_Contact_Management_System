/**
 * @file Contact_Managment_system.h

 */

#ifndef __CONTACT_MANAGEMENT_SYSTEM_H__
#define __CONTACT_MANAGEMENT_SYSTEM_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
 * @brief structure for CONTACT
 * 
 */
typedef struct contact
{
    int name[20];
    long ph;
    char address[20];
    char email[30];
}list;

/**
 * @brief return type for funtions for unit testing
 * 
 */

typedef enum test_values {
    pass = 1,
    fail = 0
}test_values;

/**
 * @brief function to find a book by its ID
 * @param id 
 * @return test_values 
 */
test_values searchContact(char name);

/**
 * @brief function to  add a  Contact
 * 
 * @return test_values 
 */
test_values addContact(char name[20],long ph,char address[20],char email[30]);

/**
 * @brief funtion to denote  discarded Contacts
 * 
 * @param id 
 * @return test_values 
 */
test_values deleteContact(char name);

/**
 * @brief function to modify the Contacts
 * 
 * @return test_values 
 */
test_values editContact(char name[20],long ph,char address[20],char email[30]);

/**
 * @brief function to view all the Contacts
 * 
 * @return test_values 
 */
test_values viewContact(void);

#endif
