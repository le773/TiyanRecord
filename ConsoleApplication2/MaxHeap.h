#pragma once

#include <iostream>

using namespace std;

class MaxHeap
{
public:
    MaxHeap();
    ~MaxHeap();
    void swapNode(int* p, int* q);
    void buildHead(int* arr, int len);
    void sinkHead(int* arr, int k);
    void swimTail(int* arr, int k);
    void insert(int* arr, int node);
    void sortHead(int* arr);
    int getCap();
    void setCap(int n);
public:
    int N = 20;
    int cap = 0;
};

