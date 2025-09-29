#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define DEVICE_FILENAME "/dev/ledkey"

int main(int argc, char * argv[])
{
	int dev;
	char buff;
	int ret;
	char key;
	unsigned long key_data;
	unsigned long key_data_old=0;
	int i;
	if(argc<2)
	{
		printf("usage : %s ledval[0x00]~[0xff]\n",argv[0]);
		return 1;
	}
	
	key = strtoul(argv[1],NULL,16);

	if(access("dev/ledkey",F_OK) != 0)
    {
        int ret = mknod("/dev/ledkey",S_IRWXU | S_IRWXG | S_IFCHR, (230 << 8) | 0);
        if(ret<0)
            perror("mknod()");
    }


	printf("1) device file open\n");

	dev = open(DEVICE_FILENAME, O_RDWR | O_NDELAY);
	if(dev<0)
	{
		perror("open");
		return 2;
	}
	
/*	ret = read(dev,&buff,sizeof(buff));
	if(ret <0)	
	{
		perror("read");
		return 3;
	}
	printf("ret = %08X, key = %#04x\n",ret,buff);
*/	

	ret = write(dev,&key,sizeof(key));
	if(ret<0)
	{
		perror("wrtie");
		return 3;
	}

	printf("ret = %08X\n",ret);
	printf("start\n");

	do {
		ret = read(dev,&buff,sizeof(buff));
		if(ret<0)
		{
			perror("write");
			return 4;
		}
        key_data = buff;
        if(key_data != key_data_old)
        {
            if(key_data)
            {
                write(dev,&buff,sizeof(buff));

                puts("0:1:2:3:4:5:6:7\n");
                for(i=0;i<8;i++)
                {
                    if(key_data & (0x01 << i))
                        putchar('O');
                    else
                        putchar('X');
                    if(i != 7 )
                        putchar(':');
                    else
                        putchar('\n');
                }
                putchar('\n');

                if(key_data == 0x80)
                    break;
            }
            key_data_old = key_data;
        }
    }while(1);

	ret = close(dev);
	return 0;
}
