#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"
#include "../bootstrap.h"
#include "../secured_bs.h"

Test(secured_bs, add_address01, .init = cr_redirect_stdout)
{
    entry_t **book = create_address_book(3);
    add_address(book, 3, "Melvin", "+49 123 456789");
    add_address(book, 3, "Leticia", "+55 123 456789");
    add_address(book, 3, "Jose", "+34 123 456789");
    add_address(book, 3, "Marvin", "+33 123 456789");
    cr_assert_stdout_eq_str("address book created\nnew address added\nnew address added\nnew address added\nadd_address: not enough capacity to store new address\n");
}
