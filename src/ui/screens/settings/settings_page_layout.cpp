/**
 * @file settings_page_layout.cpp
 * @brief Settings layout implementation
 */

#include "settings_page_layout.h"
#include "../../components/two_pane_layout.h"
#include "../../ui_common.h"
#include "settings_page_styles.h"
#include "settings_state.h"

namespace settings::ui::layout
{

// Keep filter column just wide enough for the longest category label ("Advanced").
static constexpr int kFilterPanelWidth = 92;
static constexpr int kTopBarContentGap = 3;

lv_obj_t* create_root(lv_obj_t* parent)
{
    ::ui::components::two_pane_layout::RootSpec spec;
    spec.pad_row = kTopBarContentGap;
    return ::ui::components::two_pane_layout::create_root(parent, spec);
}

lv_obj_t* create_header(lv_obj_t* root, void (*back_callback)(void*), void* user_data)
{
    ::ui::components::two_pane_layout::HeaderSpec header_spec;
    header_spec.height = ::ui::widgets::kTopBarHeight;
    header_spec.bg_hex = ::ui::components::two_pane_styles::kSidePanelBg;
    header_spec.pad_all = 0;
    lv_obj_t* header = ::ui::components::two_pane_layout::create_header_container(root, header_spec);

    ::ui::widgets::TopBarConfig cfg;
    cfg.height = ::ui::widgets::kTopBarHeight;
    ::ui::widgets::top_bar_init(g_state.top_bar, header, cfg);
    ::ui::widgets::top_bar_set_title(g_state.top_bar, "Settings");
    ::ui::widgets::top_bar_set_back_callback(g_state.top_bar, back_callback, user_data);
    ui_update_top_bar_battery(g_state.top_bar);
    return header;
}

lv_obj_t* create_content(lv_obj_t* root)
{
    return ::ui::components::two_pane_layout::create_content_row(root);
}

void create_filter_panel(lv_obj_t* parent)
{
    ::ui::components::two_pane_layout::SidePanelSpec panel_spec;
    panel_spec.width = kFilterPanelWidth;
    panel_spec.pad_row = 2;
    panel_spec.margin_left = 0;
    panel_spec.margin_right = 0;
    g_state.filter_panel = ::ui::components::two_pane_layout::create_side_panel(parent, panel_spec);
    style::apply_panel_side(g_state.filter_panel);
    lv_obj_set_style_pad_right(g_state.filter_panel, 1, LV_PART_MAIN);
}

void create_list_panel(lv_obj_t* parent)
{
    ::ui::components::two_pane_layout::MainPanelSpec panel_spec;
    panel_spec.pad_all = 0;
    panel_spec.pad_row = 6;
    panel_spec.pad_left = 1;
    panel_spec.pad_right = 2;
    panel_spec.margin_left = 0;
    panel_spec.margin_right = 0;
    panel_spec.margin_bottom = 3;
    panel_spec.scrollbar_mode = LV_SCROLLBAR_MODE_AUTO;
    g_state.list_panel = ::ui::components::two_pane_layout::create_main_panel(parent, panel_spec);
    style::apply_panel_main(g_state.list_panel);
}

} // namespace settings::ui::layout
