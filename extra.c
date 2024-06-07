
/* char	*ft_strdup(char *s, int size)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((ft_zerolen(s, -2) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
} */

/* char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (i < (ft_zerolen(s, -2) + 1))
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
} */

/* int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
 */