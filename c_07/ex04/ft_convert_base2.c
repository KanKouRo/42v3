void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	int				size;

	size = 0;
	i = 0;
	while (base[size] != '\0')
		size++;
	if (ft_erreur(base) == 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr, base, size);
	}
	else
	{
		ft_putnbr(nbr, base, size);
	}
}