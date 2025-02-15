

#ifndef LISTS_H
# define LISTS_H


# include "scene.h"
# include "entity-data.h"

typedef struct s_lst
{
	int					indx;
	int					length;
	void				*cnt;
	struct s_lst		*prev;
	struct s_lst		*next;
	t_entid				type;
}	t_lst;

/*****************************************************************************/
/*                              Lists Creation                               */
t_lst		*new_lst_node(int indx, void *shape, t_entid type);
t_lst		*find_lst_last(t_lst *lst);
void		add_node_to(t_lst **lst, void *content, t_entid type);
/*                              Lists Iteration                              */
void		*get_node_at(t_lst *shps, int indx);

#endif
