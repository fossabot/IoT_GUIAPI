#include "GUIAPI_String.h"
#include "stdio.h"

int string_tests_passed = 0;

int test_string(){
    //New string object from char array
    GUIAPI_String firstTest("Hello world!");
    if (firstTest.length() < 0){
        printf("String length is not right %lu, more then 0 expected.\r\n", firstTest.length());
        return -1;
    }
    string_tests_passed++;
    printf("%d. New string object from char array test is passed\r\n", string_tests_passed);

    //New string object from char array and array size
    GUIAPI_String secondTest("Hello world!", 12);
    if(firstTest != secondTest){
        printf("Same string is not compatable: %s/%s\r\n", firstTest.toC_str(), secondTest.toC_str());
        return -2;
    }
    string_tests_passed++;
    printf("%d. New string object from char array and array size test is passed\r\n", string_tests_passed);

    //Checking how works automatically string length determinatoin
    if(firstTest.length() != secondTest.length()){
        printf("Length of same strings is not the same: %lu/%lu.\r\n", firstTest.length(), secondTest.length());
        return -3;
    }
    string_tests_passed++;
    printf("%d. Checking how works automatically string length determinatoin test is passed\r\n", string_tests_passed);
    
    //Testing operator= with const char
    firstTest = "New string";
    if(firstTest.length() == secondTest.length()){
        printf("First string was changed, but length is the same: %lu/%lu.\r\n", firstTest.length(), secondTest.length());
        return -4;
    }
    string_tests_passed++;
    printf("%d. operator= const char* test is passed\r\n", string_tests_passed);

    //Testing operator= with string class
    firstTest = secondTest;
    if(firstTest != secondTest){
        printf("Strings is not the same. Expected same strings.\r\n");
        return -5;
    }
    string_tests_passed++;
    printf("%d. operator= string test is passed\r\n", string_tests_passed);

    printf("All string tests is passed!\r\n");

    return 0;
}