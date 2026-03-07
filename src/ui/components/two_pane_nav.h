#pragma once

#include "lvgl.h"
#include <cstddef>
#include <cstdint>

namespace ui
{
namespace components
{
namespace two_pane_nav
{

enum class FocusColumn : uint8_t
{
    Filter = 0,
    List = 1,
};

enum class BackPlacement : uint8_t
{
    None = 0,
    Leading,
    Trailing,
};

struct Adapter
{
    void* ctx = nullptr;
    bool (*is_alive)(void* ctx) = nullptr;
    lv_obj_t* (*get_key_target)(void* ctx) = nullptr;
    lv_obj_t* (*get_top_back_button)(void* ctx) = nullptr;

    size_t (*get_filter_count)(void* ctx) = nullptr;
    lv_obj_t* (*get_filter_button)(void* ctx, size_t index) = nullptr;
    int (*get_preferred_filter_index)(void* ctx) = nullptr;

    size_t (*get_list_count)(void* ctx) = nullptr;
    lv_obj_t* (*get_list_button)(void* ctx, size_t index) = nullptr;
    int (*get_preferred_list_index)(void* ctx) = nullptr;
    lv_obj_t* (*get_list_back_button)(void* ctx) = nullptr;

    bool (*handle_list_enter)(void* ctx, lv_obj_t* focused) = nullptr;
    void (*on_column_changed)(void* ctx, FocusColumn column) = nullptr;

    BackPlacement filter_top_back_placement = BackPlacement::Leading;
    BackPlacement list_top_back_placement = BackPlacement::None;
};

struct Binding
{
    Adapter adapter{};
    lv_group_t* group = nullptr;
    lv_group_t* prev_group = nullptr;
    lv_indev_t* encoder = nullptr;
    FocusColumn column = FocusColumn::Filter;
    bool bound = false;
};

void init(Binding* binding, const Adapter& adapter);
void cleanup(Binding* binding);
void on_ui_refreshed(Binding* binding);
void focus_filter(Binding* binding);
void focus_list(Binding* binding);
lv_group_t* get_group(const Binding* binding);

} // namespace two_pane_nav
} // namespace components
} // namespace ui
