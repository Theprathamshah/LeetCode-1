typedef int semaphore;
class Foo {
public:
    Foo():counter(0) {  }

    void first(function<void()> printFirst) {
        
        auto gLock = unique_lock<mutex>(_m);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        counter++;
        gLock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        auto gLock = unique_lock<mutex>(_m);
        cv.wait(gLock, [this](){return (counter == 1);});
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        counter++;
        gLock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        auto gLock = unique_lock<mutex>(_m);
        cv.wait(gLock, [this](){return (counter == 2);});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
        gLock.unlock();
        cv.notify_all();
    }
private:
    mutex _m;
    condition_variable cv;    
    semaphore counter;
    
};