/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:56:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/24 23:57:26 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_collec(map *data, counts *elements)
{
	int	i;
	int	j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j] != '\n' && data->lines[i][j] != '\0')
		{
			if (data->lines[i][j] == 'C' || data->lines[i][j] == 'E')
			{
				free(elements);
				free_split(data->lines);
				ft_error("map not valid : flodd_fill failed\n", data);
			}
			j++;
		}
		i++;
	}
}

int check_key(int button, void *data_ptr)
{
	game *data = data_ptr;

    if (button == ESC_KEY)
    {
        mlx_destroy_window(data->connection, data->window);
        exit(0);
    }
    return 0;
}
int exit_button(void *par)
{
	(void)par;
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int	        fd;
	map	        *data;
    position    player;
	game		window;
	image		player_image;
	char *file_path[] = {
		/* XPM */
/* columns rows colors chars-per-pixel */
"23 21 71 1 ",
"  c black",
". c #010000",
"X c #000100",
"o c #010101",
"O c #020001",
"+ c #000002",
"@ c #040507",
"# c #030708",
"$ c #050608",
"% c #05060A",
"& c #1C2931",
"* c #1D2A30",
"= c #1D2A32",
"- c #1F3038",
"; c #202E37",
": c #212F38",
"> c #212F3A",
", c #213037",
"< c #312F44",
"1 c #263A45",
"2 c #273B46",
"3 c #263C47",
"4 c #263C49",
"5 c #273D4A",
"6 c #263E4A",
"7 c #283B49",
"8 c #293C4A",
"9 c #3D4A52",
"0 c #3E7392",
"q c #3E7393",
"w c #3E7490",
"e c #427EA0",
"r c #437EA0",
"t c #437DA2",
"y c #427EA2",
"u c #437FA3",
"i c #447FA1",
"p c #892983",
"a c #8B2883",
"s c #9B2890",
"d c #9D2891",
"f c #57879E",
"g c #4480A4",
"h c #4785AA",
"j c #4686AA",
"k c #4787AB",
"l c #4785AC",
"z c #4985AA",
"x c #4886AB",
"c c #5A8FAE",
"v c #4C8FB9",
"b c #4C8FBA",
"n c #4B92BC",
"m c #4E91BC",
"M c #4D92BC",
"N c #4E93BD",
"B c #4D91BE",
"V c #659AB9",
"C c #D8B78E",
"Z c #C4AF90",
"A c #C5B294",
"S c #C6B395",
"D c #E7CFA9",
"F c #E6CEAA",
"G c #F9D3A4",
"H c #F9D3A6",
"J c #FFD7A9",
"K c #FFD7AB",
"L c #E7EFF2",
"P c #FFFEFF",
"I c white",
/* pixels */
"   o   X  +   + ..     ",
"  ..  $$@$$%$$#$# o    ",
"    o$-121;354555$     ",
"    $<>ec09bMMMMM5$    ",
"    :s:rI:PrMhBMMh:   +",
"    :p:rI:IrM7mMM8>    ",
"   o=:<0L1LrMMMMNn:   o",
"     :d:rrrrMMNnMM:  . ",
"     :a:rrervMzhjh:    ",
"     ==:0irguM5:===. . ",
"  +  . =:rfVVVV: X   . ",
"     X$$:rCJJJJ:    o  ",
"  +   :56yCJJKJ-       ",
"      ,lviZFHGD:   OX. ",
"  X+ o=:wruMSAM:      +",
"+      =:tMkhvM: o  +  ",
"        :ex=:tx&       ",
"        :0* :q=        ",
"        ==  ==         ",
"                       ",
"                       "
};

	fd = 0;
    player.x = 0;
    player.y = 0;
    if (argc != 2)
	{
		ft_putstr_fd("invalid arguments : args should be ./so_long (map path)\n", 2);
		exit(1);
	}
	if (check_file_name(argv[1]) == 1)
		fd = open_file(argv[1]);
	else
	{
		ft_putstr_fd("map name should end up with (.ber)\n",2);
		exit(1);
	}
	if (read_file(fd) == 1)
	{
		data = fill_map(fd, argv[1]);
		if (check_map(data, player.x, player.y) == 1)
		{
			int image_width = data->width * 64;
			int image_height = data->height * 64;
			window.connection = mlx_init();
			window.window = mlx_new_window(window.connection, data->width * 64, data->height * 64, "so_long");
			mlx_key_hook(window.window, check_key, &window);
			player_image.img = mlx_xpm_to_image(window.connection, file_path, &image_width, &image_height);
			mlx_put_image_to_window(window.connection, window.window, player_image.img, 300, 300);
			mlx_hook(window.window, 17, 0, exit_button, NULL);
			mlx_loop(window.connection);
			// free_split(data->lines);
            // free(data);
		}
	}
}
