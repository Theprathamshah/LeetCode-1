class ZeroEvenOdd {
private:
    int n;
    int counter = 1; // CS
    mutex m;
    condition_variable cv;
    
    bool evenTrigger = false;  // even and not zero.. do thing.. not toggle and zero
    bool zeroTrigger = true; // zero .. do thing.. not zero..

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        
        while(counter <= n) {
            
            auto uLock = unique_lock<mutex>(m);
            cv.wait(uLock,[this]() { return (zeroTrigger); }); // alterbatively, could have cv.wait(uLock,[this]() { return (zeroTrigger and counter <= n); }); and removed the if check below, but for some reason leetcode says TLE.. only this style works..
            
            if(counter <= n) {                
                printNumber(0);                                             
            }   
            zeroTrigger = false;   
            uLock.unlock();            
            cv.notify_all();            
        }
        return;
        
        
    }

    void even(function<void(int)> printNumber) {
        
        while(counter <= n) {
        
            auto uLock = unique_lock<mutex>(m);
                
            cv.wait(uLock,[this]() { return (!zeroTrigger and evenTrigger);});
    
            if(counter <= n) {                
                printNumber(counter++);                
            }  
            
            zeroTrigger = true;     
            evenTrigger = false;
            uLock.unlock();
            cv.notify_all();
        }
        return;

    }

    void odd(function<void(int)> printNumber) {
        
        while(counter <= n) {
        
            auto uLock = unique_lock<mutex>(m);
            
            cv.wait(uLock, [this]() {return (!zeroTrigger and !evenTrigger);});

            if(counter <= n) {                
                printNumber(counter++);                
            }
            zeroTrigger = true;     
            evenTrigger = true;
            
            uLock.unlock();
            cv.notify_all();
        }
        return;
    }
};

