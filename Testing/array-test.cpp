#include "GUIAPI_Array.h"
#include "stdio.h"


int main(){
    GUIAPI_Array<int> firstTest;

    //Testing new object
    if(firstTest.capacity() <= 0){
        printf("New object creation test is failed.\r\n", firstTest.capacity());
        return -1;
    }

    //Testing append new element
    firstTest.append(43);
    if(firstTest[0] != 43){
        printf("Appending test is failed.\r\n");
        return -2;
    }

    //Testing appending elements more then is array started size
    for(uint32_t i = 0; i < 15; i++)
        firstTest.append(i);
    if(firstTest.length() != 16){
        printf("Multiple appending test is failed.\r\n");
        return -3;
    }
    for(uint32_t i = 0; i < firstTest.length(); i++)
        printf("%d ", firstTest[i]);
    printf("\r\n");

    //Testing new array creating using second constructor with capacity
    GUIAPI_Array<int> secondTest(20);
    if(secondTest.capacity() != 20){
        printf("Capasity initialization test is failed.\r\n");
        return -4;
    }

    //Testing appending, if number of appended elements is same with capacity
    for(uint32_t i = 0; i < secondTest.capacity(); i++)
        secondTest.append(i);
    for(uint32_t i = 0; i < secondTest.length(); i++)
        printf("%d ", secondTest[i]);
    printf("\r\n");
    if(secondTest.capacity() != secondTest.length()){
        printf("Multiple appending test and operator[] test is failed.\r\n");
        return -5;
    }

    //Testing operator=
    firstTest = secondTest;
    if(firstTest.length() != secondTest.length()){
        printf("Operator= test is failed.\r\n");
        return -6;
    }

    //Testing fill, front & back methods
    GUIAPI_Array<int> thirdTest;
    thirdTest.fill(28);
    if(thirdTest.front() != thirdTest.back()){
        printf("Filling array test is failed.\r\n");
        return -7;
    }

    //Testing empty
    thirdTest.empty();
    if(thirdTest.length() != 0){
        printf("Empty array test is failed.\r\n");
        return -8;
    }

    //thirdTest = {1, 2, 3};

    printf("All array tests passed.\r\n");
    return 0;
}