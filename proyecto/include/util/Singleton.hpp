#ifndef SINGLETON_HPP
#define SINGLETON_HPP

namespace util
{
    template<class T>
    class Singleton
    {
    public:
        static T& getInstance()
        {
            static T instance;
            return instance;
        }
    protected:
        Singleton() = default;
        virtual ~Singleton() = default;
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    };
}

#endif // !SINGLETON_HPP
