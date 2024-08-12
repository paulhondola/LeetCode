#include <queue>
using namespace std;
class RecentCounter {
private:
  queue<int> q;

public:
  RecentCounter() {
    // Initialize an empty queue
  }

  int ping(int t) {
    // Add the current time 't' to the queue
    q.push(t);

    // Remove elements that are outside the 3000ms window
    while (q.front() < t - 3000) {
      q.pop();
    }

    // The size of the queue represents the number of recent calls
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
