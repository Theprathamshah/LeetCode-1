class Foo {
public:
    Foo():isfirstDone(false),isSecondDone(false) {  }

    void first(function<void()> printFirst) {
        
        auto gLock = unique_lock<mutex>(_m);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        isfirstDone = true;
        gLock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        auto gLock = unique_lock<mutex>(_m);
        cv.wait(gLock, [this](){return isfirstDone;});
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        isSecondDone = true;
        gLock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        auto gLock = unique_lock<mutex>(_m);
        cv.wait(gLock, [this](){return isSecondDone;});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
        gLock.unlock();
        cv.notify_all();
    }
private:
    mutex _m;
    condition_variable cv;    
    bool isfirstDone;
    bool isSecondDone;
};