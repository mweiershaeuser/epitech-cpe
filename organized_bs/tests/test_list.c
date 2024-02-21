#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"
#include "../bootstrap.h"
#include "../organized_bs.h"

Test(organized_bs, push_to_list)
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

Test(organized_bs, display_list_01, .init = cr_redirect_stdout)
{
    linked_list_t *list = NULL;
    char *a = "World!\n";
    char *b = "Hello ";

    push_to_list(&list, a);
    push_to_list(&list, b);
    display_list(list, (void (*)()) &my_putstr);
    cr_assert_stdout_eq_str("Hello World!\n");
}

Test(organized_bs, display_list_02, .init = cr_redirect_stdout)
{
    linked_list_t *list = NULL;
    char *a = "Hello!\n";

    push_to_list(&list, a);
    display_list(list, (void (*)()) &my_putstr);
    cr_assert_stdout_eq_str("Hello!\n");
}
