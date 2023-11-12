#ifndef FRIEND_H
#define FRIEND_H

#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"

void print_friend_list();

void remove_friend();

void send_friend_request();

void cancel_friend_request();

void print_friend_requests();

void accept_friend_request();

#endif