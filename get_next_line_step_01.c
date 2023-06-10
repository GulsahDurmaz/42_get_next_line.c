/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_layout01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:02:41 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/06/10 14:02:56 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // read
#include <fcntl.h>  // open
#include <stdio.h>  // printf

#define BUFFER_SIZE 100

int main() {
    int fd;
    int i;
    char line[BUFFER_SIZE];

    fd = open("test_01.txt", O_RDONLY);
    if (fd < 0) 
    {
        printf("Failed to open the file.\n");
        return 1;
    }
    i = 0;
    while (read(fd, line, BUFFER_SIZE)) 
    {
        ++i;
        printf("Read line_%d: %s \n", i, line);
    }
    return 0;
}

/*
    
This code demonstrates how to read a file line by line using the read() function in C. Let's break it down step by step:

The code includes necessary header files:

unistd.h for the read() function, which is used to read from the file.
fcntl.h for the open() function, which is used to open the file.
stdio.h for the printf() function, which is used to print the read lines.
The code defines a constant BUFFER_SIZE with a value of 100, which determines the size of the buffer used to store each line.

The main() function begins:

It declares variables fd (file descriptor), i (line number), and line (buffer to store each line).
The open() function is called to open the file named "test_01.txt" in read-only mode (O_RDONLY). The file descriptor is assigned to the fd variable. If the file opening fails (fd is less than 0), an error message is printed and the program returns with a non-zero exit code.

The i variable is initialized to 0, representing the line number.

The while loop starts, which continues as long as the read() function successfully reads from the file:

The read() function reads data from the file descriptor (fd) into the line buffer with a maximum size of BUFFER_SIZE. If the reading operation fails or reaches the end of the file, it returns 0 and the loop ends.
The i variable is incremented to represent the line number.
The read line is printed using printf(), with the line number and the content of line.
After reading all the lines, the main() function returns 0, indicating successful execution.

Overall, this code opens a file, reads its contents line by line using the read() function, and prints each line with its corresponding line number.

The next step will be to stop reading when encountering '\n' while reading in BUFFER_SIZE size, and save it in a buffer string.
*/