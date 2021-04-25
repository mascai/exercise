/*


*/


// Solution 1
// addNum - O(logN)
// findMedian O(1)

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto insertPos = std::upper_bound(begin(data_), end(data_), num);
        data_.insert(insertPos, num);
    }
    
    double findMedian() {
        int size = data_.size();
        if (size % 2) {
            return data_[size / 2];
        } else {
            return (data_[size / 2] + data_[(size / 2) - 1]) / 2;
        }
    }
private:
    vector<double> data_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// Solution 2
