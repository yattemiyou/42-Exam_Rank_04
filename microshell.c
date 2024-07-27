/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:58:54 by anonymous         #+#    #+#             */
/*   Updated: 2024/07/28 08:55:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEBUG 1

int err(char *ptr, int newline)
{
	while (*ptr)
		write(2, ptr++, 1);
	if (newline)
		write(2, "\n", 1);
	return 1;
}

int cd(char **argv, int argc)
{
	if (argc != 2)
		return err("error: cd: bad arguments", 1);

	if (chdir(argv[1]) == -1)
		return err("error: cd: cannot change directory to ", 0), err(argv[1], 1);

	return 0;
}

static int prev[2];
static int fd[] = {-1, -1};

int exec(char **argv, int argc, char **envp)
{
	(void)envp;
#if DEBUG
	err("---------------", 1);
	for (int i = 0; i <= argc; i++)
		if (argv[i])
			err(argv[i], 1);
	err("---------------", 1);
#endif

	prev[0] = fd[0], prev[1] = fd[1];
	fd[0] = -1, fd[1] = -1;

	int pipeline = argv[argc] && !strcmp(argv[argc], "|");
	argv[argc] = NULL;

	if (!pipeline && !strcmp(argv[0], "cd"))
		return cd(argv, argc);

	int status = 0;

	return status;
}

int main(int argc, char **argv, char **envp)
{
	int status = 0;

	if (--argc == 0 || ++argv == NULL)
		return status;

	int offset = 0;
	for (int i = 0; i <= argc; i++)
	{
		if (i == argc || !strcmp(argv[i], "|") || !strcmp(argv[i], ";"))
		{
			if (i - offset)
				status = exec(&argv[offset], i - offset, envp);
			offset = i + 1;
		}
	}

	return status;
}
