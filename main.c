/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:20:52 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/13 16:48:53 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map map;
	(void) ac;
	init_tmap(&map);
	if (map_parsing(av[1], &map) == 0)
		return (0);
	if (find_path(&map) == 0)
		return (ft_dprintf(2, NO_PATH), 0);
	
	return (0);
}
