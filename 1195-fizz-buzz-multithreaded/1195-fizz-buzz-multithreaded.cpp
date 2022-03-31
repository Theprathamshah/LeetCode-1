class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    void fizz(function<void()> printFizz) {
        while (count <= n) {
            unique_lock<mutex> lock(m);
//             cv.wait(lock, [&](){ return count <= n and (count % 3 != 0 or count % 5 == 0) ? false : true;});     
//             if (count > n) break;
            
            if(count % 3 != 0 or count % 5 == 0) {
                cv.wait(lock);
                continue;
            }
            
            printFizz();
            ++count;
            lock.unlock();
            cv.notify_all();
        }
        return;
    }

    void buzz(function<void()> printBuzz) {
        while (count <= n) {
            unique_lock<mutex> lock(m);
            // cv.wait(lock, [&](){ return count <= n and (count % 5 != 0 or count % 3 == 0) ? false : true;});            
            // if (count > n) break;
            
            if(count % 3 == 0 or count % 5 != 0) {
                cv.wait(lock);
                continue;
            }
            
            printBuzz();
            ++count;
            lock.unlock();
            cv.notify_all();
        }
        return;
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while (count <= n) {
            unique_lock<mutex> lock(m);
            // cv.wait(lock, [&](){ return count <= n and (count % 5 != 0 or count % 3 != 0) ? false : true;});        
            // if (count > n) break;
            if(count % 3 != 0 or count % 5 != 0) {
                cv.wait(lock);
                continue;
            }
            printFizzBuzz();
            ++count;
            lock.unlock();
            cv.notify_all();
        }
        return;
    }

    void number(function<void(int)> printNumber) {
        while (count <= n) {
            unique_lock<mutex> lock(m);
            // cv.wait(lock, [&](){ return count <= n and (count % 5 == 0 or count % 3 == 0) ? false : true;});            
            // if (count > n) break;
            if(count % 3 == 0 or count % 5 == 0) {
                cv.wait(lock);
                continue;
            }
            printNumber(count);
            ++count;
            lock.unlock();
            cv.notify_all();
        }
        return;
    }
};