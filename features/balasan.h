#ifndef BALASAN_H
#define BALASAN_H

#include "../ADT/ReplyTree.h"
#include "../database/database.h"


void conditionally_print(ReplyTree *t, int node, int space);

void balasan(int tweet_id);

#endif