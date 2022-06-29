#define CLEAR "\033[H\033[2J\033[3J"
#define MODULESCAN 1

#define MODDIR "/data/adb/modules/"
#define TMPDIR "/dev/root"
#define TMPDIRNONROOT "/data/tmp"

int lock = 0;
int read_config = 0;

class path {

    public:
    int include_subdirs;
    int copydir;
    int inherit_permissions;
    int inherit_users;
    std::string location;

};

class sysmod_config {

    public:
    int dir_system;
    int dir_vendor;
    int dir_bootimg;
    int dir_rootfs;
    path dir_extra; // folder with mods

};

class module_config {

    public:
    int modify_system;
    int modify_vendor;
    int patch_bootimg;
    int modify_rootfs;
    int has_postfs;
    int has_service;
    int make_props;
    int make_cprop; // flasher class in prop
    int make_zip;
    int enable_bootloopscan;
    int copy_inherit_permissions;
    int copy_inherit_users;
    path include_dir; // extra files

};

class flasher {

    public:
    int has_cprop;
    char flash_point;
    std::string path;

};

class moduleprops {

    public:
    int versionCode;
    std::string id;
    std::string name;
    std::string description;
    std::string version;

};

int usage(int status);
int _terminate(int error_code, std::string msg);
int _end(int end_code);
std::string process_errno(int number);