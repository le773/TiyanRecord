#pragma once

#include<iostream>
#include<cstdlib>

using namespace std;

/*
* non member non-friend replace member
* 1. add encapsulation && packaging flexibility
*/
class EffectCpp23
{
public:
    EffectCpp23();
    ~EffectCpp23();
    void clearCache();
    void clearHistory();
    void removeCookies();
};

