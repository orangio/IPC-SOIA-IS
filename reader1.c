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
	char tab[5];
	int i=0;
	int z=1;

	key = 8888;
	size = sizeof(b.mtext);
	if ((msqid = msgget(key, 0666)) == -1)
	{
		perror("msgget");
		exit(1);
	}

	printf("Gotowy na wiadomosci ");

	for(;;)
	{
		if (msgrcv(msqid, &b, size, 5, 0) == -1)
		{
			perror("msgrcv");
			exit(1);
		}

		//printf(" %d ",b.mtext);

		if(i==0) tab[0]=b.mtext;
		else
		{
			if(tab[i-1]==b.mtext)
			{
				tab[i]=b.mtext;
				z++;
			}
			else
			{
				tab[0]=b.mtext;
				z=1;
				i=0;
			}
		}	if(z==5)
			{		
				printf("A oto moje bajty %d %d %d %d %d ",tab[0], tab[1], tab[2], tab[3], tab[4]);
				 exit(0);
			}
		i++;
	}
	
exit (0);	
}
