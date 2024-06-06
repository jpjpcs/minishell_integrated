/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:40:13 by joaosilva         #+#    #+#             */
/*   Updated: 2024/06/06 21:55:53 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A função expand_line aloca memória para a nova linha. O comprimento
// será o comprimento da linha original
// mais o comprimento até onde está o espaço menos a diferença entre
// 'j' e 'i' (o comprimento da parte da linha a ser substituída)
// mais 1 para o caractere nulo de terminação.
// Em C, a contagem de índices em um array (ou equivalente,
// como uma string) começa em 0.
// Portanto, se você tem um ponteiro para o início de um array,
// o primeiro elemento
// do array é acessado com ponteiro[0].
// Quando você subtrai dois ponteiros que apontam para locais na
// mesma array (como tmp - sh->line no seu código), o resultado é a diferença
// entre os índices dos dois locais na array. Por exemplo, se tmp aponta para
// o quinto elemento de sh->line, então tmp - sh->line será 4, porque a contagem
// de índices começa em 0.

#include "../../include/minishell.h"

// Esta função expande a linha inserindo uma chave entre os índices 'i' e 'j'.
int	expand(char *key, int i, int j, char **line)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_substr(*line, 0, i);
	tmp2 = ft_substr(*line, j, ft_strlen(*line) - j + 1);
	tmp3 = *line;
	free(tmp3);
	*line = ft_strjoin(tmp, key);
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(*line, tmp2);
	free(tmp);
	free(tmp2);
	return (1);
}

int	expand_free(char *key, int i, int j, char **line)
{
	expand(key, i, j, line);
	free(key);
	return (1);
}
