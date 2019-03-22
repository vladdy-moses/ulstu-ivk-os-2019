#include <unistd.h> 

int main(int argc, char *argv[], char *envp[]) {
    execv("/bin/printenv", argv);

    return 0;
}
