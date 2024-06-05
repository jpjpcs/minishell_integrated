/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:04:28 by luide-so          #+#    #+#             */
/*   Updated: 2024/05/30 00:45:32 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" 

static void	sig_quit(int sig) 
{
	if (sig == SIGINT) // If signal is CTRL+C (interrupt)
		write(1, "\n", 1); // Writes a new line on the standart output
	else if (sig == SIGQUIT) // If signal is CTRL+\ (quit)
		ft_putendl_fd("Quit (core dumped)", 1); // Prints message on standart output
}

static void	sigrestore(int sig) //  Restores default shell behavior after SIGINT
{
	(void)sig; 
	g_exit = 130; // Defines global exit variable to 130
	write(1, "\n", 1); // Writes a new line on the standart output
	rl_on_new_line(); // Initiate a new line
	rl_replace_line("", 0); // Replace the actual line to a empty one
	rl_redisplay(); // Displays command line
}

static void	sig_here_doc(int sig) // Deals with interruptions on heredocs
{
	if (sig != SIGINT) // Only accepts SIGINT
		return; 
	exit(130); 
}

static void	sigint_ignore(int sig) // Ignores SIGINT
{
	if (sig == SIGINT) // If sig is equal to SIGINT
	{
		g_exit = 130; 
		ft_putstr_fd("\n", 2); // Prints a newline on the error output
		signal(SIGINT, SIG_IGN); // Ignores SIGINT if its called
	}
}

void	signal_handler(int sig) 
{
	if (sig == SIGRESTORE) 
	{
		signal(SIGINT, sigrestore); // If SIGINT is used, call handler to sigrestore
		signal(SIGQUIT, SIG_IGN); // If SIGQUIT is used, call handler to SIG_IGN (ignore this signal)
	}
	if (sig == SIGHEREDOC) 
	{
		signal(SIGINT, sig_here_doc); 
		signal(SIGQUIT, SIG_IGN); 
	}
	if (sig == SIGCHILD)
	{
		signal(SIGINT, sig_quit); 
		signal(SIGQUIT, sig_quit); 
	}
	if (sig == SIGPIPE) 
	{
		signal(SIGINT, sigint_ignore); 
		signal(SIGQUIT, SIG_IGN); 
    }
	if (sig == SIGIGNORE) 
	{
		signal(SIGINT, SIG_IGN); 
		signal(SIGQUIT, SIG_IGN); 
	}
}
