#include "User.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/pcolor.h"
#include <stdlib.h>

User create_user() {
    User user;
    user.name = NULL;
    user.password = NULL;

    user.is_public = true;
    user.bio = NULL;
    user.phone = NULL;
    user.weton = NULL;

    create_matrix(&user.profile_picture, 5, 10);

    user.total_friends = 0;
    create_priority_queue_friend_request(&user.friend_requests);

    create_dynamic_list(&user.tweets, 1);

    create_stack_draft(&user.drafts);
}

void set_user_name(User *s, char *name) {
    if (s->name != NULL) {
        free(s->name);
    }
    size_t length;
    my_strlen(name, &length);
    s->name = malloc((length + 1) * sizeof(char));
    my_strcpy(s->name, name);
}

void set_user_password(User *s, char *password) {
    if (s->password != NULL) {
        free(s->password);
    }
    size_t length;
    my_strlen(password, &length);
    s->password = malloc((length + 1) * sizeof(char));
    my_strcpy(s->password, password);
}

void set_user_bio(User *s, char *bio) {
    if (s->bio != NULL) {
        free(s->bio);
    }
    size_t length;
    my_strlen(bio, &length);
    s->bio = malloc((length + 1) * sizeof(char));
    my_strcpy(s->bio, bio);
}

void set_user_phone(User *s, char *phone) {
    if (s->phone != NULL) {
        free(s->phone);
    }
    size_t length;
    my_strlen(phone, &length);
    s->phone = malloc((length + 1) * sizeof(char));
    my_strcpy(s->phone, phone);
}

void set_user_weton(User *s, char *weton) {
    if (s->weton != NULL) {
        free(s->weton);
    }
    size_t length;
    my_strlen(weton, &length);
    s->weton = malloc((length + 1) * sizeof(char));
    my_strcpy(s->weton, weton);
}

void print_profile_picture(User *s) {
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            int color = s->profile_picture.matrix[row][2 * col];
            int character = s->profile_picture.matrix[row][2 * col + 1];
            if ((char)color == 'R') print_red(character);
            else if ((char)color == 'G') print_green(character);
            else print_blue(character);
        }
        printf("\n");
    }
}