#include "string_testing.h"
#include "array_testing.h"

int string_result = 0;
int array_result = 0;

int main(){
    array_result = test_array();
    string_result = test_string();
    if(array_result == 0 && string_result == 0){
        return 0;
    }else{
        return -1;
    }
    
}