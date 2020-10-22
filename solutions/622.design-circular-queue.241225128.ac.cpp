class MyCircularQueue {

  vector<int> queue;
  int size;
  int l;
  int r;

public:
  /** Initialize your data structure here. Set the size of the queue to be k. */

  MyCircularQueue(int k) : size(k + 1), queue(k + 1), l(0), r(0) {}

  /** Insert an element into the circular queue. Return true if the operation is
   * successful. */
  bool enQueue(int value) {
    if (isFull())
      return false;
    queue[r] = value;
    r = (r + 1) % size;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is
   * successful. */
  bool deQueue() {
    if (isEmpty())
      return false;

    l = (l + 1) % size;

    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (isEmpty())
      return -1;
    return queue[l];
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (isEmpty())
      return -1;
    return queue[(r - 1 + size) % size];
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return l == r; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return (r + 1) % size == l; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
