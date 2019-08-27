#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


// pecah string per kata
void split_words(char *string, char **words)
{
    int i;
    words[0] = strtok(string, " \n");
    for (i = 0; words[i]; i++)
        words[i+1] = strtok(NULL, " \n");
}

int main()
{
    char cmd[80];                           //  string perintah
    char *args[20];                         //  argumen string perintah
    pid_t pid;

    while (1)
    {
        //  cetak prompt "$ "
        printf("\n$");

        //  baca string perintah
        fgets(cmd,80,stdin);

        //  pecah string perintah per argumen
        split_words(cmd,args);

        //  jika perintah = "exit"
         if(strcmp(args[0], "exit") == 0) {
			break;		//      break
		}
        

        //  jika perintah = "cd"
        else if(strcmp(args[0], "cd") == 0) {
			chdir(args[1]);		//      ganti direktori
			continue;			//      continue
		}
        
        
		pid = fork();				 //  buat proses child:
		if(pid == 0) {
			execvp(args[0],args);	//      exec string perintah
			puts("Error");			//      cetak pesan error
			return -1;				//      keluar dengan kode -1
		}
        

        //  tunggu child selesai
        if (pid>0) wait(NULL);
    }

    return 0;
}
