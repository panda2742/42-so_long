/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:14:40 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 16:36:55 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_update_status(t_sl *sl, int err);
static int	_error_handler(int status);
static void	_free_everything(t_sl *sl);

int	parse_map(t_sl *sl, const char *filename)
{
	const size_t	filename_len = ft_strlen(filename);
	char			*line;
	size_t			i;
	size_t			j;
	char			c;

	// FILENAME
	if (NULL == filename || 0 == filename[0])
		return (_update_status(sl, E_FILENAME));

	// EXTENSION
	if (0 != ft_strncmp(&filename[filename_len - 4], ".ber", 4))
		_update_status(sl, E_FILEEXT);

	// OPEN
	sl->map_fd = open(filename, O_RDONLY);
	if (sl->map_fd < 0)
		return (_update_status(sl, E_OPENFD));

	// LINE GET
	line = get_next_line(sl->map_fd);
	if (NULL == line)
		return (_update_status(sl, E_MALLOC));

	// LINE LEN
	sl->height = 0;
	sl->width = ft_strlenc(line, '\n');
	while (line)
	{
		if (ft_strlenc(line, '\n') != sl->width)
		{
			free(line);
			return (_update_status(sl, E_LINELEN));
		}
		free(line);
		line = get_next_line(sl->map_fd);
		sl->height++;
	}
	free(line);

	// CLOSE FIRST READ
	if (close(sl->map_fd) < 0)
		return (_update_status(sl, E_CLOSEFD));
	
	// REOPEN
	sl->map_fd = open(filename, O_RDONLY);
	if (sl->map_fd < 0)
		return (_update_status(sl, E_OPENFD));
	
	// LINE GET
	line = get_next_line(sl->map_fd);
	if (NULL == line)
		return (_update_status(sl, E_MALLOC));
	sl->width = ft_strlenc(line, '\n');

	// LINE FILL
	sl->sl_len = sl->width * sl->height;
	sl->lines = malloc(sl->sl_len * sizeof(int));
	if (NULL == sl->lines)
	{
		free(line);
		return (_update_status(sl, E_MALLOC));
	}

	i = 0;
	while (line)
	{
		j = -1;
		while (++j < sl->width)
		{
			c = line[j];
			if (c == '1')
				sl->lines[i++] = WALL;
			else if (c == '0')
				sl->lines[i++] = FLOOR;
			else if (c == 'P')
				sl->lines[i++] = PLAYER;
			else if (c == 'C')
				sl->lines[i++] = COLLECTIBLE;
			else if (c == 'E')
				sl->lines[i++] = END;
			else
				_update_status(sl, E_WRONGTILE);
		}
		free(line);
		line = get_next_line(sl->map_fd);
	}
	free(line);
	return (sl->status);
}

static int	_update_status(t_sl *sl, int err)
{
	sl->status |= err;
	return (sl->status);
}

static int	_error_handler(int status)
{
	static char	*errors[7] = {
		" [-] Filename error.\n",
		" [-] File extension error.\n",
		" [-] Error while opening map.\n",
		" [-] The map is not a rectangle.\n",
		" [-] A heap memory allocation failed.\n",
		" [-] Error while closing map.\n",
		" [-] An invalid character is present.\n"
	};
	const int	bits = sizeof(status) * 8;
	int			i;

	if (0 == status)
		return (EXIT_SUCCESS);
	ft_eprintf(RED "Error\n  |  Code %d:\n", status);
	i = -1;
	while (++i < bits)
	{
		if (status & (1 << i))
			ft_eprintf(errors[i]);
	}
	ft_eprintf(RESET);
	return (EXIT_FAILURE);
}

static void	_free_everything(t_sl *sl)
{
	if (sl->lines)
		free(sl->lines);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	int		res;
	
	(void)argc;
	sl.height = 0;
	sl.map_fd = -1;
	sl.status = 0b0;
	sl.height = 0;
	sl.sl_len = 0;
	sl.lines = NULL;
	res = parse_map(&sl, argv[1]);
	_free_everything(&sl);
	return (_error_handler(sl.status));
}
