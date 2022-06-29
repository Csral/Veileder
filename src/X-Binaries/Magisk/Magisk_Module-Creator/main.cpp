/*
* Copyright (c) 2022 Chaturya
*       chaturyasral@gmail.com
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fstream>
#include <signal.h>
#include <sys/types.h>
#include <getopt.h>

#include "localhead.h"

std::string path_file(std::string location) {
    ssize_t status = readlink(location.c_str(), buffer, sizeof(buffer)-1);

    if (status != -1) {
        buffer[status] = '\0';
        return std::string(buffer);
    };
    
    return std::string("ERROR");
};

void startup(int argumentc, char *argguments[]) {
    
    // Startup the services.
    
    std::ofstream logfile;

    if (getuid() != 0) {
        std::string file = path_file("/proc/self/exe");

        if (file == "ERROR") {
            fprintf(stderr, "Unable to get script location, Run as root!\n");
            exit(1);
        };

        std::string cmd = "su -c " + file;

        system(cmd.c_str());
    };

    chdir("/data/adb/");

    std::__fs::filesystem::remove("Veileder/.logs/startup.log");

    logfile.open("Veileder/.logs/startup.log");

    logfile << "*Startup Log Initalized*\n";

    setenv("HOME", "/data/adb/", 1);
    setenv("TMPDIR", "/data/adb/tmp", 0);
    setenv("MAGISKEXEC", "/data/adb/magisk/", 0);
    setenv("Version", "v1.0", 1);

    if (mkdir("/data/adb/tmp",775) == -1) {
        logfile << "[mkdir]: Startup folder creation error, unable to create tmp dir";
    };

    if (setegid(2000) != 0) {
        fprintf(stderr, "Magisk Module Manager: seteuid : Unable to change user to shell\n");
        _exit(1);
    };

    if (seteuid(2000) != 0) {
        fprintf(stderr, "Magisk Module Manager: setegid : Unable to group current user to shell\n");
        _exit(1);
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
    
    startup(argc, argv);
    
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