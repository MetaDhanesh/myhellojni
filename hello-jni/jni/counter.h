//
// Created by Dhanesh Kothari on 2019-11-22.
//

#ifndef HELLO_JNI_COUNTER_H
#define HELLO_JNI_COUNTER_H

struct counter;
typedef struct counter counter_t;

counter_t *counter_create(int start);
void counter_destroy(counter_t *c);

void counter_add(counter_t *c, int amount);
void counter_subtract(counter_t *c, int amount);

void counter_increment(counter_t *c);
void counter_decrement(counter_t *c);

int counter_getval(counter_t *c);

#endif //HELLO_JNI_COUNTER_H
