#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"
#include "../bootstrap.h"
#include "../secured_bs.h"

Test(secured_bs, create_address_book_01, .init = cr_redirect_stdout)
{
    entry_t **book = create_address_book(5);
    cr_assert_stdout_eq_str("address book created\n");
}
