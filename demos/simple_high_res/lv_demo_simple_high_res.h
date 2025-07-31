/**
 * @file lv_demo_simple_high_res.h
 *
 */

#ifndef LV_DEMO_SIMPLE_HIGH_RES_H
#define LV_DEMO_SIMPLE_HIGH_RES_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "../../src/lv_conf_internal.h"
#if LV_USE_DEMO_SIMPLE_HIGH_RES

#include "../../src/others/observer/lv_observer.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    struct {
        /* input subjects */
        /* int:     the hour shown on clocks,     e.g. 9                                               */
        lv_subject_t hour;
        /* int:     the minute shown on clocks,   e.g. 36                                              */
        lv_subject_t minute;
    } subjects;

    /* the object that is created on the active screen which contains the demo contents.
     * Can be deleted to close the demo.
     */
    lv_obj_t * base_obj;
    void * user_data; /* optional extra data field for the user to use freely */
} lv_demo_simple_high_res_api_t;

typedef void (*lv_demo_simple_high_res_exit_cb_t)(int);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Start the High Resolution Demo on the default display, on the active screen.
 * This demo requires `LV_USE_DEMO_SIMPLE_HIGH_RES` and `LV_FONT_FMT_TXT_LARGE`
 * to be enabled as well as a filesystem driver to be configured and the
 * `LV_FS_DEFAULT_DRIVER_LETTER` set. The display size should be
 * 800x480, 1280x720, or 1920x1080.
 * @param logo_path         A path to a logo to display in the bottom-left
 *                          of the home screen. If `NULL`, an LVGL logo is used.
 * @param exit_cb           A callback function which will be called when the
 *                          "logout" button is clicked, or `NULL` to do nothing.
 * @return                  A struct with subjects to control the UI
 *                          and react to input.
 */
lv_demo_simple_high_res_api_t * lv_demo_simple_high_res(const char * logo_path,
                                          lv_demo_simple_high_res_exit_cb_t exit_cb);

/**
 * This function demonstrates how the demo's API can be used.
 * Start the High Resolution Demo on the default display, on the active screen.
 * This demo requires `LV_USE_DEMO_SIMPLE_HIGH_RES` and `LV_FONT_FMT_TXT_LARGE`
 * to be enabled as well as a filesystem driver to be configured and the
 * `LV_FS_DEFAULT_DRIVER_LETTER` set. The display size should be
 * 800x480, 1280x720, or 1920x1080.
 * @param logo_path         A path to a logo to display in the bottom-left
 *                          of the home screen. If `NULL`, an LVGL logo is used.
 */
void lv_demo_simple_high_res_api_example(const char * logo_path);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_DEMO_SIMPLE_HIGH_RES*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_DEMO_SIMPLE_HIGH_RES_H*/
