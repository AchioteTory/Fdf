#include <stdio.h>  /** todo: delete */
#include "fdf.h"

void	error_case(void)
{
	exit(-1);
}

int	esc(maps *map)
{
	exit(0);
	return (0);
}

int key_event(int key, maps *map, t_frame *image)
{
	if (key == 53)
		esc(map);
	if (key == 124)
		map->move_x += 50;
	if (key == 123)
		map->move_x -= 50;
	if (key == 125)
		map->move_y += 50;
	if (key == 126)
		map->move_y -= 50;
	if (key == 69)
		map->scale += 2;
	if (key == 78)
		map->scale -= 2;
	if ((key > 122 && key < 127) || key == 69 || key == 78)
	{
		mlx_clear_window(map->mlx, map->win);
		render(map);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	maps	map;

	if (argc > 2 || argc == 1)
		error_case();
	parse_me(argv[1], &map);

	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1920, 1080, "FDF");
	map.scale = 1;

	render(&map);

	mlx_key_hook(map.win, key_event, &map);
	mlx_hook(map.win, 2, 0, key_event, &map);
	mlx_hook(map.win, 17, 0, esc, &map);

	mlx_loop(map.mlx);


//	i = 0;
//	while (i < map.y)
//	{
//		j = 0;
//		while (j < map.x)
//		{
//			printf("%2.0f,", map.z[i][j].depth);
//			printf("%d", map.z[i][j].color);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
//	while (1)
//		;
	return (1);
}