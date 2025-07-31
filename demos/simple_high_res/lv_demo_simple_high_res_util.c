/**
 * @file lv_demo_simple_high_res_util.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_demo_simple_high_res_private.h"
#if LV_USE_DEMO_SIMPLE_HIGH_RES

#include "../../src/widgets/image/lv_image.h"
#include "../../src/widgets/canvas/lv_canvas.h"
#include "../../src/widgets/label/lv_label.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_12)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_16)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_24)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_30)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_36)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_60)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_light_120)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_light_160)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_regular_30)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_regular_60)

LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_regular_20)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_regular_40)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_regular_45)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_regular_90)

LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_light_80)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_light_107)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_light_180)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_light_240)

LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_8)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_11)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_18)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_medium_36)

LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_20)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_24)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_40)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_45)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_54)
LV_FONT_DECLARE(font_lv_demo_simple_high_res_roboto_slab_bold_90)

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void init_fonts_sm(lv_style_t * fonts);
static void init_fonts_md(lv_style_t * fonts);
static void init_fonts_lg(lv_style_t * fonts);
static void theme_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
static void free_ctx_event_cb(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_demo_simple_high_res_theme_t lv_demo_simple_high_res_theme_light = {
    .base = LV_COLOR_MAKE(0xff, 0xff, 0xff),
    .accent = LV_COLOR_MAKE(0xff, 0xff, 0xff),
};

const lv_demo_simple_high_res_theme_t lv_demo_simple_high_res_theme_dark = {
    .base = LV_COLOR_MAKE(0x00, 0x00, 0x00),
    .accent = LV_COLOR_MAKE(0xe1, 0x2b, 0x17),
};

const lv_demo_simple_high_res_sizes_t lv_demo_simple_high_res_sizes_all[SIZE_COUNT] = {
    {
        .gap = {0, 2, 4, 6, 9, 12, 14, 16, 20, 24, 32},
        .icon = {16, 21, 32, 42, 64},
        .card_long_edge = 200,
        .widget_long_edge = 256,
        .card_short_edge = 120,
        .smart_home_arc_diameter = 107,
        .ev_charging_arc_diameter = 160,
        .smart_meter_collapsed_part_height = 48,
        .slider_width = 27,
        .small_chart_height = 67,
        .large_chart_height = 167,
        .card_radius = 12,
        .health_panel_width = 133,
        .settings_panel_width = 179,
        .home_bottom_margin_height = 53,
        .indicator_width = 94,
        .indicator_height = 85,
        .init_fonts_cb = init_fonts_sm
    },
    {
        .gap = {0, 3, 6, 9, 12, 16, 20, 24, 30, 36, 48},
        .icon = {24, 32, 48, 64, 96},
        .card_long_edge = 300,
        .widget_long_edge = 384,
        .card_short_edge = 180,
        .smart_home_arc_diameter = 160,
        .ev_charging_arc_diameter = 240,
        .smart_meter_collapsed_part_height = 72,
        .slider_width = 40,
        .small_chart_height = 100,
        .large_chart_height = 250,
        .card_radius = 18,
        .health_panel_width = 200,
        .settings_panel_width = 268,
        .home_bottom_margin_height = 80,
        .indicator_width = 141,
        .indicator_height = 128,
        .init_fonts_cb = init_fonts_md
    },
    {
        .gap = {0, 5, 10, 15, 18, 24, 30, 36, 45, 54, 72},
        .icon = {36, 48, 72, 96, 144},
        .card_long_edge = 450,
        .widget_long_edge = 576,
        .card_short_edge = 270,
        .smart_home_arc_diameter = 240,
        .ev_charging_arc_diameter = 360,
        .smart_meter_collapsed_part_height = 108,
        .slider_width = 60,
        .small_chart_height = 150,
        .large_chart_height = 375,
        .card_radius = 27,
        .health_panel_width = 300,
        .settings_panel_width = 402,
        .home_bottom_margin_height = 120,
        .indicator_width = 212,
        .indicator_height = 192,
        .init_fonts_cb = init_fonts_lg
    }
};

/**********************
 *      MACROS
 **********************/

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(*arr))

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_demo_simple_high_res_base_obj_create(const char * logo_path,
                                            lv_demo_simple_high_res_exit_cb_t exit_cb)
{
    lv_demo_simple_high_res_ctx_t * c = lv_malloc_zeroed(sizeof(lv_demo_simple_high_res_ctx_t));
    LV_ASSERT_MALLOC(c);
    lv_obj_t * base_obj = lv_obj_create(lv_screen_active());
    lv_obj_set_user_data(base_obj, c);
    lv_obj_add_event_cb(base_obj, free_ctx_event_cb, LV_EVENT_DELETE, NULL);

    lv_display_t * disp = lv_display_get_default();
    int32_t hres = lv_display_get_horizontal_resolution(disp);
    int32_t vres = lv_display_get_vertical_resolution(disp);
    bool is_exact;
    int32_t size;
    if(hres < 1280 && vres < 720) {
        is_exact = hres == 800 && vres == 480;
        size = SIZE_SM;
    }
    else if(hres < 1920 && vres < 1080) {
        is_exact = hres == 1280 && vres == 720;
        size = SIZE_MD;
    }
    else {
        is_exact = hres == 1920 && vres == 1080;
        size = SIZE_LG;
    }
    if(!is_exact) {
        LV_LOG_WARN("a display size of exactly 800x480, 1280x720, or 1920x1080 is recommended for the high-res demo");
    }
    c->sz = &lv_demo_simple_high_res_sizes_all[size];

    for(uint32_t i = 0; i < STYLE_COLOR_COUNT; i++) {
        for(uint32_t j = 0; j < STYLE_TYPE_COUNT; j++) {
            lv_style_init(&c->styles[i][j]);
        }
    }

    for(uint32_t i = 0; i < FONT_COUNT; i++) {
        lv_style_init(&c->fonts[i]);
    }
    c->sz->init_fonts_cb(c->fonts);

    lv_subject_init_pointer(&c->th, (void *)&lv_demo_simple_high_res_theme_dark);
    c->th.user_data = c;
    lv_subject_add_observer(&c->th, theme_observer_cb, c);

    c->logo_path = lv_strdup(logo_path);
    LV_ASSERT_MALLOC(c->logo_path);

    c->exit_cb = exit_cb;

    /* API subjects */

    /* input subjects */
    lv_subject_init_int(&c->api.subjects.hour, 9);
    lv_subject_init_int(&c->api.subjects.minute, 36);

    c->api.base_obj = base_obj;
    c->api.user_data = NULL;

    c->subject_groups.time.members[0] = &c->api.subjects.hour;
    c->subject_groups.time.members[1] = &c->api.subjects.minute;
    lv_subject_init_group(&c->subject_groups.time.group, c->subject_groups.time.members,
                          ARRAY_LEN(c->subject_groups.time.members));
    
    return base_obj;
}

lv_obj_t * lv_demo_simple_high_res_simple_container_create(lv_obj_t * parent, bool vertical, int32_t pad,
                                                    lv_flex_align_t align_cross_place)
{
    lv_obj_t * obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    if(vertical) {
        lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(obj, pad, 0);
    }
    else {
        lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_column(obj, pad, 0);
    }
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, align_cross_place, align_cross_place);
    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void init_fonts_sm(lv_style_t * fonts)
{
    lv_style_set_text_font(&fonts[FONT_HEADING_MD], &font_lv_demo_simple_high_res_roboto_slab_regular_20);
    lv_style_set_text_font(&fonts[FONT_HEADING_LG], &font_lv_demo_simple_high_res_roboto_slab_regular_40);
    lv_style_set_text_font(&fonts[FONT_HEADING_XL], &font_lv_demo_simple_high_res_roboto_slab_light_80);
    lv_style_set_text_font(&fonts[FONT_HEADING_XXL], &font_lv_demo_simple_high_res_roboto_slab_light_107);
    lv_style_set_text_font(&fonts[FONT_LABEL_XS], &font_lv_demo_simple_high_res_roboto_medium_8);
    lv_style_set_text_line_space(&fonts[FONT_LABEL_XS],
                                 30 * lv_font_get_line_height(&font_lv_demo_simple_high_res_roboto_medium_8) / 100); /* +30% */
    /* lv_style_set_text_letter_space(&fonts[FONT_LABEL_XS], 197 * lv_font_get_letter_space(&font_lv_demo_simple_high_res_roboto_medium_8) / 200); */ /* -1.5% */
    lv_style_set_text_font(&fonts[FONT_LABEL_SM], &font_lv_demo_simple_high_res_roboto_medium_11);
    lv_style_set_text_font(&fonts[FONT_LABEL_MD], &font_lv_demo_simple_high_res_roboto_medium_16);
    lv_style_set_text_font(&fonts[FONT_LABEL_LG], &font_lv_demo_simple_high_res_roboto_slab_bold_20);
    lv_style_set_text_font(&fonts[FONT_LABEL_XL], &font_lv_demo_simple_high_res_roboto_slab_bold_24);
    lv_style_set_text_font(&fonts[FONT_LABEL_2XL], &font_lv_demo_simple_high_res_roboto_slab_bold_40);
}

static void init_fonts_md(lv_style_t * fonts)
{
    lv_style_set_text_font(&fonts[FONT_HEADING_MD], &font_lv_demo_simple_high_res_roboto_slab_regular_30);
    lv_style_set_text_font(&fonts[FONT_HEADING_LG], &font_lv_demo_simple_high_res_roboto_slab_regular_60);
    lv_style_set_text_font(&fonts[FONT_HEADING_XL], &font_lv_demo_simple_high_res_roboto_slab_light_120);
    lv_style_set_text_font(&fonts[FONT_HEADING_XXL], &font_lv_demo_simple_high_res_roboto_slab_light_160);
    lv_style_set_text_font(&fonts[FONT_LABEL_XS], &font_lv_demo_simple_high_res_roboto_medium_12);
    lv_style_set_text_line_space(&fonts[FONT_LABEL_XS],
                                 30 * lv_font_get_line_height(&font_lv_demo_simple_high_res_roboto_medium_12) / 100); /* +30% */
    /* lv_style_set_text_letter_space(&fonts[FONT_LABEL_XS], 197 * lv_font_get_letter_space(&font_lv_demo_simple_high_res_roboto_medium_12) / 200); */ /* -1.5% */
    lv_style_set_text_font(&fonts[FONT_LABEL_SM], &font_lv_demo_simple_high_res_roboto_medium_16);
    lv_style_set_text_font(&fonts[FONT_LABEL_MD], &font_lv_demo_simple_high_res_roboto_medium_24);
    lv_style_set_text_font(&fonts[FONT_LABEL_LG], &font_lv_demo_simple_high_res_roboto_slab_bold_30);
    lv_style_set_text_font(&fonts[FONT_LABEL_XL], &font_lv_demo_simple_high_res_roboto_slab_bold_36);
    lv_style_set_text_font(&fonts[FONT_LABEL_2XL], &font_lv_demo_simple_high_res_roboto_slab_bold_60);
}

static void init_fonts_lg(lv_style_t * fonts)
{
    lv_style_set_text_font(&fonts[FONT_HEADING_MD], &font_lv_demo_simple_high_res_roboto_slab_regular_45);
    lv_style_set_text_font(&fonts[FONT_HEADING_LG], &font_lv_demo_simple_high_res_roboto_slab_regular_90);
    lv_style_set_text_font(&fonts[FONT_HEADING_XL], &font_lv_demo_simple_high_res_roboto_slab_light_180);
    lv_style_set_text_font(&fonts[FONT_HEADING_XXL], &font_lv_demo_simple_high_res_roboto_slab_light_240);
    lv_style_set_text_font(&fonts[FONT_LABEL_XS], &font_lv_demo_simple_high_res_roboto_medium_18);
    lv_style_set_text_line_space(&fonts[FONT_LABEL_XS],
                                 30 * lv_font_get_line_height(&font_lv_demo_simple_high_res_roboto_medium_18) / 100); /* +30% */
    /* lv_style_set_text_letter_space(&fonts[FONT_LABEL_XS], 197 * lv_font_get_letter_space(&font_lv_demo_simple_high_res_roboto_medium_18) / 200); */ /* -1.5% */
    lv_style_set_text_font(&fonts[FONT_LABEL_SM], &font_lv_demo_simple_high_res_roboto_medium_24);
    lv_style_set_text_font(&fonts[FONT_LABEL_MD], &font_lv_demo_simple_high_res_roboto_medium_36);
    lv_style_set_text_font(&fonts[FONT_LABEL_LG], &font_lv_demo_simple_high_res_roboto_slab_bold_45);
    lv_style_set_text_font(&fonts[FONT_LABEL_XL], &font_lv_demo_simple_high_res_roboto_slab_bold_54);
    lv_style_set_text_font(&fonts[FONT_LABEL_2XL], &font_lv_demo_simple_high_res_roboto_slab_bold_90);
}

static void theme_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    const lv_demo_simple_high_res_theme_t * th = lv_subject_get_pointer(subject);
    const lv_demo_simple_high_res_theme_t * th_other = th == &lv_demo_simple_high_res_theme_light ? &lv_demo_simple_high_res_theme_dark :
                                                &lv_demo_simple_high_res_theme_light;
    lv_demo_simple_high_res_ctx_t * c = lv_observer_get_user_data(observer);

    for(uint32_t i = 0; i < STYLE_COLOR_COUNT; i++) {
        lv_color_t color = i == STYLE_COLOR_BASE ? th->base : th->accent;
        lv_color_t color_inv = i == STYLE_COLOR_ACCENT ? th->accent : th_other->base;

        lv_style_set_bg_color(&c->styles[i][STYLE_TYPE_OBJ], color);
        lv_style_set_outline_color(&c->styles[i][STYLE_TYPE_OBJ], color);

        lv_style_set_text_color(&c->styles[i][STYLE_TYPE_TEXT], color_inv);
        lv_style_set_line_color(&c->styles[i][STYLE_TYPE_TEXT], color_inv);

        lv_style_set_image_recolor_opa(&c->styles[i][STYLE_TYPE_A8_IMG], LV_OPA_COVER);
        lv_style_set_image_recolor(&c->styles[i][STYLE_TYPE_A8_IMG], color_inv);
    }

    for(uint32_t i = 0; i < STYLE_COLOR_COUNT; i++) {
        for(uint32_t j = 0; j < STYLE_TYPE_COUNT; j++) {
            lv_obj_report_style_change(&c->styles[i][j]);
        }
    }
}

static void free_ctx_event_cb(lv_event_t * e)
{
    lv_obj_t * base_obj = lv_event_get_target_obj(e);
    lv_demo_simple_high_res_ctx_t * c = lv_obj_get_user_data(base_obj);

    lv_subject_deinit(&c->th);

    for(uint32_t i = 0; i < STYLE_COLOR_COUNT; i++) {
        for(uint32_t j = 0; j < STYLE_TYPE_COUNT; j++) {
            lv_style_reset(&c->styles[i][j]);
        }
    }

    for(uint32_t i = 0; i < FONT_COUNT; i++) {
        lv_style_reset(&c->fonts[i]);
    }

    lv_free(c->logo_path);

    lv_subject_deinit(&c->subject_groups.time.group);

    lv_subject_t * subjects = (lv_subject_t *) &c->api.subjects;
    for(uint32_t i = 0; i < sizeof(c->api.subjects) / sizeof(lv_subject_t); i++) {
        lv_subject_deinit(&subjects[i]);
    }

    lv_free(c);

    lv_obj_set_user_data(base_obj, NULL);
}
#endif /*LV_USE_DEMO_SIMPLE_HIGH_RES*/
