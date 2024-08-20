/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:24:59 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/20 13:50:09 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static t_plane	*setup_plane_helper(t_map *map)
{
	t_plane	*temp;

	if (!map->plane)
	{
		printf("inside setup_plane_helper 1\n");
		map->plane = malloc(sizeof(t_plane));
		if (!map->plane)
			return (NULL);
		map->plane->next = NULL;
	}
	else
	{
		printf("inside setup_plane_helper 2\n");
		temp = map->plane;
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_plane));
		if (temp->next == NULL)
			return (NULL);
		temp->next->next = NULL;
		return temp->next;
	}
	return map->plane;
}

/* identifier: pl
∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
∗ R,G,B colors in range [0-255]: 0,0,225*/

int	setup_plane(char **split, t_map *map)
{
	char	**xyz;
	char	**nxyz;
    char    **rgb;
    t_plane  *new_plane;

	printf("inside setup_plane\n");
	xyz = ft_split(split[1], ',');
	nxyz = ft_split(split[2], ',');
    rgb = ft_split(split[3], ',');
	new_plane = setup_plane_helper(map);
	if (map->plane == NULL)
		return (0);
	new_plane->x = ft_atof(xyz[0]);
	new_plane->y = ft_atof(xyz[1]);
	new_plane->z = ft_atof(xyz[2]);
	new_plane->nx = ft_atof(nxyz[0]);
	new_plane->ny = ft_atof(nxyz[1]);
	new_plane->nz = ft_atof(nxyz[2]);
	new_plane->r = ft_atoi(rgb[0]);
    new_plane->g = ft_atoi(rgb[1]);
    new_plane->b = ft_atoi(rgb[2]);
	new_plane->next = NULL;
	free_split(xyz);
	free_split(nxyz);
    free_split(rgb);
	printf("end of setup_plane\n");
	return (1);
}
