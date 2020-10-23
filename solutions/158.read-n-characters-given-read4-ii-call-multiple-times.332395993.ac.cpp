// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  char buffer[4];
  int bufferIndex;
  int bufferSize;

  Solution() : bufferIndex(0), bufferSize(0) {}

  int read(char *buf, int n) {
    int bytesRead = 0;

    while (bytesRead < n) {
      if (bufferIndex == bufferSize) {
        bufferIndex = 0;
        bufferSize = read4(buffer);
        if (bufferSize == 0)
          return bytesRead;
      }
      buf[bytesRead++] = buffer[bufferIndex++];
    }

    return bytesRead;
  }
};
