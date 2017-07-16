#pragma once

#include <stdlib.h>
#define _CRT_SECURE_NO_DEPRECATE

//abstract class
class CSocketProtocol
{
public:
    virtual int cltSocketSend(void *handle, unsigned char *buf, int buflen) = 0;
    virtual int cltSocketRece(void *handle, unsigned char *buf, int buflen) = 0;
    virtual int cltSocketDestory(void *handle) = 0;
    virtual int cltSocketInit(/*void **handle*/) = 0;
    CSocketProtocol();
    ~CSocketProtocol();
};

