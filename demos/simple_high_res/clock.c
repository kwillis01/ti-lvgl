#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "lv_demo_simple_high_res_private.h"
#include "../../src/osal/lv_os.h"


static void slice(const char* str, char* result, size_t start, size_t end) {
    strncpy(result, str + start, end - start);
    result[end - start] = '\0';
}

void *clock_init(void * api_arg) {
    lv_demo_simple_high_res_api_t *api = (lv_demo_simple_high_res_api_t*)api_arg;

    int last_minute = -1;
    while(1){
        char buffer[128];
        FILE *fp = popen("date", "r");

        if (fp == NULL) {
            perror("popen failed");
            return NULL;
        }

        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            continue;
        }
        
        char sliced_hour[4];
        slice(buffer, sliced_hour, 11, 11 + 2);
        int hour = atoi(sliced_hour);
        
        char sliced_minute[4];
        slice(buffer, sliced_minute, 14, 14 + 2);
        int minute = atoi(sliced_minute);
        if(last_minute==-1){
            lv_lock();
            lv_subject_set_int(&api->subjects.hour, hour);
            lv_subject_set_int(&api->subjects.minute, minute);
            lv_unlock();
            last_minute = minute;
        }
        
        pclose(fp);

        if(last_minute != minute){
            lv_lock();
            lv_subject_set_int(&api->subjects.hour, hour);
            lv_subject_set_int(&api->subjects.minute, minute);
            lv_unlock();
        }
        last_minute = minute;
        usleep(1000000);
    }
    return NULL;
}