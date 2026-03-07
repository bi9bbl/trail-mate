#if !defined(ARDUINO_T_WATCH_S3)
/**
 * @file chat_message_list_layout.cpp
 * @brief Layout (structure only) for ChatMessageListScreen
 */

#include "chat_message_list_layout.h"
#include "../../components/two_pane_layout.h"
#include <Arduino.h>

namespace chat::ui::layout
{
namespace
{

constexpr int kFilterPanelWidth = 80;
constexpr int kButtonHeight = 28;
constexpr int kPanelGap = 0;

lv_obj_t* create_root(lv_obj_t* parent)
{
    return ::ui::components::two_pane_layout::create_root(parent);
}

lv_obj_t* create_content(lv_obj_t* parent)
{
    return ::ui::components::two_pane_layout::create_content_row(parent);
}

lv_obj_t* create_filter_panel(lv_obj_t* parent,
                              lv_obj_t** direct_btn,
                              lv_obj_t** broadcast_btn,
                              lv_obj_t** team_btn)
{
    ::ui::components::two_pane_layout::SidePanelSpec panel_spec;
    panel_spec.width = kFilterPanelWidth;
    panel_spec.pad_row = 3;
    panel_spec.margin_left = 0;
    panel_spec.margin_right = kPanelGap;
    lv_obj_t* panel = ::ui::components::two_pane_layout::create_side_panel(parent, panel_spec);

    lv_obj_t* direct = lv_btn_create(panel);
    lv_obj_set_size(direct, LV_PCT(100), kButtonHeight);
    ::ui::components::two_pane_layout::make_non_scrollable(direct);
    lv_obj_t* direct_label = lv_label_create(direct);
    lv_label_set_text(direct_label, "Direct");
    lv_obj_center(direct_label);

    lv_obj_t* broadcast = lv_btn_create(panel);
    lv_obj_set_size(broadcast, LV_PCT(100), kButtonHeight);
    ::ui::components::two_pane_layout::make_non_scrollable(broadcast);
    lv_obj_t* broadcast_label = lv_label_create(broadcast);
    lv_label_set_text(broadcast_label, "Broadcast");
    lv_obj_center(broadcast_label);

    lv_obj_t* team = lv_btn_create(panel);
    lv_obj_set_size(team, LV_PCT(100), kButtonHeight);
    ::ui::components::two_pane_layout::make_non_scrollable(team);
    lv_obj_t* team_label = lv_label_create(team);
    lv_label_set_text(team_label, "Team");
    lv_obj_center(team_label);
    lv_obj_add_flag(team, LV_OBJ_FLAG_HIDDEN);

    if (direct_btn) *direct_btn = direct;
    if (broadcast_btn) *broadcast_btn = broadcast;
    if (team_btn) *team_btn = team;
    return panel;
}

lv_obj_t* create_list_panel(lv_obj_t* parent)
{
    ::ui::components::two_pane_layout::MainPanelSpec panel_spec;
    panel_spec.pad_all = 3;
    panel_spec.pad_row = 3;
    panel_spec.pad_left = 5;
    panel_spec.pad_right = 5;
    panel_spec.scrollbar_mode = LV_SCROLLBAR_MODE_OFF;
    return ::ui::components::two_pane_layout::create_main_panel(parent, panel_spec);
}

} // namespace

MessageListLayout create_layout(lv_obj_t* parent)
{
    MessageListLayout w{};
    w.root = create_root(parent);
    w.content = create_content(w.root);
    w.filter_panel = create_filter_panel(w.content, &w.direct_btn, &w.broadcast_btn, &w.team_btn);
    w.list_panel = create_list_panel(w.content);
    return w;
}

MessageItemWidgets create_message_item(lv_obj_t* parent)
{
    MessageItemWidgets w{};
    w.btn = lv_btn_create(parent);
    lv_obj_set_size(w.btn, LV_PCT(100), 28);
    ::ui::components::two_pane_layout::make_non_scrollable(w.btn);

    w.name_label = lv_label_create(w.btn);
    lv_obj_align(w.name_label, LV_ALIGN_LEFT_MID, 10, 0);

    w.preview_label = lv_label_create(w.btn);
    lv_obj_align(w.preview_label, LV_ALIGN_LEFT_MID, 120, 0);
    lv_label_set_long_mode(w.preview_label, LV_LABEL_LONG_DOT);
    lv_obj_set_width(w.preview_label, 130);

    w.time_label = lv_label_create(w.btn);
    lv_obj_align(w.time_label, LV_ALIGN_RIGHT_MID, -10, 0);

    w.unread_label = lv_label_create(w.btn);
    lv_obj_align(w.unread_label, LV_ALIGN_RIGHT_MID, -42, 0);

    return w;
}

lv_obj_t* create_placeholder(lv_obj_t* parent)
{
    lv_obj_t* label = lv_label_create(parent);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    return label;
}

} // namespace chat::ui::layout

#endif
