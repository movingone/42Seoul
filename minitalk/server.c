/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwole <dongwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:01:25 by dongwole          #+#    #+#             */
/*   Updated: 2023/10/08 22:44:15 by dongwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 함수 프로토타입
void	signal_handler(int signo);

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	// 시그널 핸들러 등록
	signal(SIGUSR1, signal_handler);
	while (1)
	{
		pause(); // 클라이언트 메시지를 기다림
	}
	return (0);
}

// 시그널 핸들러 함수
void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		printf("Server received a message from client.\n");
		printf("Message: Hello, World!\n");
		// 클라이언트에 응답 보내기
		kill(getppid(), SIGUSR1);
	}
}
