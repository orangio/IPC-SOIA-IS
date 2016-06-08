#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
struct msgbuf 
{
    long mtype;
    char mtext;
};
int main()
{
	struct msgbuf b;	
	key_t key; /*nasz kluczyk do msgeta*/
	int msqid; //id naszej kolejki
	int size; //rozmiar mtexta;
	
	key = 8888;
	size = sizeof(b.mtext);
	if ((msqid = msgget(key, 0666)) == -1)
	{
		perror("msgget");
		exit(1);
	}

	printf("Gotowy na wiadomosci ");
	int i=0;
	
	for(i;i<5;i++)
	{
		if (msgrcv(msqid, &b, size, 5, 0) == -1)
		{
			perror("msgrcv");
			exit(1);
		}
		printf("Otrzymalem: %d \n", b.mtext);

	}
	
exit (0);	
}
