/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:26:31 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/20 13:50:04 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static t_light	*setup_light_helper(t_map *map)
{
	t_light	*temp;

	if (!map->light)
	{
		printf("inside setup_light_helper 1\n");
		map->light = malloc(sizeof(t_light));
		if (!map->light)
			return (NULL);
		map->light->next = NULL;
	}
	else
	{
		printf("inside setup_light_helper 2\n");
		temp = map->light;
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_light));
		if (temp->next == NULL)
			return (NULL);
		temp->next->next = NULL;
		return temp->next;
	}
	return map->light;
}

/*∗ identifier: L
∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
∗ the light brightness ratio in range [0.0,1.0]: 0.6
∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255*/

int	setup_light(char **split, t_map *map)
{
	char		**rgb;
	char		**xyz;
    t_light  	*new_light;

	printf("inside setup_light\n");
	xyz = ft_split(split[1], ',');
	rgb = ft_split(split[3], ',');
	new_light = setup_light_helper(map);
	if (map->light == NULL)
		return (0);
	printf("inside setup_light 1\n");
	new_light->x = ft_atof(xyz[0]);
	new_light->y = ft_atof(xyz[1]);
	new_light->z = ft_atof(xyz[2]);
	new_light->ratio = ft_atof(split[2]);
	new_light->r = ft_atoi(rgb[0]);
	new_light->g = ft_atoi(rgb[1]);
	new_light->b = ft_atoi(rgb[2]);
	new_light->next = NULL;
	free_split(xyz);
	free_split(rgb);
	printf("end of setup_light\n");
	return (1);
}
