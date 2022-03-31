class FooBar {
private:
    int n;
    
    mutex _m;
    condition_variable _cv;
    bool _isBar;
    
    

public:
    FooBar(int n) {
        this->n = n;
        _isBar = false;
    }

    void foo(function<void()> printFoo) {
        
        auto gLock = unique_lock(_m);
        
        for (int i = 0; i < n; i++) {
            
            _cv.wait(gLock, [this](){return !_isBar; });                     
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            _isBar = true;
            _cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        auto gLock = unique_lock(_m);
        
        for (int i = 0; i < n; i++) {
            
            _cv.wait(gLock, [this](){return _isBar; });
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            _isBar = false;
            _cv.notify_one();
        }
    }
};
