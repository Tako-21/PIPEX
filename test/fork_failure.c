/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:10:54 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/10/20 16:57:54 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    int pid,status,i;
    static int arr1[1000000000];
    memset(arr1,0,sizeof(arr1));
    pid=fork();
    switch(pid) {
    case -1:
        perror("parent: échec lors du fork\n");
        return EXIT_FAILURE;
    case 0:
        for(i=0;i<100;i++){
            memset(arr1+i*10000000,0,40000000);
            // sleep(1);
            puts("mem");
        }
        break;
    default:
        printf("retour fork : %d\n", pid);
        wait(&status);
        break;
    }
    return EXIT_SUCCESS;
}