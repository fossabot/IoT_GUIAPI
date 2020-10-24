#ifndef __GUIAPI_ARRAY__
#define __GUIAPI_ARRAY__

#include "stdint.h"

template<class T>
class GUIAPI_Array{

public:
    GUIAPI_Array();
    GUIAPI_Array(uint32_t arraySize);
    ~GUIAPI_Array();

    void append(T item);

    GUIAPI_Array& operator=(const GUIAPI_Array& nArray){
        if(nArray.arraySize > this->arraySize){
            free(items);
            this->arraySizeMax = nArray.arraySize + 3;
            this->arraySize = nArray.arraySize;
            items = (T*)calloc(this->arraySizeMax, sizeof(T));
        }
        for(uint32_t i = 0; i < nArray.arraySize; i++)
            this->items[i] = nArray[i];
        return *this;
    }

    T& operator[](int index){
        if(index > 0 && index < arraySizeMax){
            return items[index];
        }
        return NULL;
    }

private:
    uint32_t arraySize;
    uint32_t arraySizeMax;

    T *items;
};


#endif