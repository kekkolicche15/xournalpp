/*
 * Xournal++
 *
 * Handles input to draw an arrow
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <vector>  // for vector

#include "model/PageRef.h"  // for PageRef

#include "BaseShapeHandler.h"  // for BaseShapeHandler

class Point;
class Control;

class ArrowHandler: public BaseShapeHandler {
public:
    enum Type { NORMAL, DOUBLE, AGGREGATION, COMPOSITION, INHERITANCE };
    ArrowHandler(Control* control, const PageRef& page, ArrowHandler::Type arrowType);
    ~ArrowHandler() override;

private:
    auto createShape(bool isAltDown, bool isShiftDown, bool isControlDown)
            -> std::pair<std::vector<Point>, Range> override;
    Type arrowType = NORMAL;
};
