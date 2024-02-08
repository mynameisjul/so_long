/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:31:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/08 12:35:32 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map(char *file_name)
{
	int	fd;
	int	len;

	fd = -1;
	if (file_name)
	{
		len = ft_strlen(file_name);
		if (ft_strncmp(&file_name[len - 4], ".ber", 5) == 0 && len > 4)
			fd = open(file_name, O_RDONLY, 0644);
	}
	return (fd);
}


