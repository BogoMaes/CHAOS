/* coucou ici c'est le projet chaos
 * ca sert a rien a part faire chier
 * tout du moins ca a ete cree pour ca
 * si tu vois une utilite dis le moi gdirlewa@student.42.fr
 * voila ...
 * enjoy
 */

int chaos(int ac, char **av)
{
	int fd;
	char *line;
	int f;
	char **data;
	int i;

	i = 0;
	data = (char **)malloc(sizeof(char*) * 6);
	data[0] = (char *)malloc(10);
	data[0] = "/bin/echo\0";
	data[1] = (char *)malloc(5);
	data[1] = "echo\0";
	data[3] = (char *)malloc(3);
	data[3] = ">>\0";
	fd = open(av[ac - 1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{

		f = fork();
		if (f == -1)
			continue();
		if (f == 0)
		{
			data[2] = line;
			data[4] = ft_itoa(i);
			execv("/bin/echo", data);
		}
		if(f > 0)
		{
			waitpid(f);
			free(line);
		}
		++i;
	}
	return (1);
}
