/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:42:04 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/19 12:56:40 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_arguments(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "Too few arguments\n", ft_strlen("Too few arguments\n"));
		return (0);
	}
	if (argc > 6)
	{
		write(1, "Too many arguments\n", ft_strlen("Too many arguments\n"));
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 ||
		ft_atoi(argv[4]) <= 0)
	{
		write(1, "Invalid arguments\n", ft_strlen("Invalid arguments\n"));
		return (0);
	}
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
	{
		write(1, "Invalid arguments\n", ft_strlen("Invalid arguments\n"));
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_state *p;

	if (!check_arguments(argc, argv))
		return (-1);
	p = malloc(sizeof(t_state));
	p->num = ft_atoi(argv[1]);
	p->tdie = ft_atoi(argv[2]);
	p->teat = ft_atoi(argv[3]);
	p->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
		p->meals = ft_atoi(argv[5]);
	else
		p->meals = -1;
	if (!init(p))
		return (ft_error(p, "Memory allocation error\n"));
	if (!init_threads(p))
		return (ft_error(p, NULL)); /* Aquí hay que cambiarlo */
}
