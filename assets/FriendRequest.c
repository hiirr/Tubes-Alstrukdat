#include "FriendRequest.h"

void create_friend_request(FriendRequest *friend_req, int user_id, int total_friends) {
    friend_req->user_id = user_id;
    friend_req->current_total_friends = total_friends;
}