/*
* Copyright (c) 2022 Chaturya
*       chaturyasral@gmail.com
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <getopt.h>

#include "localhead.h"

void startup() {
    
    // Startup the services.
    
    if (setegid(2000) != 0) {
        _terminate(11, process_errno(errno));
    };

    if (seteuid(2000) != 0) {
        _terminate(12, process_errno(errno));
    };
    
};

void signal_handler(int SIGTYPE) {
    
    if (SIGTYPE == SIGINT) {
        if (lock != 0) fprintf(stderr, "Flasher: Unable to end process, forced end could cause trouble.\nPlease wait for module to be flashed.\n");
        else exit(130);
    } else if (SIGTYPE == SIGTERM) {
        if (lock != 0)
        fprintf(stderr, "Flasher: Module flashing has ended by force.\n");
        fprintf(stdout, "*Process Ended*\n");
        _exit(1);
    } else {
        signal(SIGTYPE, SIG_DFL);
    };
    
};

void module_prop(moduleprops localmodule) {
    
    
    
};

void flash_module(flasher module) {
    
    std::cout << CLEAR;
    
    std::cout << "*Magisk Module Flasher*\n* Initalising Flash...\n";
    
};

void build_sysmod(sysmod_config sysmod) {
    
    
    
};

void create_module(module_config config) {
    
    
    
};

int main(int argc, char *argv[]) {
    
    /* Main */
    
    if (getuid() != 0) { // run as root only
        std::cout << "Session restarting as root..." << std::endl;
        std::string restart_as_su = "";
        restart_as_su = "su -c";
        for (int i = 0; i < argc; i++)
            restart_as_su = restart_as_su + " " + argv[i];
        system(restart_as_su.c_str());
    };
    
    startup();
    
    fprintf(stdout, "My id %u", geteuid());
    return 0;
    
};

int usage(int status) {
    
    fprintf(stdout, "Magisk Module Manager\n\
    By Csral - V_10051\n\
    \nBuild And Manage Modules For Magisk\nOptions\n\
    \tnull\n");
    
    _exit(status);
    
};

std::string process_errno(int number) {
    
    /* Process Error Codes */
    
    std::string result = "";
    
    switch(number) {
        
        case 1:
            result = "Operation not permitted";
            break;
        case 2:
            result = "No such file or directory";
            break;
        case 3:
            result = "No such process";
            break;
        case 4:
            result = "Interrupted system call";
            break;
        case 5:
            result = "I/O error";
            break;
        case 6:
            result = "No such device or address";
            break;
        case 7:
            result = "Argument list too long";
            break;
        case 8:
            result = "Exec format error";
            break;
        case 9:
            result = "Bad file number";
            break;
        case 10:
            result = "No child processes";
            break;
        case 11:
            result = "Try again";
            break;
        case 12:
            result = "Out of memory";
            break;
        case 13:
            result = "Permission denied";
            break;
        
    };
    
    return result;
    
}

int _end(int end_code) {
    
    /* End */
    
    exit(end_code);
    
};

int _terminate(int error_code, std::string msg) {
    
    /* Terminate */
    
    switch(error_code) {
        
        case 11:
            fprintf(stderr, "Module_Builder_GROUP: Unable to set permission level to a lower: %s\n", msg.c_str());
            break;
        case 12:
            fprintf(stderr, "Module_Builder_USER: Unable to set permission level to a lower: %s\n", msg.c_str());
            break;
        
    };
    
    _exit(1);
    
};