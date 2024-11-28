
#include "parsing.h"
#include "libft.h"

int	is_chneg(const char *line, int *offset)
{
	if (line[0] == '-')
	{
		(*offset)++;
		return (-1);
	}
	return (1);
}

int	eval_vec_type(int commas, int type)
{
	if (type)
	{
		if (commas == VEC3)
			return (1);
		return (0);
	}
	else
	{
		if (commas == VEC2)
			return (1);
		return (0);
	}
}

/**
 * @brief It checks the vector format in a string. Evaluating the number
 * of commas. Valid vectors: ex. 0,0,0 0,0 
 */
int	is_vec_format(const char *line, t_vec_type type)
{
	int	commas;
	int	indx;

	commas = 0;
	indx = 0;
	while (line[indx] && (ft_isdigit(line[indx]) || line[indx] == '.' 
		|| line[indx] == ',') && !ft_isspace(line[indx]))
	{
		if (line[indx] == ',' && (!line[indx + 1] || line[indx + 1] == ','
				|| !ft_isdigit(line[indx + 1])))
			return (1);
		if (line[indx++] == ',')
			commas++;
	}
	return (eval_vec_type(commas, type));
}
