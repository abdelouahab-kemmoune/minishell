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

void    parsing(char *input, t_token **token)
{
    if (!input || !token)
        return ;
    if (*input == '|')
    {
        write(1, "minishell: parse error near `|'", ft_strlen("zsh: parse error near `|'"));
        exit (1);
    }
    if ((*token)->type == WORD)
    {
        if (ft_strncmp((*token)->value, "echo", 4))
        {
            if (ft_strncmp((*token)->next->value, "-n", 2))
            {
                //To_do later in execution, write without \n
            }
            //To_do later in execution, write with \n
        }
    }
}