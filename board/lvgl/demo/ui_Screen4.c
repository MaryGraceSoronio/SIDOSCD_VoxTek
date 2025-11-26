#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "global_vars.h"
#include <stdbool.h>

lv_obj_t * ui_Screen4 = NULL;
lv_obj_t * ui_Image4 = NULL;
lv_obj_t * ui_mainDashboardMan = NULL;
lv_obj_t * ui_startOpMan = NULL;
lv_obj_t * ui_doorStatusMan = NULL;
lv_obj_t * ui_ovenStatusMan = NULL;
lv_obj_t * ui_potenTemp = NULL;
lv_obj_t * ui_potentTime = NULL;
lv_obj_t * ui_tempDis = NULL;
lv_obj_t * ui_timeDis = NULL;
lv_obj_t * ui_tempDisLabel = NULL;
lv_obj_t * ui_timeDisLabel = NULL;

// -- EVENT CALLBACKS --
void ui_event_mainDashboardMan(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
        _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Screen2_screen_init);
}

void ui_event_potenTemp(lv_event_t * e)
{
    int value = lv_arc_get_value(ui_potenTemp);
    char buf[16];
    sprintf(buf, "%d", value);
    lv_label_set_text(ui_tempDisLabel, buf);
    potenTempValue = value; // Store for transfer to screen 2
}

void ui_event_potentTime(lv_event_t * e)
{
    int value = lv_arc_get_value(ui_potentTime);
    char buf[16];
    sprintf(buf, "%d", value);
    lv_label_set_text(ui_timeDisLabel, buf);
    potenTimeValue = value; // Store for transfer to screen 2
}

void ui_event_startOpMan(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {

            // --- MODIFIED LOGIC: READ STRING FROM LABELS AND CONVERT TO INT ---
            // Read value from timeDisLabel (string to int conversion)
            const char *time_str = lv_label_get_text(ui_timeDisLabel);
            potenTimeValue = atoi(time_str);

            // Read value from tempDisLabel (string to int conversion)
            const char *temp_str = lv_label_get_text(ui_tempDisLabel);
            potenTempValue = atoi(temp_str);

            ui_Screen2_update_manual = true;
            _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_TOP, 500, 0, &ui_Screen2_screen_init);
        }
}

// -- BUILD FUNCTIONS --
void ui_Screen4_screen_init(void)
{
    ui_Screen4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen4, LV_OBJ_FLAG_SCROLLABLE);

    ui_Image4 = lv_img_create(ui_Screen4);
    lv_img_set_src(ui_Image4, &ui_img_1694767418);
    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 480
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 272
    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);

    ui_mainDashboardMan = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_mainDashboardMan, 109);
    lv_obj_set_height(ui_mainDashboardMan, 27);
    lv_obj_set_x(ui_mainDashboardMan, -40);
    lv_obj_set_y(ui_mainDashboardMan, -110);
    lv_obj_set_align(ui_mainDashboardMan, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_mainDashboardMan, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_mainDashboardMan, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_opa(ui_mainDashboardMan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_mainDashboardMan, ui_event_mainDashboardMan, LV_EVENT_ALL, NULL);

    ui_startOpMan = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_startOpMan, 109);
    lv_obj_set_height(ui_startOpMan, 27);
    lv_obj_set_x(ui_startOpMan, 57);
    lv_obj_set_y(ui_startOpMan, 107);
    lv_obj_set_align(ui_startOpMan, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_startOpMan, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_startOpMan, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_opa(ui_startOpMan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_startOpMan, ui_event_startOpMan, LV_EVENT_ALL, NULL);

    ui_doorStatusMan = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_doorStatusMan, 79);
    lv_obj_set_height(ui_doorStatusMan, 19);
    lv_obj_set_x(ui_doorStatusMan, -168);
    lv_obj_set_y(ui_doorStatusMan, 56);
    lv_obj_set_align(ui_doorStatusMan, LV_ALIGN_CENTER);
    lv_label_set_text(ui_doorStatusMan, "Unlocked");

    ui_ovenStatusMan = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_ovenStatusMan, 79);
    lv_obj_set_height(ui_ovenStatusMan, 19);
    lv_obj_set_x(ui_ovenStatusMan, -167);
    lv_obj_set_y(ui_ovenStatusMan, 83);
    lv_obj_set_align(ui_ovenStatusMan, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ovenStatusMan, "Safe");

    ui_potenTemp = lv_arc_create(ui_Screen4);
    lv_obj_set_width(ui_potenTemp, 90);
    lv_obj_set_height(ui_potenTemp, 90);
    lv_obj_set_x(ui_potenTemp, -12);
    lv_obj_set_y(ui_potenTemp, 26);
    lv_obj_set_align(ui_potenTemp, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_potenTemp, 0, 200);
    lv_arc_set_value(ui_potenTemp, 0);
    lv_obj_add_event_cb(ui_potenTemp, ui_event_potenTemp, LV_EVENT_VALUE_CHANGED, NULL);

    ui_potentTime = lv_arc_create(ui_Screen4);
    lv_obj_set_width(ui_potentTime, 90);
    lv_obj_set_height(ui_potentTime, 90);
    lv_obj_set_x(ui_potentTime, 132);
    lv_obj_set_y(ui_potentTime, 25);
    lv_obj_set_align(ui_potentTime, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_potentTime, 0, 12);
    lv_arc_set_value(ui_potentTime, 0);
    lv_obj_add_event_cb(ui_potentTime, ui_event_potentTime, LV_EVENT_VALUE_CHANGED, NULL);

    ui_tempDis = lv_obj_create(ui_Screen4);
    lv_obj_remove_style_all(ui_tempDis);
    lv_obj_set_width(ui_tempDis, 50);
    lv_obj_set_height(ui_tempDis, 30);
    lv_obj_set_x(ui_tempDis, -33);
    lv_obj_set_y(ui_tempDis, -59);
    lv_obj_set_align(ui_tempDis, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_tempDis, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_tempDis, lv_color_hex(0x0C71A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_tempDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_timeDis = lv_obj_create(ui_Screen4);
    lv_obj_remove_style_all(ui_timeDis);
    lv_obj_set_width(ui_timeDis, 50);
    lv_obj_set_height(ui_timeDis, 30);
    lv_obj_set_x(ui_timeDis, 167);
    lv_obj_set_y(ui_timeDis, -58);
    lv_obj_set_align(ui_timeDis, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_timeDis, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_timeDis, lv_color_hex(0x0C71A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_timeDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempDisLabel = lv_label_create(ui_tempDis);
    lv_obj_set_width(ui_tempDisLabel, 40);
    lv_obj_set_height(ui_tempDisLabel, 20);
    lv_obj_set_align(ui_tempDisLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_tempDisLabel, "0");

    ui_timeDisLabel = lv_label_create(ui_timeDis);
    lv_obj_set_width(ui_timeDisLabel, 40);
    lv_obj_set_height(ui_timeDisLabel, 20);
    lv_obj_set_align(ui_timeDisLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_timeDisLabel, "0");
}

void ui_Screen4_screen_destroy(void)
{
    if(ui_Screen4) lv_obj_del(ui_Screen4);

    ui_Screen4 = NULL;
    ui_Image4 = NULL;
    ui_mainDashboardMan = NULL;
    ui_startOpMan = NULL;
    ui_doorStatusMan = NULL;
    ui_ovenStatusMan = NULL;
    ui_potenTemp = NULL;
    ui_potentTime = NULL;
    ui_tempDis = NULL;
    ui_timeDis = NULL;
    ui_tempDisLabel = NULL;
    ui_timeDisLabel = NULL;
}
