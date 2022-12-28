/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:14:15 by pcampos-          #+#    #+#             */
/*   Updated: 2022/12/28 11:24:51 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str(char *str)
{
	if (str)
		free(str);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free_str(matrix[i]);
		i++;
	}
	if (matrix)
		free(matrix);
}

void	free_cub(t_cub *cub)
{
	free_str(cub->n);
	free_str(cub->s);
	free_str(cub->w);
	free_str(cub->e);
	free_str(cub->f);
	free_str(cub->c);
	free_matrix(cub->map);
}
