/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:02:10 by arforgea          #+#    #+#             */
/*   Updated: 2022/11/03 18:05:15 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_secur_cat(char *s1, char *s2)
{
	int		s_s1;
	int		s_s2;
	char	*f_str;

	s_s1 = 0;
	s_s2 = 0;
	if (s1)
		s_s1 = ft_strlen(s1);
	if (s2)
		s_s2 = ft_strlen(s2);
	f_str = malloc(sizeof(char) * (s_s1 + s_s2) + 1);
	if (s1)
	{
		ft_strlcpy(f_str, s1, s_s1 + 1);
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		ft_strlcpy(f_str + s_s1, s2, s_s2 + 1);
		free(s2);
		s2 = NULL;
	}
	return (f_str);
}
