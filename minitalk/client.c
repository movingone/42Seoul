/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwole <dongwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:47:50 by dongwole          #+#    #+#             */
/*   Updated: 2023/10/08 22:44:13 by dongwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 함수 프로토타입
void	signal_handler(int signo);

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;

	if (argc != 3)
	{
		ft_printf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	// 시그널 핸들러 등록
	signal(SIGUSR1, signal_handler);
	// 서버에 메시지 보내기
	kill(server_pid, SIGUSR1);
	pause(); // 서버의 응답을 기다림
	printf("Client sent message to server: %s\n", message);
	return (0);
}

// 시그널 핸들러 함수
void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		printf("Client received acknowledgment from server.\n");
		exit(0);
	}
}
