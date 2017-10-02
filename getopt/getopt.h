#pragma once
//MSDN98\SAMPLES\VC98\SDK\NETDS\SNA\SHARED\GETOPT.C

extern char *optarg;
extern int optind;
extern int opterr;

extern int getopt(int argc, char *argv[], char *opstring);