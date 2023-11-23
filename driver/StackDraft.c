#include "../ADT/StackDraft.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
    StackDraft myStack;
    Draft draft1, draft2, tempDraft;

    create_stack_draft(&myStack);
    assert(is_stack_draft_empty(&myStack));

    char *text1 = strdup("First Draft");
    draft1 = new_draft(text1);

    char *text2 = strdup("Second Draft");
    draft2 = new_draft(text2);

    push_stack_draft(&myStack, draft1);
    assert(!is_stack_draft_empty(&myStack));
    assert(myStack.top == 0);

    push_stack_draft(&myStack, draft2);
    assert(myStack.top == 1);

    tempDraft = top_stack_draft(&myStack);
    assert(strcmp(tempDraft.text, text2) == 0);

    pop_stack_draft(&myStack, &tempDraft);
    assert(strcmp(tempDraft.text, text2) == 0);
    assert(myStack.top == 0);

    delete_draft(&draft1);
    delete_draft(&draft2);

    printf("All tests passed successfully.\n");

    return 0;
}
