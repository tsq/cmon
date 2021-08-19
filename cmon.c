/**
 * Copyright (c) 2021, TANG SHIQIANG <https://github.com/tsq>
 * All rights reserved.
 */
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h> // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

char version[] = "1.0.0";
char *cFileName = "";
struct tm *t;
struct stat attrib;
char old_timestamp[60] = "";

void print_info()
{
    printf("\x1b[33m[cmon] %s\x1b[0m\n", version);
    printf("\x1b[33m[cmon] watching file: %s\x1b[0m\n", cFileName);
}

void showErrMsg(char msg[])
{
    printf("\x1b[31m%s\x1b[0m", msg);
    exit(1);
}

void get_c_file_name(int argc, char **argv)
{
    // get filename from command line arguments
    if (argc == 1)
    {
        showErrMsg("Error: You need to specify a c file!");
    }

    char *fileName = argv[1];

    if (!strstr(fileName, ".c"))
    {
        strcat(fileName, ".c");
    }
    cFileName = fileName;

    if (access(cFileName, F_OK) == -1)
    {
        showErrMsg("Error: c file not found!");
    }
}

void find_gcc()
{
    int gccExist = 0;
    if (gccExist != 0)
    {
        showErrMsg("Error: gcc is not found!");
    }
}

void compile_and_run()
{
    char exe[100] = "";
    strcpy(exe, cFileName);
    char *filename_dot = strchr(exe, '.');
    int offset = filename_dot - exe;
    exe[offset] = '\0';
    char dest[1000] = "gcc ";
    strcat(dest, cFileName);
    strcat(dest, " -o ");
    strcat(dest, exe);
#ifdef WIN32
    strcat(dest, " && ");
#else
    strcat(dest, " && ./");
#endif
    strcat(dest, exe);
    printf("\x1b[32m[cmon] starting `%s`\x1b[0m\n", dest);
    system(dest);
    printf("\x1b[32m[cmon] waiting for changes before restart\x1b[0m\n");
}

void sleep_ms(int milliseconds)
{ // cross-platform sleep function
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    if (milliseconds >= 1000)
        sleep(milliseconds / 1000);
    usleep((milliseconds % 1000) * 1000);
#endif
}

int is_changed()
{
    stat(cFileName, &attrib);
    t = localtime(&(attrib.st_mtime));
    int year = t->tm_year;
    int month = t->tm_mon;
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int min = t->tm_min;
    int sec = t->tm_sec;
    char text_year[10];
    char text_month[10];
    char text_day[10];
    char text_hour[10];
    char text_min[10];
    char text_sec[10];
    sprintf(text_year, "%d", year);
    sprintf(text_month, "%d", month);
    sprintf(text_day, "%d", day);
    sprintf(text_hour, "%d", hour);
    sprintf(text_min, "%d", min);
    sprintf(text_sec, "%d", sec);

    char new_timestamp[60] = "";
    strcat(new_timestamp, text_year);
    strcat(new_timestamp, text_month);
    strcat(new_timestamp, text_day);
    strcat(new_timestamp, text_hour);
    strcat(new_timestamp, text_min);
    strcat(new_timestamp, text_sec);

    if (strcmp(old_timestamp, "") == 0)
    {
        strcpy(old_timestamp, new_timestamp);
        return 0;
    }
    else
    {
        if (strcmp(old_timestamp, new_timestamp) == 0)
        {
            // no changed
            return 0;
        }
        else
        {
            strcpy(old_timestamp, new_timestamp);
            // changed
            return 1;
        }
    }
}

void watch()
{

    while (1)
    {
        sleep_ms(1000);
        int changed = is_changed();

        if (changed)
        {
            compile_and_run();
        }
    }
}

int main(int argc, char **argv)
{
    find_gcc();
    get_c_file_name(argc, argv);
    print_info();
    compile_and_run();
    watch();
    return 0;
}
