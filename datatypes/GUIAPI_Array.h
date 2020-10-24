#ifndef __GUIAPI_ARRAY__
#define __GUIAPI_ARRAY__

#include "stdint.h"
#include "stdlib.h"

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
            this->arraySizeMax = nArray.arraySizeMax;
            items = (T*)calloc(this->arraySizeMax, sizeof(T));
        }

        this->arraySize = nArray.arraySize;
        move(nArray.items, this->items, nArray.arraySize);
        return *this;
    }

    T& operator[](int index){
        if(index > 0 && index < arraySizeMax){
            return items[index];
        }
        return NULL;
    }

private:
    void move(T* from, T* to, uint32_t mSize);
    uint32_t arraySize;
    uint32_t arraySizeMax;

    T *items;
};


#endif