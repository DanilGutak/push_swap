/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:13:15 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/19 11:34:30 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define OPEN_MAX 8192

# include <stddef.h>   
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	*input;
	int		*stack_a;
	int		stack_a_count;
	int		*indexes;
	int		*stack_b;
	int		stack_b_count;
	int		chunk_size;
	int		chunk_num;
	int		chunk_last_size;
	int		read_chunk;
	int		end;
	char	cmd[4];
	char *gnl_buffer;
	int		flag;
}			t_data;

char	*get_next_line(int fd, t_data *data);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
