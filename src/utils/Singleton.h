#pragma once

#include "noncopyable.h"

#include <assert.h> // assert
#include <stdlib.h> // atexit
#include <mutex> // call_once

namespace detail
{
    template<typename T>
    struct has_no_destroy
    {
        template <typename C> static char test(decltype(&C::no_destroy));
        template <typename C> static int32_t test(...);
        const static bool value = sizeof(test<T>(0)) == 1;
    };
}  // namespace detail

namespace Utils
{
template<typename T>
class Singleton : noncopyable
{
public:
    Singleton() = delete;
    ~Singleton() = delete;

    static T& instance()
    {
        std::call_once(_once, &Singleton::init);
        assert(_value != NULL);
        return *_value;
    }
    
private:
    static void init()
    {
        _value = new T();
        if (!detail::has_no_destroy<T>::value)
        {
            ::atexit(destroy);
        }
    }

    static void destroy()
    {
        // 解释：下面两行是为了防止将不完整类型的指针delete的情况（这种情况编译器是不会报错的）
        typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
        T_must_be_complete_type dummy; (void)dummy;

        delete _value;
        _value = NULL;
    }

private:
    static std::once_flag _once;
    static T* _value;
};

template<typename T>
std::once_flag Singleton<T>::_once;

template<typename T>
T* Singleton<T>::_value = NULL;


} // namespace Utils