#include <iostream>
#include <string>
#ifdef _WIN32
#include "getopt.h"
#elif __linux__
#include <unistd.h>
#elif __APPLE__
#include <unistd.h>
#endif
#include "ScoreManagementSystem.h"

void help();  // °ïÖúÎÄ±¾
void abort();  // ºöÂÔº¯Êı
