#ifndef UTILS
#define UTILS
#include <windows.h>

namespace Utils {
inline void setSystemEnv()
{
#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
#endif
}

}

#endif