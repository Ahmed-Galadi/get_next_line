/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:42:39 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/01 21:59:40 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

my_list	*ft_lstlast(my_list *lst)
{
	my_list	*curr;
	int		last_lst;

	if (lst == NULL)
		return (NULL);
	last_lst = ft_lstsize(lst) - 1;
	curr = lst;
	while (curr != NULL && last_lst)
	{
		curr = curr->next;
		last_lst--;
	}
	return (curr);
}

void	ft_lstadd_back(my_list **lst, my_list *new)
{
	my_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
	}
}

my_list	*ft_lstnew(void *content)
{
	my_list	*ret_lst;

	ret_lst = (my_list *)malloc(sizeof(my_list));
	if (ret_lst == NULL)
		return (NULL);
	ret_lst->str = content;
	ret_lst->next = NULL;
	return (ret_lst);
}