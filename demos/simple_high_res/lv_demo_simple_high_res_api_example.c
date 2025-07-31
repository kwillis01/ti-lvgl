/**
 * @file lv_demo_simple_high_res_api_example.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include <stdlib.h>
#include <signal.h>
#include "../../src/core/lv_refr.h"
#include "lv_demo_simple_high_res.h"
#include "../../src/osal/lv_os.h"
#include <string.h>
#include <stdio.h>
#include<pthread.h>
#if LV_USE_DEMO_SIMPLE_HIGH_RES

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static pthread_t clock_thread;
static void exit_cb(int sig);

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_demo_simple_high_res_api_t * api = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL VARIABLES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
extern void *clock_init(void * );


void lv_demo_simple_high_res_api_example(const char * logo_path)
{
	if (!api)
		api = lv_demo_simple_high_res(logo_path, exit_cb);
	else
		return;

	/* handle SIGINT (for eg, sent by Crtl-C and `kill`) and SIGTERM (for eg, sent by `systemctl stop`) */
	struct sigaction sa;
	sa.sa_handler = exit_cb;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
    pthread_create(&clock_thread, NULL, clock_init, (void*)api);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void exit_cb(int sig)
{
	if (api)
		lv_obj_delete(api->base_obj);
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_black(), 0);
    lv_refr_now(NULL);
    system("cat /dev/zero > /dev/fb0 2>/dev/null");
    exit(0);
}

#endif /*LV_USE_DEMO_SIMPLE_HIGH_RES*/
