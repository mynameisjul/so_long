/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/13 12:56:12 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map map;
	(void) ac;
	init_tmap(&map);
	map_parsing(av[1], &map);
	ft_printstrtab(map.map_data);
	ft_printinttab(map.player, 2);
	ft_printinttab(map.exit, 2);
	ft_fsplit(map.map_data);
	return (0);
}