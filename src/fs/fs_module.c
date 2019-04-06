/*
File:		fs/fs.c
Contains:	file system module
Auther:		Hu Zicheng
Time:		2019/4/2
Copyright:	(C) 2018-2019 by BookOS developers. All rights reserved.
E-mail:		2323168280@qq.com
*/
#include <sys/fs.h>
#include <sys/console.h>
#include <sys/device.h>

#include <string.h>

#include <bofs/bofs.h>

struct fs_module fs;

void init_fs_module()
{
	fs_module_build(FS_MODULE_NAME);
	
	fs_module_output(FS_MODULE_NAME);
	
}

void fs_module_output(char *name)
{
	/*set output*/
	if(!strcmp(name, FS_MODULE_NAME_BOFS)){
		
		/*dir*/
		fs.mkdir = bofs_make_dir;
		fs.rmdir = bofs_remove_dir;
		fs.opendir = bofs_open_dir;
		fs.readdir = bofs_read_dir;
		fs.rewinddir = bofs_rewind_dir;
		fs.closedir = bofs_close_dir;
		fs.getcwd = bofs_getcwd;
		fs.chdir = bofs_chdir;
		fs.lsdir = bofs_list_dir;
		fs.rename = bofs_reset_name;
		
		/*file*/
		fs.open = bofs_open;
		fs.close = bofs_close;
		fs.unlink = bofs_unlink;
		fs.write = bofs_write;
		fs.read = bofs_read;
		fs.lseek = bofs_lseek;
		fs.stat = bofs_stat;
		fs.access = bofs_access;
		fs.setmod = bofs_set_mode;
		fs.getmod = bofs_get_mode;
		fs.copy = bofs_copy_file;
		fs.move = bofs_move_file;
		
		fs.path_to_name = bofs_path_to_name;
		
		fs.lsdisk = bofs_list_drive;
		
	}
}

void fs_module_build(char *name)
{
	/*set build info*/
	memset(fs.name, 0,FS_MODULE_NAME_LEN);
	strcpy(fs.name, name);
	
	
	/*call build*/
	fs.build = init_bofs;
	fs.build();
	
}