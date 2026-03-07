/**
 * @file settings_page_input.cpp
 * @brief Settings input handling
 */

#include "settings_page_input.h"

#include "../../components/two_pane_nav.h"
#include "settings_state.h"

namespace settings
{
namespace ui
{
namespace input
{
namespace
{

using Adapter = ::ui::components::two_pane_nav::Adapter;
using BackPlacement = ::ui::components::two_pane_nav::BackPlacement;

static ::ui::components::two_pane_nav::Binding s_binding{};

static lv_obj_t* get_key_target(void* /*ctx*/)
{
    return g_state.root ? g_state.root : g_state.list_panel;
}

static lv_obj_t* get_top_back_button(void* /*ctx*/)
{
    return g_state.top_bar.back_btn;
}

static size_t get_filter_count(void* /*ctx*/)
{
    return g_state.filter_count;
}

static lv_obj_t* get_filter_button(void* /*ctx*/, size_t index)
{
    return (index < g_state.filter_count) ? g_state.filter_buttons[index] : nullptr;
}

static int get_preferred_filter_index(void* /*ctx*/)
{
    return g_state.current_category;
}

static size_t get_list_count(void* /*ctx*/)
{
    return g_state.item_count;
}

static lv_obj_t* get_list_button(void* /*ctx*/, size_t index)
{
    return (index < g_state.item_count) ? g_state.item_widgets[index].btn : nullptr;
}

static int get_preferred_list_index(void* /*ctx*/)
{
    return -1;
}

static lv_obj_t* get_list_back_button(void* /*ctx*/)
{
    return g_state.list_back_btn;
}

static Adapter make_adapter()
{
    Adapter adapter{};
    adapter.get_key_target = get_key_target;
    adapter.get_top_back_button = get_top_back_button;
    adapter.get_filter_count = get_filter_count;
    adapter.get_filter_button = get_filter_button;
    adapter.get_preferred_filter_index = get_preferred_filter_index;
    adapter.get_list_count = get_list_count;
    adapter.get_list_button = get_list_button;
    adapter.get_preferred_list_index = get_preferred_list_index;
    adapter.get_list_back_button = get_list_back_button;
    adapter.filter_top_back_placement = BackPlacement::Leading;
    return adapter;
}

} // namespace

void init()
{
    ::ui::components::two_pane_nav::init(&s_binding, make_adapter());
}

void cleanup()
{
    ::ui::components::two_pane_nav::cleanup(&s_binding);
}

void on_ui_refreshed()
{
    ::ui::components::two_pane_nav::on_ui_refreshed(&s_binding);
}

void focus_to_filter()
{
    ::ui::components::two_pane_nav::focus_filter(&s_binding);
}

void focus_to_list()
{
    ::ui::components::two_pane_nav::focus_list(&s_binding);
}

lv_group_t* get_group()
{
    return ::ui::components::two_pane_nav::get_group(&s_binding);
}

} // namespace input
} // namespace ui
} // namespace settings
