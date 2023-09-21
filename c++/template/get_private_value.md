# C++11
#include <iostream>

class Test
{
public:
    explicit Test() {}
private:
    int &value() { return v; }
    int v;
};

template <typename T, T MemPtr>
struct Access;

template <typename T, typename U, typename... Args, T (U::*MemPtr)(Args...)>
struct Access<T (U::*)(Args...), MemPtr>
{
    friend T (U::*access())(Args...) {
        return MemPtr;
    }
};

template struct Access<decltype(&Test::value), &Test::value>;

int &(Test::*access())();

int main(int argc, char *argv[])
{
    Test t;
    std::cout << access() << std::endl;
    (t.*access())() = 100;
    std::cout << (t.*access())() << std::endl;
    return 0;
}

# C++17
#include <iostream>

class Test
{
public:
    explicit Test() {}
private:
    int &value() {return v;}
    int v;
};

template <auto MemPtr>
struct Access;

template<class T, class U, class... Args, T (U::*MemPtr)(Args...)>
struct Access<MemPtr>
{
    friend decltype (MemPtr) access() {
        return MemPtr;
    }
};

template struct Access<&Test::value>;
//using Fun = int &(Test::*)();
//Fun access(Test &);
int &(Test::*access())();

int main(int argc, char *argv[])
{
    Test t;
    std::cout << access() << std::endl;
    (t.*access())() = 100;
    std::cout << (t.*access())() << std::endl;
}

