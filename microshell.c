/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:58:54 by anonymous         #+#    #+#             */
/*   Updated: 2024/07/28 07:46:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

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

int exec(char **argv, int argc, char **envp)
{
	(void)envp;

	int status = 0;

	err("---------------", 1);
	for (int i = 0; i <= argc; i++)
		if (argv[i])
			err(argv[i], 1);
	err("---------------", 1);

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
