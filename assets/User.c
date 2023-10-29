#include "User.h"
#include "../ADT/Wordmachine.h"
#include <stdlib.h>

void set_user_name(User *s, char *name) {
    free(s->name);
    size_t length;
    my_strlen(name, &length);
    s->name = malloc((length + 1) * sizeof(char));
    my_strcpy(s->name, name);
}

void set_user_password(User *s, char *password) {
    free(s->password);
    size_t length;
    my_strlen(password, &length);
    s->password = malloc((length + 1) * sizeof(char));
    my_strcpy(s->password, password);
}

void set_user_bio(User *s, char *bio) {
    free(s->bio);
    size_t length;
    my_strlen(bio, &length);
    s->bio = malloc((length + 1) * sizeof(char));
    my_strcpy(s->bio, bio);
}

void set_user_phone(User *s, char *phone) {
    free(s->phone);
    size_t length;
    my_strlen(phone, &length);
    s->phone = malloc((length + 1) * sizeof(char));
    my_strcpy(s->phone, phone);
}

void set_user_weton(User *s, char *weton) {
    free(s->weton);
    size_t length;
    my_strlen(weton, &length);
    s->weton = malloc((length + 1) * sizeof(char));
    my_strcpy(s->weton, weton);
}