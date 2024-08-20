/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/20 13:52:04 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int read_to_parse(t_element_count *element_count, t_map *map)
{
	int		fd;
	char	*line;

	fd = open("/home/tvalimak/Hive/miniRTParse/srcs/test.rt", O_RDONLY);
	//fd = open("/home/tvalimak/miniRTparsing/srcs/test.rt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error in fd\n");
		return (0);
	}
	printf("%d\n", fd);
	line = get_next_line(fd);
	while (line)
	{
		if (validate_lines(line, element_count, map) == 0)
		{
			free(line);
			printf("Invalid file\n");
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	printf("File was valid\n");
	close(fd);
	return (1);
}
/*
int main(void)
{
    t_element_count element_count;
    t_map *map;

    ft_memset(&element_count, 0, sizeof(t_element_count));
    map = malloc(sizeof(t_map));
    setup_data(&element_count, map);
    if (!map)
        return (0);
    if (read_to_parse(&element_count, map) == 0)
        return (0);
    print_data(map);
	terminate_data(map, "program ended successfully\n");
    return (0);
}*/
