#ifndef _BOFS_DRIVE_H
#define _BOFS_DRIVE_H

#include <stdint.h>

/*drive*/

#define BOFS_MAX_DRIVE_NR 26

#define BOFS_HARDDISK_DRIVE 	'c'
#define BOFS_RAMDISK_DRIVE 		'x'

/*
drive struct, name is using for drive (a~z(A~Z)).
dev_id is using for this drive link to which device. 
*/
struct bofs_drive
{
	char name[2];	/*drive name*/
	int dev_id;		/*device id*/
};

void bofs_init_drive();
int bofs_select_drive(char drive);
char bofs_install_drive(char start ,int dev_id);
int bofs_uninstall_drive(char drive);

int bofs_list_drive();

#endif

