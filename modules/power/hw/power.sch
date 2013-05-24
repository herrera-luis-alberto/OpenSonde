EESchema Schematic File Version 2  date Fri May 24 15:58:37 2013
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
LIBS:opensondebus
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title "Power Module"
Date "24 may 2013"
Rev ""
Comp "Universidad de Chile"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 5100 1750 0    60   ~ 0
Copyright UNIVERSIDAD DE CHILE 2013.\n\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1 or later.\n\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions
Connection ~ 3250 4100
Wire Wire Line
	3050 4100 3350 4100
Connection ~ 3250 2800
Wire Wire Line
	3050 2800 3300 2800
Wire Wire Line
	7050 3600 7250 3600
Wire Wire Line
	7050 3600 7050 3500
Wire Wire Line
	7450 3400 7450 3600
Wire Wire Line
	5875 4400 5975 4400
Wire Wire Line
	5875 3075 5975 3075
Connection ~ 4200 4100
Wire Wire Line
	4200 4000 4200 4300
Wire Wire Line
	4200 4100 4150 4100
Connection ~ 3750 4700
Connection ~ 4200 2800
Wire Wire Line
	4200 2700 4200 2950
Wire Wire Line
	3700 3100 3700 3550
Wire Wire Line
	3250 2800 3250 2950
Wire Wire Line
	2600 2650 2600 2850
Wire Wire Line
	4200 2800 4100 2800
Connection ~ 3700 3350
Wire Wire Line
	4200 3350 3250 3350
Wire Wire Line
	3750 4600 3750 5000
Wire Wire Line
	4200 4700 3250 4700
Wire Wire Line
	3250 4100 3250 4300
Wire Wire Line
	6825 3675 6825 3750
Wire Wire Line
	6075 3075 6175 3075
Wire Wire Line
	6075 4400 6175 4400
Wire Wire Line
	7250 3600 7250 3400
Wire Wire Line
	6825 3750 6850 3750
Wire Wire Line
	2400 3000 2400 2650
Text Label 7050 3500 0    60   ~ 0
V_IN
$Comp
L GND #PWR01
U 1 1 50D0749C
P 7450 3600
F 0 "#PWR01" H 7450 3600 30  0001 C CNN
F 1 "GND" H 7450 3530 30  0001 C CNN
	1    7450 3600
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG02
U 1 1 50D07490
P 7450 3400
F 0 "#FLG02" H 7450 3495 30  0001 C CNN
F 1 "PWR_FLAG" H 7450 3580 30  0000 C CNN
	1    7450 3400
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG03
U 1 1 50D07483
P 7250 3400
F 0 "#FLG03" H 7250 3495 30  0001 C CNN
F 1 "PWR_FLAG" H 7250 3580 30  0000 C CNN
	1    7250 3400
	1    0    0    -1  
$EndComp
Text Label 6850 3750 0    60   ~ 0
V_IN
Text Label 3050 4100 0    60   ~ 0
V_IN
Text Label 3050 2800 0    60   ~ 0
V_IN
Text Label 2400 3000 0    60   ~ 0
V_IN
$Comp
L GND #PWR04
U 1 1 50D06EEF
P 2600 2850
F 0 "#PWR04" H 2600 2850 30  0001 C CNN
F 1 "GND" H 2600 2780 30  0001 C CNN
	1    2600 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 50D06EDF
P 3700 3550
F 0 "#PWR05" H 3700 3550 30  0001 C CNN
F 1 "GND" H 3700 3480 30  0001 C CNN
	1    3700 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 50D06ED9
P 3750 5000
F 0 "#PWR06" H 3750 5000 30  0001 C CNN
F 1 "GND" H 3750 4930 30  0001 C CNN
	1    3750 5000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR07
U 1 1 50D06EB5
P 4200 4000
F 0 "#PWR07" H 4200 3960 30  0001 C CNN
F 1 "+3.3V" H 4200 4110 30  0000 C CNN
	1    4200 4000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR08
U 1 1 50D06EA8
P 4200 2700
F 0 "#PWR08" H 4200 2790 20  0001 C CNN
F 1 "+5V" H 4200 2790 30  0000 C CNN
	1    4200 2700
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 50D06E86
P 4200 4500
F 0 "C4" H 4250 4600 50  0000 L CNN
F 1 "0.1u" H 4250 4400 50  0000 L CNN
	1    4200 4500
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 50D06E2F
P 2500 2300
F 0 "P1" V 2450 2300 40  0000 C CNN
F 1 "CONN_2" V 2550 2300 40  0000 C CNN
	1    2500 2300
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 50D06DD0
P 3250 3150
F 0 "C1" H 3300 3250 50  0000 L CNN
F 1 "0.33u" H 3300 3050 50  0000 L CNN
	1    3250 3150
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 50D06DCD
P 4200 3150
F 0 "C2" H 4250 3250 50  0000 L CNN
F 1 "0.1u" H 4250 3050 50  0000 L CNN
	1    4200 3150
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 50D06DCA
P 3250 4500
F 0 "C3" H 3300 4600 50  0000 L CNN
F 1 "0.33u" H 3300 4400 50  0000 L CNN
	1    3250 4500
	1    0    0    -1  
$EndComp
$Comp
L LM317 U2
U 1 1 50D06C1B
P 3750 4250
F 0 "U2" H 3750 4550 60  0000 C CNN
F 1 "LM317" H 3800 4000 60  0000 L CNN
	1    3750 4250
	1    0    0    -1  
$EndComp
$Comp
L 7805 U1
U 1 1 50D06905
P 3700 2850
F 0 "U1" H 3850 2654 60  0000 C CNN
F 1 "7805" H 3700 3050 60  0000 C CNN
	1    3700 2850
	1    0    0    -1  
$EndComp
$Comp
L OPENSONDEBUS B1
U 1 1 50D068EF
P 6050 3700
F 0 "B1" H 6050 3700 60  0000 C CNN
F 1 "OPENSONDEBUS" H 6050 3700 60  0000 C CNN
	1    6050 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
