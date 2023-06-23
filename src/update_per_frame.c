/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_per_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:19:07 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 02:19:47 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_per_frame(t_game *game)
{
	put_map(game);
	put_object(game);
	put_sprite_with_animation(game);
	return (0);
}

