#pragma once
#include "share/QtAwesome/QtAwesome.h"

class QtAwesome;

namespace Utils {

    /// <summary>
    /// 获取QtAwesome的实例，该实例全局唯一
    /// </summary>
    /// <returns></returns>
    QtAwesome* awesome();


class NothingStyleHelper
{
public:
    NothingStyleHelper() {}
    ~NothingStyleHelper() {}

};


}