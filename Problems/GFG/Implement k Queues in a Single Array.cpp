class kQueues
{
public:
    vector<int> arr; // Stores all queue elements
    int n, k;        // n = size of array, k = number of queues

    vector<int> front; // Stores front index of each queue
    vector<int> rear;  // Stores rear index of each queue

    vector<int> next; // Used for both queue links and free list
    int freeIndex;    // Points to first free slot in arr

    kQueues(int n, int k)
    {
        this->n = n;
        this->k = k;

        // Initialize storage array
        arr.resize(n);

        // Initially all queues are empty
        front.resize(k, -1);
        rear.resize(k, -1);

        // Initialize next array
        next.resize(n);

        // Create free list:
        // 0 -> 1 -> 2 -> ... -> n-1
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        // First free position
        freeIndex = 0;
    }

    // Check if queue qn is empty
    bool isEmpty(int qn)
    {
        return (front[qn] == -1);
    }

    // Check if array has no free space left
    bool isFull()
    {
        return (freeIndex == -1);
    }

    // Insert x into queue qn
    bool enqueue(int x, int qn)
    {

        // No free space available
        if (isFull())
            return false;

        // Get first free index
        int i = freeIndex;

        // Move freeIndex to next available free slot
        freeIndex = next[i];

        // If queue is empty, new element becomes front
        if (isEmpty(qn))
            front[qn] = i;
        else
        {
            // Link old rear to new node
            next[rear[qn]] = i;
        }

        // Update rear pointer
        rear[qn] = i;

        // Store value
        arr[i] = x;

        // Mark end of queue
        next[i] = -1;

        return true;
    }

    // Remove and return front element from queue qn
    int dequeue(int qn)
    {

        // Queue is empty
        if (isEmpty(qn))
            return -1;

        // Get front index
        int i = front[qn];

        // Move front to next element
        front[qn] = next[i];

        // If queue becomes empty, update rear also
        if (front[qn] == -1)
            rear[qn] = -1;

        // Add removed index back to free list
        next[i] = freeIndex;
        freeIndex = i;

        // Return removed value
        return arr[i];
    }
};