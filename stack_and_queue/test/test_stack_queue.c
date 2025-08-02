#include "../src/stack_queue.h"
#include <assert.h>
#include <stdio.h>

void test_stack_operations() {
    Stack s;
    stack_init(&s);
    bool success;
    
    assert(stack_is_empty(&s));
    assert(s.size == 0);
    
    stack_push(&s, 10);
    assert(!stack_is_empty(&s));
    assert(s.size == 1);
    assert(stack_peek(&s, &success) == 10);
    assert(success);
    
    stack_push(&s, 20);
    assert(s.size == 2);
    assert(stack_peek(&s, &success) == 20);
    assert(success);
    
    assert(stack_pop(&s, &success) == 20);
    assert(success);
    assert(s.size == 1);
    
    assert(stack_pop(&s, &success) == 10);
    assert(success);
    assert(stack_is_empty(&s));
    assert(s.size == 0);
    
    assert(stack_pop(&s, &success) == 0);
    assert(!success);
    
    stack_clear(&s);
    printf("Stack tests passed!\n");
}

void test_queue_operations() {
    Queue q;
    queue_init(&q);
    bool success;
    
    assert(queue_is_empty(&q));
    assert(q.size == 0);
    
    queue_enqueue(&q, 10);
    assert(!queue_is_empty(&q));
    assert(q.size == 1);
    assert(queue_peek(&q, &success) == 10);
    assert(success);
    
    queue_enqueue(&q, 20);
    assert(q.size == 2);
    assert(queue_peek(&q, &success) == 10);
    assert(success);
    
    assert(queue_dequeue(&q, &success) == 10);
    assert(success);
    assert(q.size == 1);
    
    assert(queue_dequeue(&q, &success) == 20);
    assert(success);
    assert(queue_is_empty(&q));
    assert(q.size == 0);
    
    assert(queue_dequeue(&q, &success) == 0);
    assert(!success);
    
    queue_clear(&q);
    printf("Queue tests passed!\n");
}

int main() {
    test_stack_operations();
    test_queue_operations();
    return 0;
}
