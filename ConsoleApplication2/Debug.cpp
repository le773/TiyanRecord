#include "Debug.h"



Debug::Debug()
{
}


Debug::~Debug()
{
}

void Debug::cleanBrowser(EffectCpp23& eff) {
    eff.clearCache();
    eff.clearHistory();
    eff.removeCookies();
}



int main()
{
    Debug* debug = new Debug;
    EffectCpp23 eff;
    debug->cleanBrowser(eff);
    delete debug;
    return -1;
}
