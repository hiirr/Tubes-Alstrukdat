#include "../ADT/StackDraft.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    StackDraft myStack;
    Draft draft1, draft2, tempDraft;

    create_stack_draft(&myStack);
    if (is_stack_draft_empty(&myStack)) {
        printf("passed\n");
    }

    char *text1 = my_strdup("First Draft");
    draft1 = new_draft(text1);

    char *text2 = my_strdup("Second Draft");
    draft2 = new_draft(text2);

    push_stack_draft(&myStack, draft1);
    if (!is_stack_draft_empty(&myStack)) {
        printf("passed\n");
    }
    if (myStack.top == 0) {
        printf("passed\n");
    }

    push_stack_draft(&myStack, draft2);
    if (myStack.top == 1) {
        printf("passed\n");
    }

    tempDraft = top_stack_draft(&myStack);
    if (my_strcmp(tempDraft.text, text2) == 0) {
        printf("passed\n");
    }

    pop_stack_draft(&myStack, &tempDraft);
    if (my_strcmp(tempDraft.text, text2) == 0) {
        printf("passed\n");
    }
    if (myStack.top == 0) {
        printf("passed\n");
    }

    delete_draft(&draft1);
    delete_draft(&draft2);

    // free(text1);
    // free(text2);

    printf("All tests passed successfully.\n");

    return 0;
}
