class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity):_cap(capacity) {        
    }
    
    void enqueue(int element) {
        
        auto gLock = unique_lock<mutex>(_m);
             
        _cv.wait(gLock, [this](){return _queue.size() < _cap ? true : false; });
        
        // if we get here means we have space
        _queue.push(element);
               
        gLock.unlock();
        _cv.notify_one();
        
        
    }
    
    int dequeue() {
        
        auto gLock = unique_lock<mutex>(_m);
        
        _cv.wait(gLock, [this](){return _queue.size() != 0 ? true : false; });
        
        // if we get here means we have space
        int element = _queue.front(); _queue.pop();
        
        gLock.unlock();
        _cv.notify_one();
        
        return element;
        
    }
    
    int size() {
        auto gLock = lock_guard<mutex>(_m);        
        return _queue.size();
        
    }
    int _cap;    
    queue<int> _queue; // this is CS
    
    mutex _m;
    condition_variable _cv;    
};