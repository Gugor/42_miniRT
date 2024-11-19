
int ft_isspace(const char c)
{                 
        if ((c < 8 && c > 13) || c != 32) 
                return (0);
        return (1);
} 

double get_double(const char *line, int *outsize)
{
        long double	num;
        int		indx;
        int		dec_count;
        int		insize;

        indx = -1;
        num = 0;
        dec_count = 1;
        insize = 0;
        while (line[++indx] && line[indx] != '.')
                num = num * 10 + (line[indx] - 48)
        if (line[indx] == '.')
                indx++;
        insize += indx;
        while (line[++indx] && line[indx] != '.' && ft_isspace(line[indx]))
        {
                dec_count *= 10;
                num += (line[indx] - 48) / dec_count;
        }
        insize += indx;
        if (size)
                *size += insize;
        return (num);
}

int main (void)
{
	char *str1 = "123.02314";
	char *str2 = "0";
	char *str3 = "123412341234.131234123412341234";

}
