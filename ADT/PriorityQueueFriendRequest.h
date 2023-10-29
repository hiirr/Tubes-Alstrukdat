#ifndef PRIORITY_QUEUE_FRIEND_REQUEST_H
#define PRIORITY_QUEUE_FRIEND_REQUEST_H

#define PRIORITY_QUEUE_FRIEND_REQUEST_CAPACITY 20

#include "../assets/FriendRequest.h"

typedef struct PriorityQueueFriendRequest {
    FriendRequest queue[PRIORITY_QUEUE_FRIEND_REQUEST_CAPACITY];
    int head;
    int tail;
} PriorityQueueFriendRequest;

void create_priority_queue_friend_request(PriorityQueueFriendRequest *p);

int length_priority_queue_friend_request(PriorityQueueFriendRequest *p);

void enqueue_friend_request(PriorityQueueFriendRequest *p, FriendRequest element);

void dequeue_friend_request(PriorityQueueFriendRequest *p, FriendRequest *element);

void print_priority_queue_friend_request(PriorityQueueFriendRequest *p);

#endif