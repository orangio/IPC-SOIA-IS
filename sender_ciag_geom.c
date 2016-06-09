#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct msgbuf 
{
    long mtype;
    char mtext;
};

int main()
{
	struct msgbuf a;	
	key_t key; /*nasz kluczyk do msgeta*/
	int msgflg = IPC_CREAT | 0666;
	int msqid; //id naszej kolejki
	int size; //rozmiar mtexta;
	char c;

	key = 8888;
	size = sizeof(a.mtext);
	if((msqid = msgget(key, msgflg )) == -1)
        {
	 perror("msgget");
	 exit(1);
	}

	int i=0;
	int pw=2;
	a.mtype=5;
	a.mtext =pw;

	for(;;)
	{
		int j=i;
		for(j;j>0;j--)
		{
			a.mtext=a.mtext*2;	
		}
		a.mtype=5;
		if (msgsnd(msqid, &a, size, 0) == -1)
		{
			perror("msgsnd");
			exit(1);
		}
		i++;
		a.mtext=pw;
		//else
		//printf("Message: %d wyslano ", a.mtext);
		//printf("Dzialam \n");
	}
	
exit (0);	
}
