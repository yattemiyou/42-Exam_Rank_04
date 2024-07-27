/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:58:54 by anonymous         #+#    #+#             */
/*   Updated: 2024/07/28 07:35:25 by anonymous        ###   ########.fr       */
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
