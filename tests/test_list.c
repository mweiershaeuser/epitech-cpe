#include <criterion/criterion.h>
#include "../bootstrap.h"
#include "../organized_bs.h"

Test(organized_bs, push_to_list_01)
{
    linked_list_t *list = NULL;
    int a = 3;
    int b = 4;

    push_to_list(&list, &a);
    push_to_list(&list, &b);
    cr_assert_eq(*((int *) list->data), 4);
    cr_assert_eq(*((int *) list->next->data), 3);
    cr_assert_eq(list->next->next, NULL);
}
