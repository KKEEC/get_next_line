/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkc <kkc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:18:19 by kkc               #+#    #+#             */
/*   Updated: 2024/11/29 19:15:47 by kkc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"


int main() {
    int fd = open("dict.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char *line;
	int	i = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s\n", i, line);
		i++;
        free(line);
    }
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }
    return 0;
}
