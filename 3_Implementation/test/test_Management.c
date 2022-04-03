#include"Contact_Managment_system.h"
#include"unity_internals.h"
#include"unity.h"

void setUp(){}

void tearDown(){}


void test_addContact(void){
    TEST_ASSERT_EQUAL(pass,addContact("hari", 1234567890, "abc colony","hari@123.com"));
}

void test_viewContact(void){
    TEST_ASSERT_EQUAL(pass,viewList());
}

void test_searchContact(void){
    TEST_ASSERT_EQUAL(fail,searchContact("hari"));
    TEST_ASSERT_EQUAL(pass,searchContact("hari"));
}



void test_deleteContact(void){
    TEST_ASSERT_EQUAL(pass,deleteContact("hari"));
}        

void test_editContact(void){
    TEST_ASSERT_EQUAL(pass,editContact("hari"));
}

int main(){
    UNITY_BEGIN();

    RUN_TEST(test_addContact);
    RUN_TEST(test_searchContact);
    RUN_TEST(test_editContact);
    RUN_TEST(test_deleteContact);
    RUN_TEST(test_viewList);
    
    return UNITY_END();
}
