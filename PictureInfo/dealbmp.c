#include <stdio.h>
#include <stddef.h>

//位图文件头
typedef struct tagBITMAPFILE_HEADER{
	unsigned short bfType;
	unsigned int bfSize;
	
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits;
}BITMAPFILE_HEADER;

typedef struct tagBITMAPINFO_HEADER{
	
	unsigned int iSize;
	int iWidth;
	int iHeight;
	
	unsigned short iPlanes;
	unsigned short iBitCount;
	unsigned int iCompression;
	unsigned int iSizeImage;
	
	int iXPelsPerMeter;
	int iYPelsPerMeter;
	unsigned int iClrUsed;
	
	unsigned int iClrImportant;
}BITMAPINFO_HEADER;

typedef struct tagRGBQUAD{
	char rgbBlue;
	char rgbGreen;
	char rgbRed;
	
	char rgbReserved;
}RGB_QUAD;

void openbmp()
{
	
}

int main()
{
	FILE *fd;
	BITMAPFILE_HEADER bfh;
	BITMAPINFO_HEADER bih;
	
	// 1,open bmp file
	fd = fopen("DSC.bmp", "rw");
	// 2,print bmp info
	fseek(fd, 0, 0);
	fread(&bfh.bfType, sizeof(bfh.bfType), 1, fd);
	fseek(fd, sizeof(bfh.bfType), 0);
	fread(&bfh.bfSize, sizeof(bfh)-4, 1, fd);
	fseek(fd, sizeof(bfh)-2, 0);
	fread(&bih, sizeof(bih), 1, fd);
	
	printf("FILE_Header size:%ld\n", sizeof(bfh));
	printf("INFO_Header size:%ld\n", sizeof(bih));
	printf("bfSize offset : %ld\n", offsetof(BITMAPFILE_HEADER, bfSize));
	printf("bfType: %x\n", bfh.bfType);
	printf("bfSize: %x\n", bfh.bfSize);
	printf("bfReserved1: %x\n", bfh.bfReserved1);
	printf("bfReserved2: %x\n", bfh.bfReserved2);
	printf("bfOffBits: %d\n", bfh.bfOffBits);
	
	printf("iSize:%4d------------[%x]\n", bih.iSize, bih.iSize);
	printf("iWidth:%4d-----------[%x]\n", bih.iWidth, bih.iWidth);
	printf("iHeight:%4d----------[%x]\n", bih.iHeight, bih.iHeight);
	printf("iPlanes:%4d----------[%x]\n", bih.iPlanes, bih.iPlanes);
	printf("iBitCount:%4d--------[%x]\n", bih.iBitCount, bih.iBitCount);
	printf("iCompression:%4d-----[%x]\n", bih.iCompression, bih.iCompression);
	printf("iSizeImage:%4d---[%x]\n", bih.iSizeImage, bih.iSizeImage);
	printf("iXPelsPerMeter:%4d--[%x]\n", bih.iXPelsPerMeter, bih.iXPelsPerMeter);
	printf("iYPelsPerMeter:%4d--[%x]\n", bih.iYPelsPerMeter, bih.iYPelsPerMeter);
	printf("iClrUsed:%4d---------[%x]\n", bih.iClrUsed, bih.iClrUsed);
	printf("iClrImportant:%4d----[%x]\n", bih.iClrImportant, bih.iClrImportant);
	
	return 0;
}