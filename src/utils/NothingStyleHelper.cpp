#include "NothingStyleHelper.h"
#include "utils/Singleton.h"

namespace Utils
{
    QtAwesome* awesome()
    {
        return &Singleton<QtAwesome>::instance();
    }

}