#ifndef _FS_MODULE_H
#define _FS_MODULE_H

#include <types.h>
#include <stdint.h>

#include <bofs/bofs.h>

/*
<<file system module>>
we may have many file system, so weset module to manage fs.

[fs]
	fs_build, fs_format
[dir]
	mkdir, rmdir, opendir, closedir, readdir, rewinddir, getcwd, chdir

[file]
	open, close, read, write, unlink, lseek, stat, access, move, copy
*/


/*select a fs*/
#define _FS_MODULE_BOFS

/*fs name*/
#define FS_MODULE_NAME_BOFS "bofs"

/*bofs*/
#ifdef _FS_MODULE_BOFS
	/*name*/
	#define FS_MODULE_NAME	 	FS_MODULE_NAME_BOFS
	
	/*struct */
	#define dir 			bofs_dir
	#define dir_entry 		bofs_dir_entry
	#define stat 			bofs_stat
	#define file_descriptor bofs_file_descriptor
	
	/*file */
	#define O_RDONLY 		BOFS_O_RDONLY
	#define O_WRONLY 		BOFS_O_WRONLY
	#define O_RDWR 			BOFS_O_RDWR
	#define O_CREAT 		BOFS_O_CREAT
	#define O_TRUNC 		BOFS_O_TRUNC
	#define O_APPEDN 		BOFS_O_APPEDN
	#define O_EXEC 			BOFS_O_EXEC

	#define SEEK_SET 		BOFS_SEEK_SET
	#define SEEK_CUR 		BOFS_SEEK_SET
	#define SEEK_END 		BOFS_SEEK_END

	#define F_OK 			BOFS_F_OK
	#define X_OK 			BOFS_X_OK
	#define R_OK 			BOFS_R_OK
	#define W_OK 			BOFS_W_OK
	/*dir */
	#define MAX_PATH_NAME_LEN 	BOFS_PATH_LEN
	#define MAX_FILE_NAME_LEN 	BOFS_NAME_LEN
	
	/*inode*/
	#define IMODE_U 		BOFS_IMODE_U
	#define IMODE_R 		BOFS_IMODE_R
	#define IMODE_W 		BOFS_IMODE_W
	#define IMODE_X 		BOFS_IMODE_X
	#define IMODE_F 		BOFS_IMODE_F
	#define IMODE_D 		BOFS_IMODE_D

#endif

/*module name len*/
#define FS_MODULE_NAME_LEN 12


struct fs_module
{
	/*inside*/
	/*module*/
	char name[FS_MODULE_NAME_LEN];
	
	/*fs*/
	void (*build)(void);
	
	/*output*/
	/*dir*/
	int (*mkdir)(const char *);
	int (*rmdir)(const char *);
	struct dir *(*opendir)(const char *);
	struct dir_entry *(*readdir)(struct dir *dir);
	void (*rewinddir)(struct dir *dir);
	void (*closedir)(struct dir* dir);
	int (*getcwd)(char *, uint32 );
	int (*chdir)(const char *);
	void (*lsdir)(const char *, int );
	int (*rename)(const char *, char *);
	
	/*file*/
	int (*open)(const char *, uint32 );
	int (*close)(int );
	int (*unlink)(const char *);
	int (*write)(int , void* , uint32 );
	int (*read)(int , void* , uint32 );
	int (*lseek)(int , int , uint8 );
	int (*stat)(const char *, struct stat *);
	int (*access)(const char *, int );
	int (*setmod)(const char* , int );
	int (*getmod)(const char* );
	int (*copy)(const char *, const char *);
	int (*move)(const char *, const char *);
	
	/*help*/
	int (*path_to_name)(const char *, char *);
	
	int (*lsdisk)(void);
	
};

extern struct fs_module fs;

void init_fs_module();

void fs_module_input(char *name);
void fs_module_build(char *name);
void fs_module_output(char *name);

#endif

