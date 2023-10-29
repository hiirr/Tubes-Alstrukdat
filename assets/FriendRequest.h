#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

typedef struct FriendRequest {
    int user_id;
    int current_total_friends; // Sebagai prioritasnya di ADT Priority Queue
} FriendRequest;

#endif