//
// Created by erikaemma on 17-9-11.
//

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

#define LIST_POISON1 ((void*)0x00100100)
#define LIST_POISON2 ((void*)0x00200200)

//list node
typedef struct _list_head
{
    struct _list_head *prev;
    struct _list_head *next;
} list_head, *plhead;

//init method 1
#define LIST_HEAD_INIT(name) {&(name), &(name)}

//define and init
#define NEW_LIST_HEAD(name) list_head name = LIST_HEAD_INIT(name)

//init a empty list (init method 2)
static inline void INIT_LIST_HEAD(list_head *list)
{
    list->prev = list;
    list->next = list;
}

//combines @prev, @new and @next
static inline void __list_add(list_head *new, list_head *prev, list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

//adds @new after @head, before @head->next
static inline void list_add(list_head *new, list_head *head)
{
    __list_add(new, head, head->next);
}

//adds @new before @head, after @head->prev
static inline void list_add_tail(list_head *new, list_head *head)
{
    __list_add(new, head->prev, head);
}

//combines @prev and @next
static inline void __list_del(list_head *prev, list_head *next)
{
    next->prev = prev;
    prev->next = next;
}

//deletes the @entry (does not free)
static inline void list_del(list_head *entry)
{
    __list_del(entry->prev, entry->next);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}

//tests whether @list is the last entry in list
static inline int list_is_last(const list_head *list, const list_head *head)
{
    return (list->next == head);
}

//tests whether @head is empty
static inline int list_is_empty(const list_head *head)
{
    return (head->next == head);
}


//得到@member基于@struct_t（地址0）的偏移量
#define __offsetof(struct_t, member) ((size_t)&((struct_t*)0)->member)
//根据@ptr（struct_t->member)和__offsetof得到ptr结构体的首地址（指针）
#define __container_of(ptr, struct_t, member) \
({ \
const typeof(((struct_t*)0)->member) *__mptr = (ptr); \
(struct_t*)((char*)__mptr - __offsetof(struct_t, member)); \
})

//get the struct(include list_head) for this entry
#define get_list_entry(ptr, struct_t, member) __container_of(ptr, struct_t, member)

//get the first element from a list
#define get_list_first_entry(ptr, struct_t, member) get_list_entry((ptr)->next, struct_t, member)


//iterate over a list
#define list_for_each(pos, head) for(pos = (head)->next; pos != (head); pos = pos->next)

//iterate voer a list backwards
#define list_for_each_prev(pos, head) for(pos = (head)->prev; pos != (head); pos = pos->prev)

//iterate over a list safe against removal of list entry
#define list_for_each_safe(pos, n, head) for(pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)

//iterate voer list of given type
#define list_for_each_entry(pos, head, member) \
for(pos = get_list_entry((head)->next, typeof(*pos), member); \
&pos->member != (head); \
pos = get_list_entry(pos->member.next, typeof(*pos), member) \
)

#ifdef __cplusplus
}
#endif

#endif //UNTITLED1_LIST_H
