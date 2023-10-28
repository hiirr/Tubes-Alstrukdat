#include "ADT/wordmachine.h"

int main() {
    while (true) {
        READWORD(10);
        printCurrentWord();
        print("\n");
        if (isCWordEqual("MASUK")) {
            printf("Logged In!\n");
        }
        if (isCWordEqual("KELUAR")) {
            printf("Logged Out!\n");
            break;
        }
    }
}