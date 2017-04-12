/*
** trace_syscall.c for trace_syscall in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Apr 11 17:03:01 2017 David Zeng
** Last update Tue Apr 11 17:03:01 2017 David Zeng
*/

#include "strace.h"

static void	print_syscall(t_proc *proc)
{
  fprintf(stderr, "syscall %s", get_syscall_name(proc->regs.rax));
}

// TODO GET PARAM

static void	print_ret(t_proc *proc)
{
  ptrace(PTRACE_SINGLESTEP, proc->pid, NULL, NULL);
  waitpid(proc->pid, &proc->status, 0);
  ptrace(PTRACE_GETREGS, proc->pid, NULL, &proc->regs);
  // TODO check void ret
  fprintf(stderr, " = 0x%llx\n", proc->regs.rax);
}

void		trace_syscall(pid_t pid, t_param param)
{
  t_proc	proc;

  proc.pid = pid;
  proc.param = param;
  while (waitpid(pid, &proc.status, 0) && !WIFEXITED(proc.status))
    {
      ptrace(PTRACE_GETREGS, pid, NULL, &proc.regs);
      if ((short)ptrace(PTRACE_PEEKTEXT, pid, proc.regs.rip, NULL) == SYSCALL)
	{
	  print_syscall(&proc);
	  print_ret(&proc);
	}
      ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    }
}
