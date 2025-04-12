/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:32:00 by akemmoun          #+#    #+#             */
/*   Updated: 2025/04/12 20:54:28 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	add_token(t_token **head, char *value, t_token_type type)
{
	t_token *new;

	new = malloc (sizeof(t_token));
	if (!new)
		return ;
	
	new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		t_token *temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	word_case(char *input, int *i, t_token **token_list)
{
	int start;
	char *word;

	start = *i;
	while (input[*i] && input[*i] != ' ' && input[*i] != '\t' && \
	input[*i] !='|' && input[*i] != '>' && input[*i] != '<')
		i++;
	word = strndup(&input[start], *i - start);
	add_token(&token_list, word, WORD);
	free(word);
}


void	lexer(char *input)
{
	t_token *token_list;
	int i = 0;

	while (input[i])
	{
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] == '|')
			add_token(&token_list, "|", PIPE);
		else if (input[i] == '>')
		{
			if (input[i+1] == '>')
			{
				add_token(&token_list, ">>", APPEND);
				i += 2;
			}
			else 
			{
				add_token(&token_list, ">", REDIR_IN);
				i++;
			}
		}
		else if (input[i] == '<')
		{
			if (input[i+1] == '<')
			{
				add_token(&token_list, "<<", HEREDOC);
				i += 2;
			}
			else 
			{
				add_token(&token_list, "<", REDIR_IN);
				i++;
			}
		}
		else
			word_case(input, &i, &token_list);
	}
}
