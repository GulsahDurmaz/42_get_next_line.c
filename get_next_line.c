#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#  define BUFFER_SIZE 100

int len_line(char *line)
{
    int len;

    len = 0;
    if (line && line[len] == '\n')
		len++;
    return (len);
}
char *find_the_end(int fd, char *s)
{
    char    *s_new;
    int len;
    int i;

    len = len_line(s);  
    s_new = malloc((len + 1) * sizeof(char));
    if (!s_new)
        return (NULL);
    i = 0;
    while (s[i] != '\n' && s[i] != '\0')
    {
      s_new[i] = s[i];
      i++;
    }
    s_new[i] = '\0';
    return (s_new);
}

char *get_next_line(int fd)
{
    static char *buff;
    char *line;
    int buffer_size;

    buff = (char *)malloc(BUFFER_SIZE);
    read(fd, buff, BUFFER_SIZE);
    line = find_the_end(fd, buff);
    free(buff);
    return(line);
}

int main()
{
    char    *line;
    int fd;

    fd = open("test_01", O_RDONLY);
    if (fd < 0 || BUFFER_SIZE <= 0)
	    return (0);    
    line = get_next_line(fd);
    printf("%s \n", line);
    line = get_next_line(fd);
    printf("%s \n", line);
    line = get_next_line(fd);
    printf("%s \n", line);
    line = get_next_line(fd);
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