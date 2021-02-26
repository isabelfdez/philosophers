/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:14:06 by isfernan          #+#    #+#             */
/*   Updated: 2021/02/26 16:18:11 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void    prueba(void *a)
{
    int *z;

    z = a;
    printf("el número recibido es %i\n", *z);
}


int main()
{
    int *a;

    a = malloc(sizeof(int));
    *a = 36;
    printf("el número indicado por el puntero es %i\n", *a);
    prueba(a);
}