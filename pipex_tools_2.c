/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/07 14:55:20 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmp_to_stdin(char *str, char *stdin_str)
{
	size_t	str_len;
	size_t	stdin_str_len;

	str_len = ft_strlen(str);
	stdin_str_len = ft_strlen(stdin_str);
	if (!ft_strncmp(str, stdin_str, str_len) && stdin_str_len == str_len + 1)
		return (0);
	else
		return (1);
}
