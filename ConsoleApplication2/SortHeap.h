#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class SortHeap
{
public:
    SortHeap();
    ~SortHeap();
};

#define LEN 12

int swap(int* a, int* b);
void sinkOrder(int* arr, int k, int top);
void sortHeapSink(int* arr);
void swimOrder(int arr[], int k/*, int top*/);
void sortHeapSwim(int arr[]);

