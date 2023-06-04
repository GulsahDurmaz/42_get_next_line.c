#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#  define BUFFER_SIZE 1000

char *find_the_end(char *s)
{
    char    *s_new;
    int i;

    i = 0;
    s_new = malloc(BUFFER_SIZE);
    while (s[i] != '\n' || s[i] != '\0')
        s_new[i] = s[i];
        i++;
    return (s_new);
}
char *get_next_line(int fd)
{
    char *buff;
    char *linee;
    int len;

    buff = (char *)malloc(BUFFER_SIZE);
    read(fd, buff, BUFFER_SIZE);
    return(buff);
}

int main()
{
    char    *line;
    int fd;

    fd = open("test_01", O_RDONLY);
    line = get_next_line(fd);

//  read(fd, buff, 10);
//   write(1, line, 10);
    printf("%s \n", line);
    return(0);
}
/*
    #include <unistd.h>
    ssize_t read(int fd, void *buf, size_t count);

    DESCRIPTION         top

       read() attempts to read up to count bytes from file descriptor fd
       into the buffer starting at buf.

       On files that support seeking, the read operation commences at
       the file offset, and the file offset is incremented by the number
       of bytes read.  If the file offset is at or past the end of file,
       no bytes are read, and read() returns zero.

       If count is zero, read() may detect the errors described below.
       In the absence of any errors, or if read() does not check for
       errors, a read() with a count of 0 returns zero and has no other
       effects.

       According to POSIX.1, if count is greater than SSIZE_MAX, the
       result is implementation-defined; see NOTES for the upper limit
       on Linux.

    The types size_t and ssize_t are, respectively, unsigned and
    signed integer data types specified by POSIX.1.

    #include <fcntl.h>

       int open(const char *pathname, int flags);


*/