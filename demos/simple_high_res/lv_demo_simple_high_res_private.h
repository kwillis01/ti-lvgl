/**
 * @file lv_demo_simple_high_res_private.h
 *
 */

#ifndef LV_DEMO_SIMPLE_HIGH_RES_PRIVATE_H
#define LV_DEMO_SIMPLE_HIGH_RES_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "../../src/lv_conf_internal.h"
#if LV_USE_DEMO_SIMPLE_HIGH_RES

#include "lv_demo_simple_high_res.h"
#include "../../src/core/lv_obj.h"
#include "../../src/others/observer/lv_observer.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

enum {
    STYLE_COLOR_BASE = 0,
    STYLE_COLOR_ACCENT,
    STYLE_COLOR_COUNT
};

enum {
    STYLE_TYPE_OBJ = 0,
    STYLE_TYPE_TEXT,
    STYLE_TYPE_A8_IMG,
    STYLE_TYPE_COUNT
};

enum {
    FONT_HEADING_MD = 0,
    FONT_HEADING_LG,
    FONT_HEADING_XL,
    FONT_HEADING_XXL,
    FONT_LABEL_XS,
    FONT_LABEL_SM,
    FONT_LABEL_MD,
    FONT_LABEL_LG,
    FONT_LABEL_XL,
    FONT_LABEL_2XL,
    FONT_COUNT
};

enum {
    SIZE_SM = 0,
    SIZE_MD,
    SIZE_LG,
    SIZE_COUNT
};

enum {
    ICON_SM = 0,
    ICON_MD,
    ICON_LG,
    ICON_XL,
    ICON_2XL,
    ICON_COUNT
};

typedef struct {
    lv_color_t base;
    lv_color_t accent;
} lv_demo_simple_high_res_theme_t;

typedef struct {
    int32_t gap[10 + 1];
    int32_t icon[ICON_COUNT];
    int32_t card_long_edge;
    int32_t widget_long_edge;
    int32_t card_short_edge;
    int32_t smart_home_arc_diameter;
    int32_t ev_charging_arc_diameter;
    int32_t smart_meter_collapsed_part_height;
    int32_t slider_width;
    int32_t small_chart_height;
    int32_t large_chart_height;
    int32_t card_radius;
    int32_t health_panel_width;
    int32_t settings_panel_width;
    int32_t home_bottom_margin_height;
    int32_t indicator_width;
    int32_t indicator_height;
    void (*init_fonts_cb)(lv_style_t * fonts);
} lv_demo_simple_high_res_sizes_t;

typedef struct {
    struct {
        lv_subject_t group;
        lv_subject_t * members[2];
    } time;
} lv_demo_simple_high_res_subject_groups_t;

typedef struct {
    const lv_demo_simple_high_res_sizes_t * sz;
    lv_style_t styles[STYLE_COLOR_COUNT][STYLE_TYPE_COUNT];
    lv_style_t fonts[FONT_COUNT];
    lv_subject_t th;
    char * logo_path;
    lv_demo_simple_high_res_exit_cb_t exit_cb;
    bool top_margin_subjects_are_init;
    lv_demo_simple_high_res_api_t api;
    lv_demo_simple_high_res_subject_groups_t subject_groups;
} lv_demo_simple_high_res_ctx_t;

LV_ATTRIBUTE_EXTERN_DATA extern const lv_demo_simple_high_res_theme_t lv_demo_simple_high_res_theme_light;
LV_ATTRIBUTE_EXTERN_DATA extern const lv_demo_simple_high_res_theme_t lv_demo_simple_high_res_theme_dark;
LV_ATTRIBUTE_EXTERN_DATA extern const lv_demo_simple_high_res_sizes_t lv_demo_simple_high_res_sizes_all[SIZE_COUNT];

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * lv_demo_simple_high_res_base_obj_create(const char * logo_path,
                                            lv_demo_simple_high_res_exit_cb_t exit_cb);

void lv_demo_simple_high_res_home(lv_obj_t * base_obj);
lv_obj_t * lv_demo_simple_high_res_top_margin_create(lv_obj_t * parent, int32_t pad_hor, bool show_time,
                                              lv_demo_simple_high_res_ctx_t * c);
void lv_demo_simple_high_res_top_margin_deinit_subjects(lv_demo_simple_high_res_ctx_t * c);

lv_obj_t * lv_demo_simple_high_res_simple_container_create(lv_obj_t * parent, bool vertical, int32_t pad,
                                                    lv_flex_align_t align_cross_place);


/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_DEMO_SIMPLE_HIGH_RES*/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_DEMO_SIMPLE_HIGH_RES_PRIVATE_H*/
