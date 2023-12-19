/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansax <ansax@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:50:01 by ansax             #+#    #+#             */
/*   Updated: 2023/12/15 09:50:03 by ansax            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Deletes and frees the given node and every
 successor of that node, using the function ’del’
 and free(3).
 Finally, the pointer to the list must be set to
 NULL.*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp -> next;
		ft_lstdelone(temp, del);
		temp = next;
	}
	*lst = NULL;
}
