# 0x17. C - Doubly linked lists

## Task

### [0-print_dlistint](./0-print_dlistint.c)

Write a function that prints all the elements of a `dlistint_t` list.


* Prototype: `size_t print_dlistint(const dlistint_t *h);`
* Return: the number of nodes
* Format: see example

<details>
<summary>Test main</summary>

```C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *new;
    dlistint_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    n = print_dlistint(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (EXIT_SUCCESS);
}

```

</details>

**Demo**

```
$ gcc 0-main.c 0-print_dlistint.c -o a
$ ./a
9
8
-> 2 elements
$
```

---
### [1-dlistint_len](./1-dlistint_len.c)

Write a function that returns the number of elements in a linked `dlistint_t` list.

* Prototype: `size_t dlistint_len(const dlistint_t *h);`

<details>
<summary>Test Main</summary>

```C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *new;
    dlistint_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    n = dlistint_len(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (EXIT_SUCCESS);
}

```

</details>

**Demo**

```
$ gcc 1-main.c 1-dlistint_len.c -o b
$ ./b
-> 2 elements
$
```

---

### [2-add_dnodeint](./2-add_dnodeint.c)

Write a function that adds a new node at the beginning of a `dlistint_t` list.


* Prototype: `dlistint_t *add_dnodeint(dlistint_t **head, const int n);`
* Return: the address of the new element, or `NULL` if it failed

<details>
<summary>Test Main</summary>

```C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
        dlistint_t *head;

        head = NULL;
        add_dnodeint(&head, 0);
        add_dnodeint(&head, 1);
        add_dnodeint(&head, 2);
        add_dnodeint(&head, 3);
        add_dnodeint(&head, 4);
        add_dnodeint(&head, 98);
        add_dnodeint(&head, 402);
        add_dnodeint(&head, 1024);
        print_dlistint(head);


return (EXIT_SUCCESS);
}

```

</details>

**Demo**

```
$ gcc 2-main.c 2-add_dnodeint.c 0-print_dlistint.c -o c
$ ./c
1024
402
98
4
3
2
1
0
$
```

---

### [3-add_dnodeint_end](./3-add_dnodeint_end.c)

Write a function that adds a new node at the end of a `dlistint_t` list.


* Prototype: `dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);`
* Return: the address of the new element, or `NULL` if it failed

<details>
<summary>Test Main</summary>

```C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    return (EXIT_SUCCESS);
}

```

</details>

**Demo**

```
$ gcc 3-main.c 3-add_dnodeint_end.c 0-print_dlistint.c -o d
$ ./d
0
1
2
3
4
98
402
1024
$
```

---

### [4-free_dlistint](./4-free_dlistint.c)

Write a function that free a `dlistint_t` list.

* Prototype: `void free_dlistint(dlistint_t *head);`

<details>
<summary>Test Main</summary>

```C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}

```
</details>

**Demo**

```
gcc 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c -o e
$ valgrind ./e
...
...
==4197== HEAP SUMMARY:
==4197==     in use at exit: 0 bytes in 0 blocks
==4197==   total heap usage: 9 allocs, 9 frees, 1,216 bytes allocated
==4197==
==4197== All heap blocks were freed -- no leaks are poss
..
..
$
```

---

### [5-get_dnodeint](./5-get_dnodeint.c)

Write a function that returns the nth node of a `dlistint_t` linked list.


* Prototype: `dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);`
* where `index` is the index of the node, starting from `0`
* if the node does not exist, return `NULL`

<details>
<summary>Test Main</summary>

```C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *node;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    node = get_dnodeint_at_index(head, 5);
    printf("%d\n", node->n);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}

```
</details>

**Demo**

```
$ gcc 5-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 5-get_dnodeint.c -o h
$ ./h
0
1
2
3
4
98
402
1024
98
$
```

---

### [6-sum_dlistint](./6-sum_dlistint.c)

Write a function that returns the sum of all the data (n) of a `dlistint_t` linked list.


* Prototype: `int sum_dlistint(dlistint_t *head);`
* if the list is empty, return `0`

<details>
<summary>Test Main</summary>

```C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    int sum;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    sum = sum_dlistint(head);
    printf("sum = %d\n", sum);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}

```

</details>

**Demo**

```
$ gcc 6-main.c 3-add_dnodeint_end.c 4-free_dlistint.c 6-sum_dlistint.c -o i
$ ./i
sum = 1534
$
```

---

### [7-insert_dnodeint](./7-insert_dnodeint.c)

Write a function that inserts a new node at a given position.


* Prototype: `dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);`
* where `idx` is the index of the list where the new node should be added. Index starts at `0`
* Returns: the address of the new node, or `NULL` if it failed
* if it is not possible to add the new node at index `idx`, do not add the new node and return `NULL`

files `2-add_dnodeint.c` and `3-add_dnodeint_end.c` will be compiled during the correction

<details>
<summary>Test Main</summary>

```C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

void test_0(void)
{
    dlistint_t *head;
        printf("test 0: add anywhere valid\n");
    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 5, 4096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
}

void test_1(void)
{
    dlistint_t *head;
        printf("test 1: add to start\n");
    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 0, 4096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
}

void test_2(void)
{
    dlistint_t *head;
        printf("test 2: add to end\n");
    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 8, 4096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
}
void test_3(void)
{
    dlistint_t *head;
        printf("test 3: head null\n");
    head = NULL;
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 0, 4096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
}
void test_4(void)
{
    dlistint_t *head;
        printf("test 4: index out of range \n");
    head = NULL;
    add_dnodeint_end(&head, 0);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 10, 4096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
}
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
        test_0();
        test_1();
        test_2();
        test_3();
        test_4();
    return (EXIT_SUCCESS);
}
```
</details>

**Demo**

```
$ gcc 7-main.c 2-add_dnodeint.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 7-insert_dnodeint.c -o j
$ ./j
test 0: add anywhere valid
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
4096
98
402
1024
test 1: add to start
0
1
2
3
4
98
402
1024
-----------------
4096
0
1
2
3
4
98
402
1024
test 2: add to end
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
98
402
1024
4096
test 3: head null
-----------------
4096
test 4: index out of range
-----------------
0
$
```

---

### [8-delete_dnodeint](./8-delete_dnodeint.c)

Write a function that deletes the node at index `index` of a `dlistint_t` linked list.


* Prototype: `int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);`
* where `index` is the index of the node that should be deleted. Index starts at `0`
* Returns: `1` if it succeeded, `-1` if it failed

<details>
<summary>Test Main</summary>

```C
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    return (0);
}

```

</details>

**Demo**

```
$ gcc 8-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 8-delete_dnodeint.c -o k
$ ./k
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
402
1024
-----------------
1
2
3
4
402
1024
-----------------
2
3
4
402
1024
-----------------
3
4
402
1024
-----------------
4
402
1024
-----------------
402
1024
-----------------
1024
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
$
```
