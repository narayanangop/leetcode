/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

typedef struct {
    char data[4];
    int capacity;
    int front;
    int rear;
    int size;
    
} Solution;

/** initialize your data structure here. */
Solution* solutionCreate() {

    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->capacity = 4;
    obj->front = 0;
    obj->rear = obj->capacity - 1;
    obj->size = 0;

    return obj;
}

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(Solution* obj, char* buf, int n) {

    int bytes_read_so_far = 0;
    int bytes_read=0;
    char local_buf[4];
    int bytes_remaining = n - bytes_read_so_far;
    int bytes_to_copy;

    while(bytes_remaining && obj->size) {
        *(buf + bytes_read_so_far) = obj->data[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;
        obj->size--;
        bytes_read_so_far += 1;
        bytes_remaining = n - bytes_read_so_far;
    }
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

    int extra_bytes = bytes_read - bytes_to_copy;
    while(extra_bytes > 0) {
        obj->rear = (obj->rear + 1) % obj->capacity;
        printf("%d, %d\n", obj->rear, bytes_to_copy);
        obj->data[obj->rear] = local_buf[bytes_to_copy];
        obj->size++;
        bytes_to_copy++;
        extra_bytes--;
    }

    return bytes_read_so_far;
    
}