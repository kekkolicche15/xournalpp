/*
 * Xournal++
 *
 * Enum definition used for tools
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>  // for string

#include "model/LineStyle.h"

enum ToolSize {
    TOOL_SIZE_VERY_FINE = 0,
    TOOL_SIZE_FINE,
    TOOL_SIZE_MEDIUM,
    TOOL_SIZE_THICK,
    TOOL_SIZE_VERY_THICK,
    // None has to be at the end, because this enum is used as memory offset
    TOOL_SIZE_NONE
};
std::string toolSizeToString(ToolSize size);
ToolSize toolSizeFromString(const std::string& size);


enum DrawingType {
    /**
     * For config entry, don't change value
     */
    DRAWING_TYPE_DONT_CHANGE = 0,

    /**
     * Default drawing, nothing special
     */
    DRAWING_TYPE_DEFAULT,
    DRAWING_TYPE_LINE,
    DRAWING_TYPE_RECTANGLE,
    DRAWING_TYPE_ELLIPSE,
    DRAWING_TYPE_ARROW,
    DRAWING_TYPE_DOUBLE_ARROW,
    DRAWING_TYPE_AGGREGATION_ARROW,
    DRAWING_TYPE_COMPOSITION_ARROW,
    DRAWING_TYPE_INHERITANCE_ARROW,
    DRAWING_TYPE_COORDINATE_SYSTEM,
    DRAWING_TYPE_SHAPE_RECOGNIZER,
    DRAWING_TYPE_SPLINE
};
std::string drawingTypeToString(DrawingType type);
DrawingType drawingTypeFromString(const std::string& type);


// Has to be in the same order as in Action.h: ActionType!
// The numbers must agree with the action's targets in ui/mainmenubar.xml
enum ToolType {
    TOOL_NONE = 0,

    // First valid tool, often used starting Index 0
    TOOL_PEN = 1,
    TOOL_ERASER = 2,
    TOOL_HIGHLIGHTER = 3,
    TOOL_TEXT = 4,
    TOOL_IMAGE = 5,
    TOOL_SELECT_RECT = 6,
    TOOL_SELECT_REGION = 7,
    TOOL_SELECT_MULTILAYER_RECT = 8,
    TOOL_SELECT_MULTILAYER_REGION = 9,
    TOOL_SELECT_OBJECT = 10,
    TOOL_PLAY_OBJECT = 11,
    TOOL_VERTICAL_SPACE = 12,
    TOOL_HAND = 13,
    TOOL_DRAW_RECT = 14,
    TOOL_DRAW_ELLIPSE = 15,
    TOOL_DRAW_ARROW = 16,
    TOOL_DRAW_DOUBLE_ARROW = 17,
    TOOL_DRAW_AGGREGATION_ARROW = 18,
    TOOL_DRAW_COMPOSITION_ARROW = 19,
    TOOL_DRAW_INHERITANCE_ARROW = 20,
    TOOL_DRAW_COORDINATE_SYSTEM = 21,
    TOOL_FLOATING_TOOLBOX = 22,
    TOOL_DRAW_SPLINE = 23,
    TOOL_SELECT_PDF_TEXT_LINEAR = 24,
    TOOL_SELECT_PDF_TEXT_RECT = 25,
    TOOL_END_ENTRY
};
auto isSelectToolType(ToolType type) -> bool;
auto isSelectToolTypeSingleLayer(ToolType type) -> bool;

/**
 * @brief Whether or not the tool needs the selection to be cleared when selected
 */
auto requiresClearedSelection(ToolType type) -> bool;

// The count of tools
#define TOOL_COUNT (TOOL_END_ENTRY - 1)

std::string toolTypeToString(ToolType type);
ToolType toolTypeFromString(const std::string& type);

enum OpacityFeature {
    OPACITY_NONE,
    OPACITY_FILL_PEN,
    OPACITY_FILL_HIGHLIGHTER,
    OPACITY_SELECT_PDF_TEXT_MARKER,
};
std::string opacityFeatureToString(OpacityFeature feature);
OpacityFeature opacityFeatureFromString(const std::string& feature);

enum EraserType { ERASER_TYPE_NONE = 0, ERASER_TYPE_DEFAULT, ERASER_TYPE_WHITEOUT, ERASER_TYPE_DELETE_STROKE };
std::string eraserTypeToString(EraserType type);
EraserType eraserTypeFromString(const std::string& type);


enum ToolCapabilities : unsigned int {
    TOOL_CAP_NONE = 0,
    TOOL_CAP_COLOR = 1 << 0,
    TOOL_CAP_SIZE = 1 << 1,
    TOOL_CAP_RULER = 1 << 2,
    TOOL_CAP_RECTANGLE = 1 << 3,
    TOOL_CAP_ELLIPSE = 1 << 4,
    TOOL_CAP_ARROW = 1 << 5,
    TOOL_CAP_DOUBLE_ARROW = 1 << 6,
    TOOL_CAP_AGGREGATION_ARROW = 1 << 7,
    TOOL_CAP_COMPOSITION_ARROW = 1 << 8,
    TOOL_CAP_INHERITANCE_ARROW = 1 << 9,
    TOOL_CAP_RECOGNIZER = 1 << 10,
    TOOL_CAP_FILL = 1 << 11,
    TOOL_CAP_COORDINATE_SYSTEM = 1 << 12,
    TOOL_CAP_DASH_LINE = 1 << 13,
    TOOL_CAP_SPLINE = 1 << 14,
    TOOL_CAP_LINE_STYLE = 1 << 15,
};

enum StrokeType {
    STROKE_TYPE_NONE = 0,
    STROKE_TYPE_STANDARD = 1,
    STROKE_TYPE_DASHED = 2,
    STROKE_TYPE_DASHDOTTED = 3,
    STROKE_TYPE_DOTTED = 4
};
auto strokeTypeFromString(const std::string& type) -> StrokeType;
auto strokeTypeToLineStyle(StrokeType type) -> LineStyle;
auto strokeTypeToString(StrokeType type) -> std::string;

namespace xoj::tool {
/// \return Whether the provided tool is used for selecting objects on a PDF.
bool isPdfSelectionTool(ToolType toolType);
}  // namespace xoj::tool
