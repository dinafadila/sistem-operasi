#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t child = fork();
    if (child == 0) {
        while (1) {
            puts("child");
            sleep(1);
        }
    } 
    else {
        sleep(4);				//dia selalu ngikutin yang atasnya
        kill(child, SIGSTOP);	//agar dia berhenti sementara
        sleep(3);				//berhentinya selama 3 detik
        kill(child, SIGCONT);	//agar dia continue
        sleep(2);				//continue selama dua detik
        kill(child, SIGTERM);   // terminate
    }
    return 0;
}
