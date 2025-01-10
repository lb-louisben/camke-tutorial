#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "array_print.h"
#include "log_manage.h"

int main()
{
    int a = 20;
    int b = 12;
    int arr[] = {1, 2, 3, 4, 5};
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));
    print_array(arr, 5);

    create_log("This is an info message", "2021-07-01 12:00:00", INFO);
    create_log("This is a warning message", "2021-07-01 12:01:00", WARNING);

    log_print();

    return 0;
}
