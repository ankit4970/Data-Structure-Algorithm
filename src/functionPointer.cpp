//
// Created by ankit on 1/4/2018.
//
#include "../includes/common.h"

#if 0

struct file_operations {
    void (*read)();         // Callbacks
    void (*write)();

    void (*open)();
};

struct miscdevice {
    int minor;
    const char *name;
    const struct file_operations *fops;
    const char *nodename;
};

void my_open() {
    cout << "Open function called" << endl;
}

void my_read() {
    cout << "Read function called" << endl;
}

void my_write() {
    cout << "Write function called" << endl;
}

static const struct file_operations my_fops = {
    .open    = &my_open,
    .read    = &my_read,
    .write    = &my_write,
};

static struct miscdevice my_device = {
    .name = "mydriver",
    .fops = &my_fops,
};

void fucnPointerMain() {
    cout << "Function pointer entry" << endl;

    my_device.fops->open();
    my_device.fops->read();
}

#endif