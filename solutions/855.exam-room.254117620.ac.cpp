
// Structure to maintain list of spaces available
struct space {
  int s;
  int left;
  int right;

  space(int i, int j) : left(i), right(j) {
    s = (j - i) / 2; // Maximum space between i and j
  }

  bool operator<(const space &rhs) const {

    // smaller space
    if (s != rhs.s)
      return s < rhs.s;

    // or greater left index when space is a tie
    return left > rhs.left;
  }
};

class ExamRoom {

  // Priority Queue. We use set so that we can delete elements in the queue
  set<space> pq;

  // Map of students, key is index of student's seat.
  // The pair maintains nearest left student and nearest right student.
  // If no student exists on the left, then left = -1
  // if no student exists on the right, then right = N
  map<int, pair<int, int>> students;

  // Total number of seats available
  int N;

public:
  ExamRoom(int N) : N(N) {}

  int seat() {

    // If empty insert first student to the left
    if (students.size() == 0)
      return insertLeft();

    // Compute score of inserting to the left most seat (0)
    int leftScore = students.begin()->first;

    // Compute score of inserting to the left most seat (N-1)
    int rightScore = N - students.rbegin()->first - 1;

    // Computer score of inserting in the middle - between 1 and N - 2
    // Note that there has to be some space in the priority queue, otherwise we
    // set score to -1
    int priorityQueueScore = pq.empty() ? -1 : pq.rbegin()->s;

    // Right score is highest so insert at right
    if (rightScore > leftScore && rightScore > priorityQueueScore)
      return insertRight();

    // Left score is higher or equal to other scores
    if (leftScore >= priorityQueueScore)
      return insertLeft();

    // Priority Queue score is highest

    auto space = *pq.rbegin();    // Highest Space
    del(space.left, space.right); // Delete Space

    int i = space.left + space.s; // Compute new seat
    insert(space.left, i);        // Insert new left space
    insert(i, space.right);       // Insert new right spaces

    return i;
  }

  int insertLeft() {

    // Check if right seat exists
    int right = students.empty() ? N : students.begin()->first;

    students[0].first = -1;
    students[0].second = right;

    // If exists, insert
    if (right != N)
      insert(0, right);

    return 0;
  }
  int insertRight() {

    // Check if left seat exists
    int left = students.empty() ? -1 : students.rbegin()->first;

    students[N - 1].first = left;
    students[N - 1].second = N;

    // If exists, insert
    if (left != -1)
      insert(left, N - 1);

    return N - 1;
  }

  void insert(int i, int j) {
    // Helper function to insert
    students[i].second = j;
    students[j].first = i;
    pq.emplace(i, j);
  }

  void del(int i, int j) {

    // Helper function to delete
    pq.erase(space(i, j));

    // We have to check i!=-1
    if (i != -1)
      students[i].second = N;

    // We have to check j!=N
    if (j != N)
      students[j].first = -1;
  }

  void leave(int p) {

    int prev = students[p].first;
    int next = students[p].second;

    // Delete space to the left and to the right
    del(prev, p);
    del(p, next);

    // Remove student from student map
    students.erase(p);

    // Insert new space if possible.
    if (prev != -1 && next != N)
      insert(prev, next);
  }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
