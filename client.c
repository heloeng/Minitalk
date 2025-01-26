//incluir cabeçalho

#include "minitalk.h"

//pode enviar proximo bit
int g_can_send_next_bit = 0;

//a função é um handler para respostas.
//manipulador de respostas
void	response_handler(int signal)
{
	(void)signal;
	g_can_send_next_bit = 1;
}
//enviar bits por meio de sinais
void	send_bits_via_signals(int pid, char *str)
{
	static int	bit;

	while (*str != '\0')
	{
		bit = 8;
		while (bit--)
		{
			g_can_send_next_bit = 0;
			if ((*str >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (g_can_send_next_bit == 0);
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		g_can_send_next_bit = 0;
		kill(pid, SIGUSR1);
		while (g_can_send_next_bit == 0)
			;
	}
}


int	main(int argc, char **argv)
{
	int	pid; 

	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [STRING]\n", argv[0]);
		return (1);
	}

	pid = ft_atoi(argv[1]);

	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}


	if (kill(pid, 0) == -1)
	{
		ft_printf("No process with PID %d found.\n", pid);
		return 1;
    }

	signal(SIGUSR1, response_handler);
	signal(SIGUSR2, response_handler);
	send_bits_via_signals(pid, argv[2]);
	return (0);
}