/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:23:09 by akemmoun          #+#    #+#             */
/*   Updated: 2025/04/11 13:23:10 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_echo_helper(t_token **token, char *s)
{
	*token = (*token)->next;
	if ((*token)->type == WORD)
	{
		s = (*token)->value;
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
	else
		return ;
}

void	ft_echo(t_token **token)
{
	char	*s;

	if ((*token)->type == WORD)
	{
		if (ft_strncmp((*token)->value, "echo", 4) == 0)
		{
			*token = (*token)->next;
			if (ft_strncmp((*token)->value, "-n", 2) == 0)
				ft_echo_helper(token, &s);
			else if ((*token)->type == WORD)
			{
				s = (*token)->value;
				while (*s)
				{
					write(1, s, 1);
					s++;
				}
				write(1, "\n", 1);
			}
			else
				return ;
		}
	}
}

void    parsing(char *input, t_token **token)
{
	char	*s;

	if (!input || !token)
		return ;
	if (*input == '|')
	{
		write(1, "minishell: parse error near `|'", ft_strlen("minishell: parse error near `|'"));
		exit (1);
	}
}
