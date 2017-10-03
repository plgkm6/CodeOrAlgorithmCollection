#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct _test_list {
    char name[20];
    int age;
    list_head  list;
} test_list_t, *ptlist_t;

//LIST_HEAD t_list = LIST_HEAD_INIT(t_list);
NEW_LIST_HEAD(t_list);

static void _item_init(char *name, int age) {
    ptlist_t item = (ptlist_t) malloc(sizeof(test_list_t));

    strcpy(item->name, name);
    item->age = age;

    list_add(&item->list, &t_list);
}

static void _item_destroy() {
    ptlist_t entry = NULL;
    plhead temp = NULL;
    plhead item = NULL;

    printf("destroy\n");
    list_for_each_safe(item, temp, &t_list) {
        entry = get_list_entry(item, struct _test_list, list);
        list_del(item);
        printf("next : %p\t prev : %p\n", entry->list.next, entry->list.prev);
        printf("name : %s\t age : %d\n", entry->name, entry->age);
        free(entry);
        printf("delete\n");
        entry = NULL;
    }
}

static void _item_display() {
    ptlist_t entry = NULL;

    printf("display\n");
    list_for_each_entry(entry, &t_list, list) {
        printf("name : %s\t age : %d\n", entry->name, entry->age);
    }
}

static void list_oper(void) {
    _item_init("wo", 10);
    _item_init("shi", 20);
    _item_init("zhong", 30);
    _item_init("guo", 40);
    _item_init("ren", 50);

    _item_display();

    _item_destroy();

}

void test_list() {
    list_oper();
}

int main() {
    test_list();
    return 0;
}