class MedianFinder {
public:
  /** initialize your data structure here. */

  multiset<int> maxHeap;
  multiset<int> minHeap;
  MedianFinder() {}

  void addNum(int num) {
    if (maxHeap.empty())
      minHeap.insert(num);
    else if (minHeap.empty())
      maxHeap.insert(num);
    else if (num <= *maxHeap.rbegin())
      maxHeap.insert(num);
    else
      minHeap.insert(num);
    balance();
  }

  void balance() {
    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.insert(*maxHeap.rbegin());
      maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
    } else if (minHeap.size() > maxHeap.size() + 1) {
      maxHeap.insert(*minHeap.begin());
      minHeap.erase(minHeap.begin());
    }
  }

  double findMedian() {
    if (maxHeap.size() > minHeap.size())
      return *maxHeap.rbegin();
    if (maxHeap.size() < minHeap.size())
      return *minHeap.begin();

    return (*maxHeap.rbegin() + *minHeap.begin()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
