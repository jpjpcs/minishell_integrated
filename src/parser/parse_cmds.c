/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:10:56 by joaosilva         #+#    #+#             */
/*   Updated: 2024/06/06 22:11:40 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Token é o argumento. O argumento é o que vem depois do operador de 
//redirecionamento "<" ou ">".
// O while verifica se o próximo token é "<" ou ">".
// O type atribui um toke type que pode ser "<", ">", 
// "<<, ">>", "|", ou "a".
// O segundo if verifica se o token não for argumento ou se o 
//token for "<" e o próximo token for ">".
static t_cmd	*parseredir(t_cmd *cmd, t_shell *shell)
{
	int		type;
	char	*token;

	while (peek(shell, "<>"))
	{
		type = gettoken(shell, NULL);
		if (gettoken(shell, &token) != 'a')
		{
			if (type != '<' || (type == '<' && ft_strcmp(token, ">")))
				return (print_error_syntax(shell, token, 2), cmd);
			else if (gettoken(shell, &token) != 'a')
				return (print_error_syntax(shell, token, 2), cmd);
		}
		if (type == '<')
			cmd = redir_cmd(cmd, token, O_RDONLY, 0);
		else if (type == '>')
			cmd = redir_cmd(cmd, token, O_WRONLY | O_CREAT | O_TRUNC, 1);
		else if (type == APPEND)
			cmd = redir_cmd(cmd, token, O_WRONLY | O_CREAT | O_APPEND, 1);
		else if (type == HERE_DOC)
			cmd = here_cmd(cmd, token);
	}
	return (cmd);
}

static t_cmd	*parseexec(t_shell *shell)
{
	t_cmd	*ret;
	t_exec	*cmd;
	char	*token;
	int		type;

	ret = exec_cmd();
	cmd = (t_exec *)ret;
	ret = parseredir(ret, shell);
	while (!peek(shell, "|"))
	{
		type = gettoken(shell, &token);
		if (!type)
			break ;
		if (type != 'a' && shell->status == CONTINUE)
			return (print_error_syntax(shell, token, 2), ret);
		if (cmd->argv[0])
			cmd->argv[0] = ft_strjoin_free_s1(cmd->argv[0], " ");
		cmd->argv[0] = ft_strjoin_free_s1(cmd->argv[0], token);
		ret = parseredir(ret, shell);
	}
	return (ret);
}

t_cmd	*parsepipe(t_shell *shell)
{
	t_cmd	*cmd;

	if (peek(shell, "|") && shell->status == CONTINUE)
		return (print_error_syntax(shell, shell->ps, 2), NULL);
	cmd = parseexec(shell);
	if (cmd && peek(shell, "|"))
	{
		gettoken(shell, NULL);
		cmd = pipe_cmd(cmd, parsepipe(shell));
	}
	return (cmd);
}
