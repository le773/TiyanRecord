#include "SortHeap.h"

SortHeap::SortHeap()
{
}


SortHeap::~SortHeap()
{
}

void swapAB(int* a, int* b) {
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
* len 数组长度, 包括占位符arr[0]
*/
void sinkOrder(int* arr, int k, int top) {
    while (k * 2 + 1 <= top) { // 2k+1
        int j = 2 * k;
        if (j < LEN && arr[j] < arr[j + 1])
            j++;
        if (arr[k] > arr[j])
            break;
        else
            swapAB(&arr[k], &arr[j]);
        k = j;
    }
}


void sortHeapSink(int* arr) {

    // build max heap
    for (int i = LEN / 2; i >= 1; i--) {
        sinkOrder(arr, i, LEN);
    }
    cout << "------max heap-------" << endl;
    for (int i = 0; i < 13; i++) {
        cout << arr[i] << " ";
    }
    cout << " " << endl;
    cout << "-------------" << endl;
    // heap sort
    int j = LEN;
    while (j > 2) { // note: a[0] 为占位符，否者 j>1
        cout << arr[1] << " swap " << arr[j] << endl;
        swapAB(&arr[1], &arr[j--]);
        sinkOrder(arr, 1, j);
        cout << j << "\t";
        for (int i = 0; i <= LEN; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

/*
* len 数组长度, 包括占位符arr[0]
*/
void swimOrder(int arr[], int k/*, int top*/) {
    // print // -d
    cout << "------------before---------------" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
    for (int i = k; i >= 2; i--) { // 从k到1都需要上浮重新排位
        int j = i;
        while (j >= 2) {
            if (arr[j] > arr[j / 2])
                swapAB(&arr[j], &arr[j / 2]);
            j = j / 2;
        }
    }
    // print // -d
    cout << "------------after---------------" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
* note: 从k到1都需要上浮重新排位:
*/
void sortHeapSwim(int arr[]) {
    // build max heap
    for (int i = LEN; i >= 2; i--) {
        swimOrder(arr, i);
        cout << "i = " << i << endl; // -d
    }

    // print // -d
    for (int i = 1; i <= 12; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int k = LEN;
    while (k >= 2) {
        cout << "------------line---------------" << endl; // debug
        cout << "swap" << arr[1] << " " << arr[k] << " k= " << k - 1 << endl; // -d
        swapAB(&arr[1], &arr[k--]);
        swimOrder(arr, k);
    }
}
// debug
int main_SortHeap() {
    int arr[13] = { 1, 50, 38, 65, 97, 76, 23, 27, 49, 68, 34, 12, 64 };
    /*
    * debug successful
    sortHeapSink(arr);*/

    sortHeapSwim(arr);

    // print
    /*for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/

    return -1;
}