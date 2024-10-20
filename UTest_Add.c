#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "add.h"

int __wrap_add_numbers(int a, int b)
{
    check_expected(a);
    check_expected(b);
    return mock();
}

static void test_calculate_sum(__attribute__((unused)) void **state)
{
    expect_value(__wrap_add_numbers, a, 10);
    expect_value(__wrap_add_numbers, b, 30);
    will_return(__wrap_add_numbers, 40);

    expect_value(__wrap_add_numbers, a, 11);
    expect_value(__wrap_add_numbers, b, 33);
    will_return(__wrap_add_numbers, 44);

    int results[2] = {0};

    int status = calculate_sum(results);

    assert_int_equal(results[0], 40);
    assert_int_equal(results[1], 44); 
    assert_int_equal(status, 0);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_calculate_sum),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
