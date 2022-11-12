#include "Search.h"

int SearchSeq(SSTable ST, ElemType key) {
    int res;
    for (res = 0; res < ST.length && ST.data[res] != key; res++)
        ;
    return res == ST.length ? -1 : res;
}

int SearchBinary(SSTable ST, ElemType key) {
    int low = 0, high = ST.length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ST.data[mid] == key) {
            return mid; //查找成功返回
        } else if (ST.data[mid] > key) {
            high = mid - 1; //在前半部分进行查找
        } else {
            low = mid + 1; //查找后半部分
        }
    }
    return -1; //失败返回-1
}
