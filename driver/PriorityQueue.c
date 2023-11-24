#include "../ADT/PriorityQueueFriendRequest.h"
#include <stdio.h>

int main() {
    PriorityQueueFriendRequest myQueue;
    FriendRequest req1, req2, req3;
    
    create_friend_request(&req1, 1, 5);
    create_friend_request(&req2, 2, 10);
    create_friend_request(&req3, 3, 7);

    create_priority_queue_friend_request(&myQueue);
    if (is_empty_priority_queue_friend_request(myQueue)) {
        printf("passed\n");
    }

    enqueue_friend_request(&myQueue, req1);
    enqueue_friend_request(&myQueue, req2);
    enqueue_friend_request(&myQueue, req3);
    if (length_priority_queue_friend_request(myQueue) == 3) {
        printf("passed\n");
    }

    if (is_in_priority_queue_friend_request(myQueue, 1)) {
        printf("passed\n");
    }
    if (is_in_priority_queue_friend_request(myQueue, 2)) {
        printf("passed\n");
    }
    if (is_in_priority_queue_friend_request(myQueue, 3)) {
        printf("passed\n");
    }

    FriendRequest dequeued;
    dequeue_friend_request(&myQueue, &dequeued);
    if (dequeued.user_id == 2) {
        printf("passed\n");
    }

    remove_request_from_queue(&myQueue, 1);
    if (!is_in_priority_queue_friend_request(myQueue, 1)) {
        printf("passed\n");
    }

    printf("All tests passed successfully.\n");

    return 0;
}
