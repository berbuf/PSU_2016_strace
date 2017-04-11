/*
** strace.h for strace in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Apr 10 18:05:35 2017 David Zeng
** Last update Mon Apr 10 18:05:35 2017 David Zeng
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <stdio.h>
# include <stdlib.h>
# include <sys/ptrace.h>
# include <sys/reg.h>
# include <stdbool.h>
# include <unistd.h>
# include <getopt.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/user.h>
# include <signal.h>

# define SYSCALL 0x050f

typedef struct	s_param
{
  bool		s;
  bool		p;
  pid_t		pid;
  int		argc;
  char		**argv;
}		t_param;

t_param		parse_args(int argc, char *argv[]);
void		trace_syscall(pid_t pid);
pid_t		fork_process(char *argv[]);
pid_t		trace_process(pid_t pid);

#endif /* !STRACE_H_ */
