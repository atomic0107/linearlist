#include<stdio.h>
#include<stdlib.h>


typedef struct linearlist llist_t;
typedef struct number num_t;

typedef struct nummber{
    int num;
    num_t *next;
};

typedef struct linearlist{
    char prime;
    int value;
    llist_t *next;
};

void set_linear(llist_t *list){
    list->prime = 2;
    list->value = 1;
    list->next = NULL;
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
    set_linear(&list);
    print_list(&list);
    append_list(&list,5);
    append_list(&list,6);
    
    return 0;
}

