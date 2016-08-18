#include<stdio.h>  
#include<string.h>  
#include<sys/types.h>  
  #include <stdlib.h>
#include <iostream>  
  
#pragma pack(2)  
  
 
#define F_PATH "/home/tanlin/Imageprocessing/cmake/dd/22.bmp"

using namespace std;
typedef struct BITMAPFILEHEADER  
{   
    u_int16_t bfType;   
    u_int32_t bfSize;   
    u_int16_t bfReserved1;   
    u_int16_t bfReserved2;   
    u_int32_t bfOffBits;   
}BITMAPFILEHEADER;   
  
typedef struct BITMAPINFOHEADER  
{   
    u_int32_t biSize;   
    u_int32_t biWidth;   
    u_int32_t biHeight;   
    u_int16_t biPlanes;   
    u_int16_t biBitCount;   
    u_int32_t biCompression;   
    u_int32_t biSizeImage;   
    u_int32_t biXPelsPerMeter;   
    u_int32_t biYPelsPerMeter;   
    u_int32_t biClrUsed;   
    u_int32_t biClrImportant;   
}BITMAPINFODEADER; 
typedef unsigned char       BYTE;
typedef unsigned long       DWORD; 
void threshold(BYTE *image_in, BYTE *image_out, int xsize, int ysize, int thresh,int mode)
{
    int i,j;
    for (j=0;j<ysize;j++)
    {
        for (i=0;i<xsize;i++)
        {
            switch (mode)
            {
            case 2:
                if(*(image_in+j*xsize+i)<=thresh)
                    *(image_out+j*xsize+i)=1;
                else
                    *(image_out+j*xsize+i)=0;
                break;
            default:
                if(*(image_in+j*xsize+i)>=thresh)
                    *(image_out+j*xsize+i)=1;
                else
                    *(image_out+j*xsize+i)=0;
                break;
            }
        }
    }
}

int main()
  {
    BITMAPFILEHEADER fileheader;
    BITMAPINFODEADER info;
 
    FILE *fp=fopen(F_PATH ,"r");
    cout << "image Info:Height:" << info.biWidth << " Width:" << info.biHeight << endl; 

    if (NULL==fp)
        return  0;
 
    //文件头
    fread(&fileheader, sizeof(BITMAPFILEHEADER), 1, fp);
    if (fileheader.bfType!=0x4D42)//不是BMP图片
    {
        fclose(fp);
        return 0;
    }
    cout << "image Info:Height:" << info.biWidth << " Width:" << info.biHeight << endl; 
    //信息头
    fread(&info, sizeof(BITMAPINFOHEADER), 1, fp);
    cout << "info.biBitCount" << info.biBitCount<< endl;
    //位图宽度和高度
    long height=info.biWidth;
    long wide=info.biHeight;
 
    //宽字节
    int widthByte=(info.biWidth * info.biBitCount + 31)/32 *4 ;
 
    DWORD size;
    if (info.biClrUsed!=0)
        size=info.biSizeImage;//带颜色表
    else
        size=height * widthByte;        //不带颜色表
 
    BYTE* bmpData = (BYTE*)malloc(size);
    if (bmpData==NULL)
        return 0 ;
    fseek(fp, fileheader.bfOffBits,0);
    fread(bmpData, size, 1 ,fp);
    fclose(fp);
        
        BYTE *threshold_temp=(BYTE*)malloc(size);
       // threshold(bmpData,threshold_temp,wide,height,120,1);             //二值化处理
 
    FILE *fp4; 
    fp4=fopen("k=1.bmp","w");
    fwrite(&fileheader, sizeof(fileheader), 1, fp4);
    fwrite(&info, sizeof(BITMAPINFOHEADER), 1,fp4);
    fwrite(threshold_temp, size, 1, fp4);
    fclose(fp4);
}



