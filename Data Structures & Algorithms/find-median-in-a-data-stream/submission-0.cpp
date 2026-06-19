class MedianFinder {
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (firstHalf.empty() || firstHalf.top() >= num || secondHalf.empty()) {
            firstHalf.push(num);
        } else {
            secondHalf.push(num);
        }

        // balancing
        if (firstHalf.size() > 1 + secondHalf.size()) {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        } else if (secondHalf.size() > 1 + firstHalf.size()) {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }

    double findMedian() {
        int fhSize = firstHalf.size();
        int shSize = secondHalf.size();

        if ((fhSize + shSize) % 2 == 0) {
            int fhTop = firstHalf.top();
            int shTop = secondHalf.top();
            return (fhTop + shTop) / 2.0;
        }
        if (fhSize > shSize) {
            return firstHalf.top();
        }
        return secondHalf.top();
    }
};