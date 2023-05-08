# 0x15. C - File I/O

## Tasks

#### [0-read_textfile.c](./0-read_textfile.c)
- Prototype: `ssize_t read_textfile(const char *filename, size_t letters);`
- where letters is the number of letters it should read and print
- returns the actual number of letters it could read and print
- if the file can not be opened or read, return `0`
- if `filename` is `NULL` return `0`
- if `write` fails or does not write the expected amount of bytes, return `0`

<details>
<summary>Test File</summary>
    
```
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.
```

</details>

<details>
<summary>cat 0-main.c</summary>
    
```C
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
    }
    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);
    return (0);
}
```
</details>

##### OUTPUT
```
$ ./a Requiescat
Requiescat
by Oscar Wilde
...
...
...
(printed chars: 468)
$
```
---

### [1-create_file.c](./1-create_file.c)

* Prototype: `int create_file(const char *filename, char *text_content);`
* where `filename` is the name of the file to create and `text_content` is a `NULL` terminated string to write to the file
* Returns: `1` on success, `-1` on failure (file can not be created, file can not be written, `write` “fails”, etc…)
* The created file must have those permissions: `rw-------`. If the file already exists, do not change the permissions.
* if the file already exists, truncate it
* if `filename` is `NULL` return `-1`
* if `text_content` is `NULL` create an empty file

<details>
<summary>cat 1-main.c</summary>

```C
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = create_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
```

</details>

#### OUTPUT

```
$ alias gccw="gcc -Wall -pedantic -Werror -Wextra" 
$ gccw 1-main.c 1-create_file.c -o b
$ ./b hello world
-> 1)
$ cat -e hello
world
```
---

### [2-append_text_to_file.c](./2-append_text_to_file.c)

* Prototype: `int append_text_to_file(const char *filename, char *text_content);`
* where `filename` is the name of the file and `text_content` is the `NULL` terminated string to add at the end of the file
* Return: `1` on success and `-1` on failure
* Do not create the file if it does not exist
* If `filename` is `NULL` return `-1`
* If `text_content` is `NULL`, do not add anything to the file. Return `1` if the file exists and `-1` if the file does not exist or if you do not have the required per  missions to write the file

<details>
<summary>cat 2-main.c</summary>

```C
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = append_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
```

</details>

#### OUTPUT

```
$ alias gccw="gcc -Wall -pedantic -Werror -Wextra" 
$ gccw 2-main.c 2-append_text_to_file.c -o c
$ ./c hello world
-> 1)
$ cat -e hello
world
```
---

### [3-cp.c](./3-cp.c)

* Usage: `cp file_from file_to`
* if the number of argument is not the correct one, exit with code `97` and print `Usage: cp file_from file_to`, followed by a new line, on the `POSIX` standard error
* if `file_to` already exists, truncate it
* if `file_from` does not exist, or if you can not read it, exit with code `98` and print `Error: Can't read from file NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error
where `NAME_OF_THE_FILE` is the first argument passed to your program
* if you can not create or if `write` to `file_to` fails, exit with code `99` and print `Error: Can't write to NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error
where `NAME_OF_THE_FILE` is the second argument passed to your program
* if you can not close a file descriptor , exit with code `100` and print `Error: Can't close fd FD_VALUE`, followed by a new line, on the `POSIX` standard error
where `FD_VALUE` is the value of the file descriptor
* Permissions of the created file: `rw-rw-r--`. If the file already exists, do not change the permissions
* You must read `1,024` bytes at a time from the `file_from` to make less system calls. Use a buffer
* You are allowed to use `dprintf`
<details>
<summary>3-cp.c</summary>

```
```

</details>

#### OUTPUT

```
$ alias gccw="gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-cp.c"
$ ./cp incitatous Incitatous
-> 1)
$ cat -e Incitatous
world
```
---

### [100-elf_header.c](./100-elf_header.c)

* Usage: `elf_header elf_filename`
* Displayed information: (no less, no more, do not include trailing whitespace)
Magic
Class
Data
Version
OS/ABI
ABI Version
Type
Entry point address
* Format: the same as `readelf -h` (version `2.26.1`)
* If the file is not an `ELF` file, or on error, exit with status code `98` and display a comprehensive error message to `stderr`
* You are allowed to use `lseek` once
* You are allowed to use `read` a maximum of 2 times at runtime
* You are allowed to have as many functions as you want in your source file
* You are allowed to use `printf`
man `elf`, `readelf`

<details>
<summary>cat 100-elf_header.c</summary>

```
```

</details>

#### OUTPUT

```
$ alias gccw="gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-elf_header.c -0 elf_header"
$ gccw elf_header 100-elf_header.c -o b
$ ./elf_header ubuntu64
-> 1)
$ ./elf_header sparc32
```
