class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        _cap = capacity;
        _size = 0;
    }
    
    void enqueue(int element) {
        
        auto gLock = unique_lock<mutex>(_m);
     
        
        _cv.wait(gLock, [this](){return _size < _cap ? true : false; });
        
        // if we get here means we have space
        _queue.push(element);
        
        _size++;
        
        gLock.unlock();
        _cv.notify_one();
        
        
    }
    
    int dequeue() {
        
        auto gLock = unique_lock<mutex>(_m);
        
        _cv.wait(gLock, [this](){return _size != 0 ? true : false; });
        
        // if we get here means we have space
        int element = _queue.front(); _queue.pop();
        
        _size--;
        
        gLock.unlock();
        _cv.notify_one();
        
        return element;
        
        
        
        
    }
    
    int size() {
        auto gLock = unique_lock<mutex>(_m);
        int s = _size;
        gLock.unlock();
        return s;
        
    }
    int _cap;
    int _size;
    queue<int> _queue; // this is CS
    
    mutex _m;
    condition_variable _cv;
    
};