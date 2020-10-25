#include "GUIAPI_Array.h"
#include "stdio.h"

int array_tests_passed = 0;

int main(){
    GUIAPI_Array<int> firstTest;

    //Testing new object
    if(firstTest.capacity() <= 0){
        printf("Array length is not right %lu, more then 0 expected.\r\n", firstTest.capacity());
        return -1;
    }
    array_tests_passed++;
    printf("%d. New array object test is passed. Array capacity: %lu, Array length: %lu\r\n", array_tests_passed, firstTest.capacity(), firstTest.length());

    //Testing append new element
    firstTest.append(43);
    if(firstTest[0] != 43){
        printf("Appended element is not right.\r\n");
        return -2;
    }
    array_tests_passed++;
    printf("%d. Element %d successfully appended! New array length is %lu\r\n", array_tests_passed, firstTest[0], firstTest.length());

    //Testing appending elements more then is array started size
    for(uint32_t i = 0; i < 15; i++)
        firstTest.append(i);
    if(firstTest.length() != 16){
        printf("Number of appended elements is not right.\r\n");
        return -3;
    }
    for(uint32_t i = 0; i < firstTest.length(); i++)
        printf("%d ", firstTest[i]);
    printf("\r\n");
    array_tests_passed++;
    printf("%d. 15 elements appended! New array length is %lu and capacity is %lu\r\n", array_tests_passed, firstTest.length(), firstTest.capacity());

    //Testing new array creating using second constructor with capacity
    GUIAPI_Array<int> secondTest(20);
    if(secondTest.capacity() != 20){
        printf("New array capacity is not right, 20 required.\r\n");
        return -4;
    }
    array_tests_passed++;
    printf("%d. Testing new array creating using second constructor with capacity %lu is passed\r\n", array_tests_passed, firstTest.capacity());

    //Testing appending, if number of appended elements is same with capacity
    for(uint32_t i = 0; i < secondTest.capacity(); i++)
        secondTest.append(i);
    for(uint32_t i = 0; i < secondTest.length(); i++)
        printf("%d ", secondTest[i]);
    printf("\r\n");
    if(secondTest.capacity() != secondTest.length()){
        printf("Appending error.\r\n");
        return -5;
    }
    array_tests_passed++;
    printf("%d. Testing appending, if number of appended elements is same with capacity %lu/%lu is passed\r\n", array_tests_passed,  secondTest.length(), secondTest.capacity());

    //Testing operator=
    firstTest = secondTest;
    if(firstTest.length() != secondTest.length()){
        printf("Copying array error.\r\n");
        return -6;
    }
    array_tests_passed++;
    printf("%d. Testing operator= is passed. %lu/%lu\r\n", array_tests_passed,  firstTest.length(), secondTest.length());

    printf("All array tests passed.\r\n");
    return 0;
}