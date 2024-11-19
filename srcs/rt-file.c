
#include "scene.h"
#include "error-handler.h"
#include "file.h"

/**
* @brief It opens the file rt and throws an error otherwise.
*/
int open_rt(const char *rt_path)
{
        int     fd; 

        if((fd = open(rt_path, O_RDONLY)) == -1)    
        {
                err_rt_file_not_open(errno);
                exit(ERR_FILE_NO_OPEN);
        }
	return (fd);
}

