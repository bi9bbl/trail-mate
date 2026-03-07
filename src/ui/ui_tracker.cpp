#include "screens/tracker/tracker_page_components.h"
#include "screens/tracker/tracker_page_input.h"
#include "ui_common.h"

void ui_tracker_enter(lv_obj_t* parent)
{
    lv_group_t* prev_group = lv_group_get_default();
    set_default_group(nullptr);
    tracker::ui::components::init_page(parent);
    set_default_group(prev_group);
    tracker::ui::input::init_tracker_input();
}

void ui_tracker_exit(lv_obj_t*)
{
    tracker::ui::input::cleanup_tracker_input();
    tracker::ui::components::cleanup_page();
}
