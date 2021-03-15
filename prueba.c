/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:14:06 by isfernan          #+#    #+#             */
/*   Updated: 2021/03/15 19:13:15 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


typedef struct s_hola
{
    int    *a;
}               t_hola;

int main()
{
    printf("size = %lu\n", sizeof(t_hola));
    return (0);
}