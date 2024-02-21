#include <criterion/criterion.h>
#include "../my.h"
#include "../bootstrap.h"
#include "../secured_bs.h"

Test(secured_bs, create_address_01)
{
    entry_t *address = create_address("Marvin", "+33 654321");
    cr_assert_str_eq(address->name, "Marvin");
    cr_assert_str_eq(address->phone_number, "+33 654321");
}
