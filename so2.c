/*
#include <stdio.h>
#include <unistd.h>
int main(){
	fork();
	fork();
	puts("hello");
	return 0;
}


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	pid_t pid;// process id untuk menyimpan return value
	pid = fork(); // buat ngecek return value nya
	if(pid == 0)
		puts("child");
	else
		puts("parent");
	return 0;
}
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	pid_t pid;
	char *msg;
	int n;
	pid = fork();
	if (pid == 0) {
		msg = "child";
		n = 8;
	}
	
	else {
		msg = "parent";
		n = 4;
	}
	
	while (n--) {
		puts(msg);
		sleep(1);
	}
	if( pid >0 ) //parent menunggu child hingga selesai
		wait(NULL);
		
	return 0;
}


