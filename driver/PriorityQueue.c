#include "../ADT/PriorityQueueFriendRequest.h"
#include <stdio.h>
#include <assert.h>

int main() {
    PriorityQueueFriendRequest myQueue;
    FriendRequest req1, req2, req3;
    
    create_friend_request(&req1, 1, 5);
    create_friend_request(&req2, 2, 10);
    create_friend_request(&req3, 3, 7);

    create_priority_queue_friend_request(&myQueue);
    assert(is_empty_priority_queue_friend_request(myQueue));

    enqueue_friend_request(&myQueue, req1);
    enqueue_friend_request(&myQueue, req2);
    enqueue_friend_request(&myQueue, req3);
    assert(length_priority_queue_friend_request(myQueue) == 3);

    assert(is_in_priority_queue_friend_request(myQueue, 1));
    assert(is_in_priority_queue_friend_request(myQueue, 2));
    assert(is_in_priority_queue_friend_request(myQueue, 3));

    FriendRequest dequeued;
    dequeue_friend_request(&myQueue, &dequeued);
    assert(dequeued.user_id == 2);

    remove_request_from_queue(&myQueue, 1);
    assert(!is_in_priority_queue_friend_request(myQueue, 1));

    printf("All tests passed successfully.\n");

    return 0;
}
