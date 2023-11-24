CC = gcc
CFLAGS = -Wall
TARGET = main

MAIN_SOURCES = main.c ADT/*.c assets/*.c database/*.c features/*.c
PRIO_QUEUE_SOURCES = driver/PriorityQueue.c ADT/PriorityQueueFriendRequest.c assets/FriendRequest.c
MATRIX_SOURCES = driver/Matrix.c ADT/Matrix.c
CHAR_SOURCES = driver/Charmachine.c ADT/Charmachine.c
GRAPH_SOURCES = driver/GraphMatrix.c ADT/GraphMatrix.c
STACK_DRAFT_SOURCES = driver/StackDraft.c ADT/StackDraft.c assets/Draft.c ADT/Datetime.c ADT/Wordmachine.c ADT/Charmachine.c ADT/DynamicList.c ADT/math.c
DYNAMIC_LIST_SOURCES = driver/DynamicList.c ADT/DynamicList.c
REPLY_TREE_SOURCES = driver/ReplyTree.c ADT/*.c assets/*.c database/*.c
WORD_SOURCES = driver/Wordmachine.c ADT/Datetime.c ADT/Charmachine.c ADT/Wordmachine.c ADT/DynamicList.c ADT/math.c
LINKED_SOURCES = driver/LinkedThread.c ADT/LinkedThread.c ADT/Wordmachine.c ADT/DynamicList.c ADT/math.c ADT/Charmachine.c
DATETIME_SOURCES = driver/Datetime.c ADT/Datetime.c ADT/Wordmachine.c ADT/Charmachine.c ADT/DynamicList.c ADT/math.c
STATICLIST_SOURCES = driver/StaticList.c ADT/StaticList.c

# Help
help:
	@echo "Command to run main:"
	@echo "make run"
	@echo "_______________________"
	@echo "Commands to run driver:"
	@echo "make test_char"
	@echo "make test_datetime"
	@echo "make test_dynamic_list"
	@echo "make test_graph"
	@echo "make test_linked"
	@echo "make test_matrix"
	@echo "make test_prio_queue"
	@echo "make test_reply_tree"
	@echo "make test_stack_draft"
	@echo "make test_word"
	@echo "____________________________________"
	@echo "Command to clean all compiled files:"
	@echo "make clean"

# Main target
run: $(MAIN_SOURCES)
	@$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_SOURCES)
	@./$(TARGET)

# Test targets
test_prio_queue:
	@$(CC) $(CFLAGS) -o test_prio_queue $(PRIO_QUEUE_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_prio_queue

test_matrix:
	@$(CC) $(CFLAGS) -o test_matrix $(MATRIX_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_matrix

test_char:
	@$(CC) $(CFLAGS) -o test_char $(CHAR_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_char

test_graph:
	@$(CC) $(CFLAGS) -o test_graph $(GRAPH_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_graph

test_stack_draft:
	@$(CC) $(CFLAGS) -o test_stack_draft $(STACK_DRAFT_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_stack_draft

test_dynamic_list:
	@$(CC) $(CFLAGS) -o test_dynamic_list $(DYNAMIC_LIST_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_dynamic_list

test_reply_tree:
	@$(CC) $(CFLAGS) -o test_reply_tree $(REPLY_TREE_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_reply_tree

test_word:
	@$(CC) $(CFLAGS) -o test_word $(WORD_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_word

test_linked:
	@$(CC) $(CFLAGS) -o test_linked $(LINKED_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_linked

test_datetime:
	@$(CC) $(CFLAGS) -o test_datetime $(DATETIME_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_datetime

test_static_list:
	@$(CC) $(CFLAGS) -o test_static_list $(STATICLIST_SOURCES)
	@echo "Compiled.."
	@echo "Running test..\n"
	@./test_static_list

# Clean target
clean:
	@rm -f $(TARGET) test_prio_queue test_matrix test_char test_graph test_stack_draft test_dynamic_list test_reply_tree test_word test_linked test_datetime test_static_list
	@rm -f $(TARGET).exe test_prio_queue.exe test_matrix.exe test_char.exe test_graph.exe test_stack_draft.exe test_dynamic_list.exe test_reply_tree.exe test_word.exe test_linked.exe test_datetime.exe test_static_list.exe
	@echo "Cleaned all compiled files"

# PHONY targets
.PHONY: clean test_prio_queue test_matrix test_char test_graph test_stack_draft test_dynamic_list test_reply_tree test_word test_linked test_datetime test_static_list
