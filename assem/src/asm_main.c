/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:50:55 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/25 16:52:10 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_application	*ft_init_app(void)
{
	t_application *app;

	app = malloc(sizeof(t_application));
	*app = (t_application){.name = NULL};
	return (app);
}

static void				*ft_deallocate_app(t_application *app)
{
	t_token *tic;
	t_token *tac;

	tic = app->tokens;
	while (tic)
	{
		tac = tic->next;
		ft_strdel(&tic->in_file);
		ft_strdel(&tic->cur_str);
		free(tic);
		tic = tac;
	}
	ft_strdel(&app->name);
	free(app);
	return (NULL);
}

static int				ft_check_input_file_name(const char *filename)
{
	size_t len;

	if (filename != NULL)
	{
		if ((len = ft_strlen(filename)) >= 3)
		{
			if (filename[len - 1] == 's' && filename[len - 2] == '.')
				return (1);
			return (0);
		}
		return (0);
	}
	return (0);
}

/*
** Genearate output filename from input filename
*/

static char				*ft_generate_application_name(t_application *app,
		const char *name)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(name);
	app->name = ft_strsub(name, 0, len - 2);
	if (app->name)
	{
		tmp = ft_strjoin(app->name, ".cor");
		ft_strdel(&app->name);
		app->name = tmp;
	}
	else
		ft_error(ET_UNDEFINED_ERROR, NULL);
	return (app->name);
}

int						main(int ac, char *av[])
{
	t_application *compiler;

	if (ac != 2 || (ft_check_input_file_name(av[1]) == 0))
		ft_error(ET_BAD_ARGUMENT, NULL);
	compiler = ft_init_app();
	if ((compiler->fd_input = open(av[1], O_RDONLY)) == -1)
		ft_error(ET_CANT_OPEN_FILE, NULL);
	ft_generate_application_name(compiler, av[1]);
	ft_printf("%{cyn}Get source code: %{grn}%s\n", av[1]);
	ft_tokenizer(compiler);
	ft_printf("%{cyn}Reading source code: %{grn}success!%{eoc}\n");
	ft_check_app_size(compiler);
	if ((compiler->fd_output = open(compiler->name, O_CREAT | O_RDWR | O_TRUNC,
									0777)) == -1)
		ft_error(ET_CANT_CREATE_FILE, NULL);
	ft_write_app(compiler);
	close(compiler->fd_output);
	ft_printf("%{cyn}Compiling: %{grn}success!%{eoc}\n");
	ft_printf("%{cyn}Writed to: %{grn}%s%{eoc}\n", compiler->name);
	ft_deallocate_app(compiler);
	return (0);
}
