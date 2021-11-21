#include <stdio.h>
#include <getopt.h>
#include <string.h>

void cycle(int opts,int index, bool help, bool version, bool list, int argc, char **argv) {
    const char *sOptions = "hvl:";
    static struct option lOptions[] = {
            {"help",    no_argument,       0, 'h'},
            {"version", no_argument,       0, 'v'},
            {"l",       required_argument, 0, 'l'},
            {0,0,0,0}

    };
    const char *hOption = "Program options:\n"
                          "-h or --help\n"
                          "-v or --version\n"
                          "-m[<val1>,...]";
    while ((opts = getopt_long(argc, argv, sOptions, lOptions, &index)) != -1) {
        switch (opts) {
            case 'h': {
                if (!help) {
                    help = true;
                    printf("%s\n", hOption);
                }
                break;
            }

            case 'v': {
                if (!version) {
                    version = true;
                    printf("Version\n");
                }
                break;
            }
            case 'l': {
                if (!list) {
                    char *args;
                    printf("Option list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    list = true;
                }
                break;
            }
            default: {
                printf("No such option!\n");
                
                
            }
        }
        
    }
    
}

int main(int argc, char **argv) {

    bool help, version, list = false;

    int index, opts;
    cycle(opts,index, help, version,  list,  argc,  argv);
    
    return 0;
}


