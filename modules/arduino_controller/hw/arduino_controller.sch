EESchema Schematic File Version 2  date Thu 20 Dec 2012 04:44:22 PM CLST
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino
LIBS:breakboards
LIBS:opensondebus
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "20 dec 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 9150 2250
Wire Wire Line
	9300 2150 9300 2250
Wire Wire Line
	9300 2250 9000 2250
Wire Wire Line
	9000 1750 9000 1550
Wire Wire Line
	8700 1700 8700 1550
Wire Wire Line
	8450 1550 8450 1700
Wire Wire Line
	8450 1700 8150 1700
Wire Wire Line
	8300 1500 8300 2100
Wire Wire Line
	6800 1500 6800 2100
Wire Wire Line
	6950 2200 6825 2200
Wire Wire Line
	8400 2775 8225 2775
Wire Wire Line
	4550 3850 4550 3700
Wire Wire Line
	5950 2525 5950 2300
Wire Wire Line
	5950 2300 5650 2300
Wire Wire Line
	6825 2975 6900 2975
Wire Wire Line
	6825 2975 6825 2200
Wire Wire Line
	8300 2975 8300 2200
Wire Wire Line
	8300 2200 8150 2200
Wire Wire Line
	6950 1800 6900 1800
Wire Wire Line
	6800 2100 6950 2100
Wire Wire Line
	8300 2100 8150 2100
Connection ~ 8300 1700
Connection ~ 6800 1700
Wire Wire Line
	8225 2875 8225 1800
Wire Wire Line
	8225 1800 8150 1800
Connection ~ 8225 2775
Wire Wire Line
	6900 1800 6900 2875
Connection ~ 6900 2775
Wire Wire Line
	8225 3075 8225 2975
Wire Wire Line
	6900 2975 6900 3075
Wire Wire Line
	5650 2200 6625 2200
Wire Wire Line
	6625 2200 6625 3725
Connection ~ 7550 3725
Wire Wire Line
	3650 2500 3450 2500
Wire Wire Line
	3450 2500 3450 2625
Wire Wire Line
	4750 3700 4750 3850
Wire Wire Line
	8225 2975 8425 2975
Connection ~ 8300 2975
Wire Wire Line
	6625 3725 7775 3725
Wire Wire Line
	7775 3725 7775 3650
Connection ~ 7625 3725
Wire Wire Line
	6625 1550 6625 1700
Wire Wire Line
	6625 1700 6950 1700
Wire Wire Line
	9300 1750 9300 1550
Wire Wire Line
	9000 2250 9000 2150
Wire Wire Line
	9150 2250 9150 2350
$Comp
L GND #PWR01
U 1 1 50D36A69
P 9150 2350
F 0 "#PWR01" H 9150 2350 30  0001 C CNN
F 1 "GND" H 9150 2280 30  0001 C CNN
	1    9150 2350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 50D36A62
P 9300 1550
F 0 "#PWR02" H 9300 1510 30  0001 C CNN
F 1 "+3.3V" H 9300 1660 30  0000 C CNN
	1    9300 1550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 50D36A5D
P 9000 1550
F 0 "#PWR03" H 9000 1640 20  0001 C CNN
F 1 "+5V" H 9000 1640 30  0000 C CNN
	1    9000 1550
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 50D36A4F
P 9300 1950
F 0 "C2" H 9350 2050 50  0000 L CNN
F 1 "C" H 9350 1850 50  0000 L CNN
	1    9300 1950
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 50D36A4B
P 9000 1950
F 0 "C1" H 9050 2050 50  0000 L CNN
F 1 "C" H 9050 1850 50  0000 L CNN
	1    9000 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 50D11396
P 8700 1700
F 0 "#PWR04" H 8700 1700 30  0001 C CNN
F 1 "GND" H 8700 1630 30  0001 C CNN
	1    8700 1700
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 50D11392
P 8700 1550
F 0 "#FLG05" H 8700 1645 30  0001 C CNN
F 1 "PWR_FLAG" H 8700 1730 30  0000 C CNN
	1    8700 1550
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG06
U 1 1 50D11354
P 6625 1550
F 0 "#FLG06" H 6625 1645 30  0001 C CNN
F 1 "PWR_FLAG" H 6625 1730 30  0000 C CNN
	1    6625 1550
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG07
U 1 1 50D11347
P 8450 1550
F 0 "#FLG07" H 8450 1645 30  0001 C CNN
F 1 "PWR_FLAG" H 8450 1730 30  0000 C CNN
	1    8450 1550
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG08
U 1 1 50D11339
P 7775 3650
F 0 "#FLG08" H 7775 3745 30  0001 C CNN
F 1 "PWR_FLAG" H 7775 3830 30  0000 C CNN
	1    7775 3650
	1    0    0    -1  
$EndComp
NoConn ~ 3650 2200
NoConn ~ 3650 2300
NoConn ~ 3650 2400
NoConn ~ 3650 2600
NoConn ~ 3650 2700
NoConn ~ 3650 2800
NoConn ~ 3650 2900
NoConn ~ 3650 3000
NoConn ~ 3650 3100
NoConn ~ 3650 3200
NoConn ~ 3650 3300
NoConn ~ 4800 1800
NoConn ~ 4900 1800
NoConn ~ 5650 3300
NoConn ~ 5650 3200
NoConn ~ 5650 3100
NoConn ~ 5650 3000
NoConn ~ 5650 2900
NoConn ~ 5650 2800
NoConn ~ 5650 2700
NoConn ~ 5650 2600
NoConn ~ 5650 2500
NoConn ~ 5650 2400
NoConn ~ 4700 1800
NoConn ~ 4600 1800
NoConn ~ 4500 1800
NoConn ~ 4400 1800
Text Label 4550 3850 0    60   ~ 0
SDA
Text Label 4750 3850 0    60   ~ 0
SCL
Text Label 8425 2975 0    60   ~ 0
SCL
Text Label 8400 2775 0    60   ~ 0
SDA
$Comp
L GND #PWR09
U 1 1 50D1118A
P 3450 2625
F 0 "#PWR09" H 3450 2625 30  0001 C CNN
F 1 "GND" H 3450 2555 30  0001 C CNN
	1    3450 2625
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 50D11181
P 5950 2525
F 0 "#PWR010" H 5950 2525 30  0001 C CNN
F 1 "GND" H 5950 2455 30  0001 C CNN
	1    5950 2525
	1    0    0    -1  
$EndComp
NoConn ~ 6950 1900
NoConn ~ 6950 2300
NoConn ~ 8150 2300
NoConn ~ 8150 1900
$Comp
L +3.3V #PWR011
U 1 1 50D110AA
P 6800 1500
F 0 "#PWR011" H 6800 1460 30  0001 C CNN
F 1 "+3.3V" H 6800 1610 30  0000 C CNN
	1    6800 1500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 50D1109D
P 8300 1500
F 0 "#PWR012" H 8300 1590 20  0001 C CNN
F 1 "+5V" H 8300 1590 30  0000 C CNN
	1    8300 1500
	1    0    0    -1  
$EndComp
$Comp
L LOGICLEVELCONVERTER U1
U 2 1 50D11013
P 7550 2200
F 0 "U1" H 7550 2200 60  0000 C CNN
F 1 "LOGICLEVELCONVERTER" H 7600 2700 60  0000 C CNN
	2    7550 2200
	1    0    0    -1  
$EndComp
$Comp
L LOGICLEVELCONVERTER U1
U 1 1 50D1100E
P 7550 1800
F 0 "U1" H 7550 1800 60  0000 C CNN
F 1 "LOGICLEVELCONVERTER" H 7600 2300 60  0000 C CNN
	1    7550 1800
	1    0    0    -1  
$EndComp
$Comp
L ARDUINOMINIPRO U2
U 1 1 50D11005
P 4650 2750
F 0 "U2" H 4650 2750 60  0000 C CNN
F 1 "ARDUINOMINIPRO" H 4650 2750 60  0000 C CNN
	1    4650 2750
	1    0    0    -1  
$EndComp
$Comp
L OPENSONDEBUS B1
U 1 1 50D10FFA
P 7600 2950
F 0 "B1" H 7600 2950 60  0000 C CNN
F 1 "OPENSONDEBUS" H 7600 2950 60  0000 C CNN
	1    7600 2950
	0    1    1    0   
$EndComp
$EndSCHEMATC
