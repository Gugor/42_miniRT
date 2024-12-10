
#include "parsing.h"
#include "libft.h"

/**
 * @brief Another silly function to contempt norminette.
 */
void update_line_offset(char **line, int *offset)
{
	*line += *offset;
	*offset = 0;
}

/**
 * @brief It checks if the current char is '-' and returns a value to be used
 * with a neg variable. This functios is just a silly fucntion to skip 
 * norminette 25 lines limit.
 */
int	is_chneg(const char *line, int *offset)
{
	if (line[0] == '-')
	{
		(*offset)++;
		return (-1);
	}
	return (1);
}

/**
 * @brief It evaluates if the number of commas passed correspond with the vector type specified. This
 * fucntion is multipourpouse, you can check VEC2 and VEC3 formats.
 * @param commas `{int}` the number of commas the format has.
 * @param type ´{t_vec_type}´ the vector type VEC2 or VEC3 types. 
 */
static int	eval_vec_type(int commas, t_vec_type type)
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
	/*
	while (line[indx] && (ft_isdigit(line[indx]) || line[indx] == '.' 
		|| line[indx] == ',' || line[indx] == '-') && !ft_isspace(line[indx]))
	{
		if (line[indx] == ',' && (!line[indx + 1] || line[indx + 1] == ','
				|| (!ft_isdigit(line[indx + 1] && line[indx] != '-'))))
			return (1);
		if (line[indx++] == ',')
			commas++;
	}
	*/
	while (line[indx] && line[indx] != 32)
		if (line[indx++] == ',')
			commas++;
	return (eval_vec_type(commas, type));
}
