/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char* buf, int n) {

    int bytes_read_so_far = 0;
    int bytes_read;
    char local_buf[4];
    int bytes_remaining = n - bytes_read_so_far;
    int bytes_to_copy;
    while(bytes_remaining) {
        bytes_read = read4(local_buf);
        bytes_to_copy = (bytes_remaining > bytes_read) ? bytes_read : bytes_remaining;
        memcpy((buf+bytes_read_so_far), local_buf, bytes_to_copy);
        bytes_read_so_far += bytes_to_copy;
        bytes_remaining = n - bytes_read_so_far;
        if(bytes_read < 4) {
            break;
        }
    }

    return bytes_read_so_far;
    
}