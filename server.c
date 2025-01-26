//incluir cabeçalho

#include "minitalk.h"

//store_or_finish_char - armazenar ou terminar o char
int	store_or_finish_char(char **str, char *c, int *bit_c, siginfo_t *info)
{
	char	*temp;

	if (*c == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*c = 0;
		*bit_c = 0;
		*str = NULL;
		kill(info->si_pid, SIGUSR2);
		return (0);
	}
	temp = ft_strjoin(*str, c);
	free(*str);
	*str = temp;
	*c = 0;
	*bit_c = 0;
	return (1);
}

//receber_bits_por_sinais_e_formar_um_caracter
void	receive_bits_from_signals_build_char(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static char		*str = NULL;
	static int		bit_count = 0;

	(void)context;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (str == NULL)
		str = ft_strdup("");
	bit_count++;
	if (bit_count == 8)
	{
		if (store_or_finish_char(&str, &c, &bit_count, info) == 0)
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = receive_bits_from_signals_build_char;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}