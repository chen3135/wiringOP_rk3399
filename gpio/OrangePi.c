#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "OrangePi.h"
#include <wiringPi.h>

#ifdef CONFIG_ORANGEPI_PC2
int physToWpi[64] =
{
    -1,        // 0
    -1,  -1,   // 1, 2
    8,   -1,   // 3, 4
    9,   -1,   // 5, 6
    7,   15,   // 7, 8
    -1,  16,   // 9, 10
    0,    1,   //11, 12
    2,   -1,   //13, 14
    3,    4,   //15, 16
    -1,   5,   //17, 18
    12,  -1,   //19, 20
    13,   6,   //21, 22
    14,  10,   //23, 24
    -1,  11,   //25, 26
    30,  31,   //27, 28
    21,  -1,   //29, 30
    22,  26,   //31, 32
    23,  -1,   //33, 34
    24,  27,   //35, 36
    25,  28,   //37, 38
    -1,  29,   //39, 40
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
    -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

char *physNames[64] =
{
    NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "  GPIO.7", "TxD3    ",
 "      0v", "RxD3    ",
 "    RxD2", "GPIO.1  ",
 "    TxD2", "0v      ",
 "    CTS2", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 "    MOSI", "0v      ",
 "    MISO", "RTS2    ",
 "    SCLK", "CE0     ",
 "      0v", "GPIO.11 ",
 "   SDA.1", "SCL.1   ",
 " GPIO.21", "0v      ",
 " GPIO.22", "RTS1    ",
 " GPIO.23", "0v      ",
 " GPIO.24", "CTS1    ",
 " GPIO.25", "TxD1    ",
 "      0v", "RxD1    ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
  "GPIO.17", "GPIO.18",
  "GPIO.19", "GPIO.20",
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
char *physNames[64] =
{
    NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "  GPIO.7", "TxD2    ",
 "      0v", "RxD2    ",
 "    RxD1", "GPIO.1  ",
 "    TxD1", "0v      ",
 "    CTS1", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 " SPI2_DI", "0v      ",
 "SPI2_DIO", "RTS1    ",
 "SPI2_CLK", "SPI2_CS0",
 "      0v", "SPI2_CS1",
 "   SDA.1", "SCL.1   ",
 " GPIO.21", "0v      ",
 " GPIO.22", "RTS2    ",
 " GPIO.23", "0v      ",
 " GPIO.24", "CTS2    ",
 " GPIO.25", "SCL.2   ",
 "      0v", "SDA.2   ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

int physToWpi[64] =
{
    -1,        // 0
    -1,  -1,   // 1, 2
    8,   -1,   // 3, 4
    9,   -1,   // 5, 6
    7,   15,   // 7, 8
    -1,  16,   // 9, 10
    0,    1,   //11, 12
    2,   -1,   //13, 14
    3,    4,   //15, 16
    -1,   5,   //17, 18
    12,  -1,   //19, 20
    13,   6,   //21, 22
    14,  10,   //23, 24
    -1,  11,   //25, 26
    30,  31,   //27, 28
    21,  -1,   //29, 30
    22,  26,   //31, 32
    23,  -1,   //33, 34
    24,  27,   //35, 36
    25,  28,   //37, 38
    -1,  29,   //39, 40
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
    -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};
#endif

#ifdef CONFIG_ORANGEPI_A64
char *physNames [64] =
{
  NULL,

 "    3.3v", "5v      ",
 "   SDA.1", "5V      ",
 "   SCL.1", "0v      ",
 "  GPIO.7", "S_TX    ",
 "      0v", "S_RX    ",
 "    RxD3", "GPIO.1  ",
 "    TxD3", "0v      ",
 "    CTS3", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 "    MOSI", "0v      ",
 "    MISO", "RTS3    ",
 "    SCLK", "CE0     ",
 "      0v", "GPIO.11 ",
 "   SDA.2", "SCL.2   ",
 " GPIO.21", "0v      ",
 " GPIO.22", "RTS2    ",
 " GPIO.23", "0v      ",
 " GPIO.24", "CTS2    ",
 " GPIO.25", "TxD2    ",
 "      0v", "RxD2    ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
  "GPIO.17", "GPIO.18",
  "GPIO.19", "GPIO.20",
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

int physToWpi [64] =
{
  -1,        // 0
  -1,  -1,   // 1, 2
   8,  -1,   // 3, 4
   9,  -1,   // 5, 6
   7,  15,   // 7, 8
  -1,  16,   // 9, 10
   0,   1,   //11, 12
   2,  -1,   //13, 14
   3,   4,   //15, 16
  -1,   5,   //17, 18
  12,  -1,   //19, 20
  13,   6,   //21, 22
  14,  10,   //23, 24
  -1,  11,   //25, 26
  30,  31,   //27, 28
  21,  -1,   //29, 30
  22,  26,   //31, 32
  23,  -1,   //33, 34
  24,  27,   //35, 36
  25,  28,   //37, 38
  -1,  29,   //39, 40
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
   -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};
#endif

#ifdef CONFIG_ORANGEPI_H3
int pinToGpioOrangePi [64] =
{
  12, 11, 6, 13, 14, 1, 110, 0,    // From the Original Wiki - GPIO 0 through 7:   wpi  0 -  7
   3,  68,               // I2C  - SDA0, SCL0                wpi  8 -  9
   71,  64,               // SPI  - CE1, CE0              wpi 10 - 11
  65,  2, 66,               // SPI  - MOSI, MISO, SCLK          wpi 12 - 14
  67, 21,               // UART - Tx, Rx                wpi 15 - 16
  19, 18, 7, 8,           // Rev 2: New GPIOs 8 though 11         wpi 17 - 20
  200,  9, 10, 201, 20,           // B+                       wpi 21, 22, 23, 24, 25
  198, 199, 4, 5,           // B+                       wpi 26, 27, 28, 29
   -1, -1,               // B+                       wpi 30, 31

// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 47
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int physToWpi[64] =
{
	-1,		// 0
	-1, -1,	// 1, 2
	0, -1,  //3, 4
	1, -1,  //5, 6
	2, 3,  //7, 8
	-1, 4, //9,10
	5, 6, //11,12
	7, -1, //13,14
	8, 9, //15,16
	-1, 10, //17,18
	11, -1, //19,20
	12, 13, //21,22
	14, 15, //23, 24
	-1,  16,	// 25, 26

	17,	18,   //27, 28
	19,  -1,	//29, 30
	20,  21,	//31, 32
	22, -1, //33, 34
	23, 24, //35, 36
	25, 26, //37, 38
	-1, 27, //39, 40
	28, 29, //41, 42
	// Padding:

    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 56
	-1, -1, -1, -1, -1, -1, -1,	// ... 63
};

char *physNames[64] =
{
  NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "     PA6", "TxD3    ",
 "      0v", "RxD3    ",
 "    RxD2", "PD14    ",
 "    TxD2", "0v      ",
 "    CTS2", "PC04    ",
 "    3.3v", "PC07    ",
 "    MOSI", "0v      ",
 "    MISO", "RTS2    ",
 "    SCLK", "CE0     ",
 "      0v", "PA21    ",
 "   SDA.1", "SCL.1   ",
 "    PA07", "0v      ",
 "    PA08", "RTS1    ",
 "    PA09", "0v      ",
 "    PA10", "CTS1    ",
 "    PA20", "TxD1    ",
 "      0v", "RxD1    ",
 "    PA04", "PA05    ",
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
  	   NULL, NULL,
       NULL, NULL,
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_ZERO
int physToWpi [64] =
{
  -1,        // 0

  -1,  -1,   // 1, 2
   8,  -1,   // 3, 4
   9,  -1,   // 5, 6
   7,  15,   // 7, 8
  -1,  16,   // 9, 10
   0,   1,   //11, 12
   2,  -1,   //13, 14
   3,   4,   //15, 16
  -1,   5,   //17, 18
  12,  -1,   //19, 20
  13,   6,   //21, 22
  14,  10,   //23, 24
  -1,  11,   //25, 26

  30,  -1,   //27, 28

  -1,  -1,   //29, 30
  -1,  -1,   //31, 32
  -1,  -1,   //33, 34
  -1,  -1,   //35, 36
  -1,  -1,   //37, 38
  -1,  -1,   //39, 40
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
   -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

char *physNames[64] =
{
      NULL,

 "    3.3v", "5v      ",
 "   SDA.0", "5V      ",
 "   SCL.0", "0v      ",
 "  GPIO.7", "TxD3    ",
 "      0v", "RxD3    ",
 "    RxD2", "GPIO.1  ",
 "    TxD2", "0v      ",
 "    CTS2", "GPIO.4  ",
 "    3.3v", "GPIO.5  ",
 "    MOSI", "0v      ",
 "    MISO", "RTS2    ",
 "    SCLK", "CE0     ",
 "      0v", "GPIO.11 ",

 "STAT-LED", "PWR-LED ",

       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_LITE2
int physToWpi [64] = 
{
	-1, 		  // 0
	-1, -1, 	  // 1, 2
	 0, -1,
	 1, -1, 	  
	 2,  3, 	  //7, 8
	-1,  4, 	  
	 5,  6, 	  //11, 12
	 7, -1, 	  
	 8,  9, 	  //15, 16
	-1, 10, 	  
	11, -1, 	  //19, 20
	12, 13, 	  
	14, 15, 	  //23, 24
	-1, 16, 	  // 25, 26
	
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
	-1, -1, -1, -1, -1, -1, -1,   // ... 63

};

char *physNames [64] = 
{
  	   NULL,

 "    3.3v", "5v      ",
 "   SDA.1", "5V      ",
 "   SCL.1", "0v      ",
 "    PWM1", "PD21    ",
 "      0v", "PD22    ",
 "    RxD3", "PC09    ",
 "    TxD3", "0v      ",
 "    CTS3", "PC08    ",
 "    3.3v", "PC07    ",
 "  MOSI.0", "0v      ",
 "  MISO.0", "RTS3    ",
 "  SCLK.0", "CE.0    ",
 "      0v", "PH03    ",

	   NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL, NULL,
       NULL,
};
#endif

/*
 * ReadAll 
 */
void OrangePiReadAll(void)
{
    int pin;
	int tmp = wiringPiDebug;
    wiringPiDebug = FALSE;
#ifdef CONFIG_ORANGEPI_PC2
    printf (" +------+-----+----------+------+---+OrangePi PC2+---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_2G_IOT
    printf (" +-----+-----+----------+------+---+OrangePi 2G-IOT+---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_H3
    printf (" +------+-----+----------+------+---+OrangePiH3+---+------+----------+-----+------+\n");
#elif CONFIG_ORANGEPI_ZERO
    printf (" +------+-----+----------+------+---+OrangePi Zero+---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_A64
    printf (" +------+-----+----------+------+---+OrangePi Win/Win+ +---+---+------+---------+-----+--+\n");
#elif CONFIG_ORANGEPI_LITE2
    printf (" +------+-----+----------+------+---+OrangePiH6+---+------+----------+-----+------+\n");
#endif
    printf (" | GPIO | wPi |   Name   | Mode | V | Physical | V | Mode | Name     | wPi | GPIO |\n");
    printf (" +------+-----+----------+------+---+----++----+---+------+----------+-----+------+\n");

#ifdef CONFIG_ORANGEPI_H3
    for (pin = 1 ; pin <= 42 ; pin += 2)
#else CONFIG_ORANGEPI_LITE2
	for (pin = 1 ; pin <= 26 ; pin += 2)
#endif
        readallPhys(pin) ;

    printf (" +------+-----+----------+------+---+----++----+---+------+----------+-----+------+\n");
    printf (" | GPIO | wPi |   Name   | Mode | V | Physical | V | Mode | Name     | wPi | GPIO |\n");
#ifdef CONFIG_ORANGEPI_PC2
    printf (" +------+-----+----------+------+---+OrangePi PC2+---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_2G_IOT
    printf (" +------+-----+----------+------+---+OrangePi 2G-IOT+---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_H3
    printf (" +------+-----+----------+------+---+OrangePiH3+---+------+----------+-----+------+\n");
#elif CONFIG_ORANGEPI_ZERO
    printf (" +------+-----+----------+------+---+OrangePi Zero+---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_A64
    printf (" +------+-----+----------+------+---+OrangePi Win/Win+ +---+------+----------+-----+-----+\n");
#elif CONFIG_ORANGEPI_LITE2
    printf (" +------+-----+----------+------+---+OrangePiH6+---+------+----------+-----+------+\n");
#endif
    wiringPiDebug = tmp;
}
