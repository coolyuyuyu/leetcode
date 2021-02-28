// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution()
        : m_bgnIndex(0)
        , m_endIndex(0)
        , m_end(false) {

    }

    /**
    * @param buf Destination buffer
    * @param n   Maximum number of characters to read
    * @return    The number of characters read
    */
    int read(char *buf, int n) {
        int numBytesRemaining = n;
        while (0 < numBytesRemaining) {
            if (m_end && m_bgnIndex >= m_endIndex) {
                break;
            }

            int numBytesRequestFromBuffer = min(numBytesRemaining, m_endIndex - m_bgnIndex);
            if (numBytesRequestFromBuffer) {
                memcpy(buf, m_buf + m_bgnIndex, numBytesRequestFromBuffer);
                m_bgnIndex += numBytesRequestFromBuffer;
                buf += numBytesRequestFromBuffer;
                numBytesRemaining -= numBytesRequestFromBuffer;

            }

            if (!m_end && m_bgnIndex == m_endIndex) {
                m_bgnIndex = 0;
                m_endIndex = read4(m_buf);
                if (m_endIndex != 4) {
                    m_end = true;
                }
            }
        }

        return n - numBytesRemaining;
    }

private:
    char m_buf[4];
    int m_bgnIndex;
    int m_endIndex;
    bool m_end;

};