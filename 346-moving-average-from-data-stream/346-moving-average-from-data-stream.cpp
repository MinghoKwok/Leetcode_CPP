class MovingAverage {
    int size;
    vector<double> last_3;
public:
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (last_3.size() == size) {
            last_3.erase(last_3.begin());
        } 
        
        last_3.push_back(val);
        
        double sum = 0;
        for (int i = 0; i < last_3.size(); i++) {
            sum += last_3[i];
        }
        
        return sum / (double)last_3.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */