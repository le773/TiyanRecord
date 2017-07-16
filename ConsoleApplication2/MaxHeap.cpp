#include "MaxHeap.h"



MaxHeap::MaxHeap()
{
}


MaxHeap::~MaxHeap()
{
}

//#define N 12

void MaxHeap::buildHead(int* arr, int len) {
    
    for (int i = len - 1; i >= 0; i--) {
        int k = i;
        while (k >=1)
        {
            k = k / 2;
            if (arr[i] > arr[k]) {
                swapNode(&arr[i], &arr[k]);
            }
        }
    }
}

// 从上到下重建堆
void MaxHeap::sinkHead(int* arr, int k) {
    while (2 * k <N) {
        int j = 2 * k;
        if (arr[j] < arr[j + 1]) {
            j++;
        }

        if (arr[k] > arr[j]) {
            break;
        }

        swapNode(&arr[k], &arr[j]);
        k = j;
   }
}
// 从下到上重建堆
void MaxHeap::swimTail(int* arr, int k) {
    while (k > 1 && arr[k] > arr[k / 2]) {
        swapNode(&arr[k], &arr[k/2]);
        k = k / 2;
    }
}

// 添加元素
void MaxHeap::insert(int* arr, int node) {
    int cap = getCap();
    arr[cap] = node;
    swimTail(arr, cap);
    setCap(++cap);

}

void MaxHeap::swapNode(int* p, int* q) {
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

int MaxHeap::getCap() {
    return cap;
}


void MaxHeap::setCap(int n) {
    cap = n;
}

void MaxHeap::sortHead(int* arr) {
    int N = getCap() - 1;
    for (int k = N / 2; k >= 1; k--) {
        sinkHead(arr, k);
    }
}
int main_MaxHeap() {
    int arr[20] = { 50, 38, 65, 97, 76, 13, 27, 49, 78, 34, 12, 64};

    MaxHeap *heap = new MaxHeap;
    for(int i=0; i<12; i++) {
        heap->buildHead(arr, 12 -i);
        heap->swapNode(&arr[0], &arr[11 - i]);
    }
    //heap->sortHead(arr);

    for (int i = 0; i < 12; i++) {
        cout << arr[i] << endl;
    }

    delete heap;
    delete[] arr;

    heap == NULL;
    return -1;
}