#include <iostream>
using namespace std;

#include "SocketProtocol.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

void swaps_(int* num1, int* num2);

int sckSendAndRec(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen) {
    return 0;
}

void main_bk1() {
    CSocketProtocol *sp = NULL;
    unsigned char in[4096];
    FILE* stream;
    FILE* stream2;
    errno_t err;
    //Openforread(willfailiffile"crt_fopen_s.c"doesnotexist)
    err = fopen_s(&stream, "crt_fopen_s.txt", "w");
    if (err == 0)
    {
        printf("Thefile'crt_fopen_s.c'wasopened\n");
    }
    else
    {
        printf("Thefile'crt_fopen_s.c'wasnotopened\n");
    }


    std::string ss = "AAA";
    //for(int i=0; i<5; i++)
    fwrite(&ss, 1, sizeof(ss), stream);

    char s2[100];

    err = fopen_s(&stream2, "crt_fopen_s.txt", "r");
    if (err == 0)
    {
        printf("Thefile'crt_fopen_s.c'wasopened\n");
    }
    else
    {
        printf("AA Thefile'crt_fopen_s.c'wasnotopened\n");
    }

    fread(&s2, 1, sizeof(ss), stream2);

    if (s2 != nullptr)
        cout << s2 << endl;
    else 
        cout << "s2 is null" << endl;
    cout << "hello..." << endl;
    fclose(stream);
    fclose(stream2);
    //system("pause");
    return;
}

void main_bk2() {
    FILE* fp;
    fp = fopen("hello.ttx", "wb+");
    string ss = "AAAA";
    fwrite(&ss, 1, sizeof(ss), fp);

    fp = fopen("hello.ttx", "rb+");
    
    char s1[10];
    fread(&s1, 1, sizeof(ss), fp);

    //cout << s1 << endl;
    puts(s1);


    fclose(fp);
}

void helan(int* arr, int n) {
    int start = 0, curr = 0;
    int end = n - 1;

    while (curr <= end)
    {
        if (arr[curr] == 0) {
            swaps_(&arr[start], &arr[curr]);
            start++;
            curr++;
        }
        else if (arr[curr] == 1) {
            curr++;
        }
        else
        {
            swaps_(&arr[curr], &arr[end]);
            end--;
        }
    }
}

void swaps_(int* num1, int* num2) {
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

/*quick sort*/
int partition(int* arr, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    while (true)
    {
        while (arr[++i] < arr[lo]) {
            if (i > hi)
                break;
        }

        while (arr[--j] > arr[lo]) {
            if (j < lo)
                break;
        }

        if (i >/*=*/ j)
            break;

        swaps_(&arr[i], &arr[j]);
    }
    /*i以及之后的数比arr[lo]大，j以及之前的数比arr[lo]小
      j位置的数比arr[lo]小
    */
    swaps_(&arr[lo], &arr[j]);
    return j;
}

void quicksort(int* arr, int lo, int hi) {
    if (lo > hi)
        return;
    int index = partition(arr, lo, hi);
    quicksort(arr, lo, index - 1);
    quicksort(arr, index+ 1, hi);
}
int main_mainclass() {

    int len = 0;
    /* debug 荷兰国旗
    int arr[12] = { 2, 1, 2, 0, 2, 1, 0, 2, 1, 0, 2 };
    GET_ARRAY_LEN(arr, len);
    helan(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    */

    /*debug quick sort
    int arr[10] = { 4, 3, 7, 9, 6, 1, 2, 5, 8 };
    quicksort(arr, 0, 8);
    GET_ARRAY_LEN(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    */
    return -1;
}