
//old version if fails mar 13, 2019

// char ***create_map(char **str_spltd)
// {
// 	printf("\n+++Entering create_map +++\n");
// 	char ***map;
// 	int y;
// 	int x;
// 	int i;
// 	int lines;
// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	lines = 0;
// 	while (str_spltd[lines] != NULL)
// 		lines++;
// 	printf("lines is |%d|\n",lines);
// 	map = (char ***)malloc((lines + 1) * sizeof(char **));
// 	if (map == NULL)
// 		return (NULL);
// 	while (str_spltd[i] != NULL)
// 	{
// 		map[i] = ft_strsplit(str_spltd[i], ' ');
// 		i++;
// 	}
// 	printf("i is |%d|\n",i);
// 	map[lines] = NULL;
// 	printf("y is %d\n", y);
// 	while (map[y] != NULL)
// 	{
// 		printf("LOOP: y is %d\n", y);
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			printf("map [%d][%d] |%s|\n", y, x, map[y][x]);
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (map[y] == NULL)
// 	{
// 		printf("y is null\n");
// 	}
// 	return (map);
// }


// int main(int argc, char **argv)
// {
// 	t_mlx 	*st_mlx;
// 	t_map 	*st_map;
// 	t_line 	*st_line;
// 	t_img	*st_img;
// 	int 	fd;
//  	if (argc == 2)
//  	{
//  		fd = open(argv[1], O_RDONLY);
//  		if(!(check_valid_file(fd)))//, &(map->str_map))))
//  		{
// 			ft_putstr("Found wrong line length. Exiting.\n");
// 			return (0);
// 		}

// 		char **test;
// 		char m[100] = "00 01 02,00xf123fd 03 04  05 \n 10 11 12 13 14 15\n 20 21 22 23 24 25";
// 		test = ft_strsplit(m,'\n');
// 		st_map->map = create_map(test);
// 		//window_init(&mlx->mlx_ptr, &mlx->win_ptr, &mlx->img_ptr);
		
// 	}
// 	else
// 	{
// 		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
// 	}
// 	return (0);
// }


//update create_map

// char ***create_map(char **str_spltd)
// {
// 	char ***map;
// 	int y;
// 	int x;
// 	int i;
// 	int lines;
	
// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	lines = 0;

// 	while (str_spltd[lines] != NULL)
// 		lines++;

// 	if ((map = (char ***)malloc((lines + 1) * sizeof(char **))) == NULL)
// 		return (NULL);
	
// 	while (str_spltd[i] != NULL)
// 	{
// 		map[i] = ft_strsplit(str_spltd[i], ' ');
// 		i++;
// 	}
// 	map[lines] = NULL;
// 	return (map);
// }