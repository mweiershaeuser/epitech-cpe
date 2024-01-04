#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"
#include "../bootstrap.h"
#include "../secured_bs.h"

void print_name(entry_t *address)
{
    my_putstr(address->name);
    my_putchar('\n');
}

Test(secured_bs, execute_on_address_book, .init = cr_redirect_stdout)
{
    entry_t **book = create_address_book(3);
    add_address(book, 3, "Melvin", "+49 123 456789");
    add_address(book, 3, "Leticia", "+55 123 456789");
    add_address(book, 3, "Jose", "+34 123 456789");
    execute_on_address_book(book, 3, &print_name);
    cr_assert_stdout_eq_str("address book created\nnew address added\nnew address added\nnew address added\nMelvin\nLeticia\nJose\n");
}
