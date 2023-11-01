#ifndef PRIORITY_QUEUE_FRIEND_REQUEST_H
#define PRIORITY_QUEUE_FRIEND_REQUEST_H

#define PRIORITY_QUEUE_FRIEND_REQUEST_CAPACITY 20

#include "../assets/FriendRequest.h"
#include "../ADT/boolean.h"

typedef struct PriorityQueueFriendRequest {
    FriendRequest queue[PRIORITY_QUEUE_FRIEND_REQUEST_CAPACITY];
    int head;
    int tail;
} PriorityQueueFriendRequest;

void create_priority_queue_friend_request(PriorityQueueFriendRequest *p);

boolean is_empty_priority_queue_friend_request(PriorityQueueFriendRequest p);

boolean is_in_priority_queue_friend_request(PriorityQueueFriendRequest p, int user_id);

int length_priority_queue_friend_request(PriorityQueueFriendRequest p);

void enqueue_friend_request(PriorityQueueFriendRequest *p, FriendRequest element);

void dequeue_friend_request(PriorityQueueFriendRequest *p, FriendRequest *element);

void print_priority_queue_friend_request(PriorityQueueFriendRequest *p);

void update_priority_queue_friend_request(PriorityQueueFriendRequest *p, int user_id, int new_popularity);

void remove_request_from_queue(PriorityQueueFriendRequest *p, int user_id);

#endif