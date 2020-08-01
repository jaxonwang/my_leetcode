#include <atomic>
#include <iostream>
#include <thread>
#include <functional>

using namespace std;

class Foo {
public:

    atomic_flag afinish;
    atomic_flag bfinish;
    Foo():afinish(), bfinish() {
        afinish.test_and_set();
        bfinish.test_and_set();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        // cout << "first";
        afinish.clear();

    }

    void second(function<void()> printSecond) {
        while(afinish.test_and_set());
        
        // printSecond() outputs "second". Do not change or remove this line.
        // printSecond();
        // cout << "second";
        bfinish.clear();
    }

    void third(function<void()> printThird) {
        while(bfinish.test_and_set());
        
        // printThird() outputs "third". Do not change or remove this line.
        // cout << "thrid" << endl;;
        printThird();
    }
};

int main(int argc, const char *argv[])
{

    auto f1 = [](Foo &f){
        f.first(function<void()>{[](){}});
    };
    auto f2 = [](Foo &f){
        f.second(function<void()>{[](){}});
    };
    auto f3 = [](Foo &f){
        f.third(function<void()>{[](){}});
    };
    Foo foo;
    thread t3(f3, ref(foo));
    thread t2(f2, ref(foo));
    thread t1(f1, ref(foo));

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
