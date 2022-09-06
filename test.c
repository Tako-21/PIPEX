#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[],char *arge[])
{
	char	*cmd[] = { "ls", "-l", (char *)0 };
	char *env[] = { "HOME=/usr/home",
					"LOGNAME=home", (char *)0 };
	execve("/bin/ls", cmd, arge);
}