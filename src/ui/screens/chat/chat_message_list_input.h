/**
 * @file chat_message_list_input.h
 * @brief Input handling for ChatMessageListScreen
 */

#pragma once

#include "../../components/two_pane_nav.h"

namespace chat
{
namespace ui
{

class ChatMessageListScreen;

namespace message_list
{
namespace input
{

using FocusColumn = ::ui::components::two_pane_nav::FocusColumn;
using Binding = ::ui::components::two_pane_nav::Binding;

void init(ChatMessageListScreen* screen, Binding* binding);
void cleanup(Binding* binding);
void on_ui_refreshed(Binding* binding);
void focus_filter(Binding* binding);
void focus_list(Binding* binding);

} // namespace input
} // namespace message_list
} // namespace ui
} // namespace chat
