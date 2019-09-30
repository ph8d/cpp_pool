#include "GraphicalMode.class.hpp"

void GraphicalMode::draw(StaticData staticData, DynamicData dynamicData) {
    static_cast<void>(staticData);
    static_cast<void>(dynamicData);
}

GraphicalMode & GraphicalMode::operator=(GraphicalMode const & rhs) {
    static_cast<void>(rhs);
    return *this;
}

GraphicalMode::GraphicalMode(const GraphicalMode & toCopy) {
    *this = toCopy;
}

GraphicalMode::GraphicalMode(void) {}
GraphicalMode::~GraphicalMode(void) {}