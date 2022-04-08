class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> _pq; // This is a min_heap of k elements. So when we pop, we will get the kth largest element..
    int _size;
public:
    KthLargest(int k, vector<int>& nums) {
        
        _size = k;
                        
        for(auto& n : nums) {            
            _pq.push(n);            
            if(_pq.size() > _size) {
                _pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        _pq.push(val);            
        if(_pq.size() > _size) {
            _pq.pop();
        }
        return _pq.top();
        
    }
};


/*

We can't use a set here coz we need to return kth largest element in the sorted order, not the kth distinct element.
i.e. if the input was 5 5 5 .. set will compress it into just 1 5.. but we need to keep all 3 5s



*/





/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */