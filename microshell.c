/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:58:54 by anonymous         #+#    #+#             */
/*   Updated: 2024/07/28 07:05:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int err(char *ptr, int newline)
{
	while (*ptr)
		write(2, ptr++, 1);
	if (newline)
		write(2, "\n", 1);
	return 1;
}

int main(int argc, char **argv, char **envp)
{
	return err("42", 1);
}
