/**
 * @file lv_demo_simple_high_res_home.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_demo_simple_high_res_private.h"
#if LV_USE_DEMO_SIMPLE_HIGH_RES

#include "../../src/widgets/image/lv_image.h"
#include "../../src/widgets/label/lv_label.h"
#include "../../src/widgets/span/lv_span_private.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef void (*app_cb_t)(lv_obj_t * base_obj);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void theme_observer_accent_span_cb(lv_observer_t * observer, lv_subject_t * subject);
static void time_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
static void hi_lo_observer_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_demo_simple_high_res_home(lv_obj_t * base_obj)
{
    lv_demo_simple_high_res_ctx_t * c = lv_obj_get_user_data(base_obj);

    /* background */

    lv_obj_t * bg = base_obj;
    lv_obj_remove_style_all(bg);
    lv_obj_set_size(bg, LV_PCT(100), LV_PCT(100));

    lv_obj_t * bg_cont = lv_obj_create(bg);
    lv_obj_remove_style_all(bg_cont);
    lv_obj_set_size(bg_cont, LV_PCT(100), LV_PCT(100));
    lv_obj_set_flex_flow(bg_cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_top(bg_cont, c->sz->gap[7], 0);

    /* top margin */
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x000000), LV_PART_MAIN);

    /* info area */

    lv_obj_t * info_area = lv_obj_create(bg_cont);
    lv_obj_remove_style_all(info_area);
    lv_obj_set_width(info_area, LV_PCT(100));
    lv_obj_set_flex_grow(info_area, 1);
    lv_obj_set_flex_flow(info_area, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(info_area, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t * date_and_time = lv_demo_simple_high_res_simple_container_create(info_area, true, c->sz->gap[4],
                                                                        LV_FLEX_ALIGN_CENTER);

    lv_obj_t * time = lv_spangroup_create(date_and_time);
    lv_obj_add_style(time, &c->fonts[FONT_HEADING_XXL], 0);
    lv_obj_add_style(time, &c->styles[STYLE_COLOR_BASE][STYLE_TYPE_TEXT], 0);
    lv_spangroup_new_span(time);
    lv_span_t * minute = lv_spangroup_new_span(time);
    lv_subject_add_observer_obj(&c->th, theme_observer_accent_span_cb, time, minute);
    lv_subject_add_observer_obj(&c->subject_groups.time.group, time_observer_cb, time, c);

    lv_obj_t * logo = lv_image_create(info_area);
    lv_obj_set_height(logo, c->sz->icon[1]);
    lv_image_set_src(logo, c->logo_path);
    int32_t scale = lv_image_get_scale_y(logo) * 5/4;
    lv_image_set_inner_align(logo, LV_IMAGE_ALIGN_CENTER);
    lv_image_set_scale(logo, scale);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void theme_observer_accent_span_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    lv_span_t * span = lv_observer_get_user_data(observer);
    const lv_demo_simple_high_res_theme_t * th = lv_subject_get_pointer(subject);
    lv_color_t accent = lv_color_hex(0xFFFFFF);
    
    lv_style_set_text_color(&span->style, accent);
}

static void time_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * spangroup = lv_observer_get_target_obj(observer);
    lv_demo_simple_high_res_ctx_t * c = lv_observer_get_user_data(observer);

    char buf[16];

    lv_snprintf(buf, sizeof(buf), "%02"LV_PRId32, lv_subject_get_int(&c->api.subjects.hour));
    lv_span_set_text(lv_spangroup_get_child(spangroup, 0), buf);

    lv_snprintf(buf, sizeof(buf), ":%02"LV_PRId32, lv_subject_get_int(&c->api.subjects.minute));
    lv_span_set_text(lv_spangroup_get_child(spangroup, 1), buf);
}

#endif /*LV_USE_DEMO_SIMPLE_HIGH_RES*/
