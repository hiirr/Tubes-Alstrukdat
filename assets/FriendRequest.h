#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

typedef struct FriendRequest {
    int user_id;
    int current_total_friends; // Sebagai prioritasnya di ADT Priority Queue
} FriendRequest;

void create_friend_request(FriendRequest *friend_request, int user_id, int total_friends);

#endif