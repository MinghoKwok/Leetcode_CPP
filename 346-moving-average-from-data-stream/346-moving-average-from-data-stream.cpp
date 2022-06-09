class MovingAverage {
    double sum;
    int size;
    queue<double> last_3;
public:
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        sum += val;
        last_3.push(val);
        
        if (last_3.size() > this->size) {
            sum -= last_3.front();
            last_3.pop();
        }
        
        return sum / (double)last_3.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */