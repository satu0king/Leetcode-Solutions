// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int fullReadCount = n / 4;
    int bytesRead = 0;
    for (int i = 0; i < fullReadCount; i++) {
      int bytesReadTemp = read4(buf + i * 4);
      bytesRead += bytesReadTemp;
      if (bytesReadTemp < 4)
        return bytesRead;
    }

    if (n % 4) {
      char tempBuf[4];
      int bytesReadTemp = min(read4(tempBuf), n % 4);

      for (int i = 0; i < bytesReadTemp; i++) {
        buf[fullReadCount * 4 + i] = tempBuf[i];
      }
      bytesRead += bytesReadTemp;
    }

    return bytesRead;
  }
};
