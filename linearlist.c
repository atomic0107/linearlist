#include<stdio.h>
#include<stdlib.h>

typedef struct linearlist{
    char *key;
    int value;
    unsigned long *next;
}llist_t;

llist_t set_linear(void){
    llist_t list;
    llist_t child;

    list.key = "tomohiro";
    list.value = 1;

    return list;
}

void append_list(llist_t *list,int value){
    llist_t next;
    next.value = value;

    if((unsigned long)list->next == 0x0U ){
        list->next = (unsigned long *)&next;
        printf("%d\n",list->value);
    }
    else
    {
        printf("%d\n",list->value);
        append_list((llist_t*)list->next,value);
    }
}

void print_list(llist_t *list){
    printf("----------------------\n");
    printf("key = %s\t\t\n",list->key);
    printf("value = %d\t\t\n",list->value);
    printf("next address = %p\t\n",list->next);
}

int main(void){
    llist_t list;

    printf("hello world\n");
    list = set_linear();
    print_list(&list);
    append_list(&list,5);
    append_list(&list,6);
    
    return 0;
}

