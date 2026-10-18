#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Adds a compact progress overlay to the top-right corner during gameplay.
class $modify(OverlayStarterPlayLayer, PlayLayer) {
    CCLabelBMFont* m_overlayLabel = nullptr;

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        m_overlayLabel = CCLabelBMFont::create("OVERLAY  |  0%", "bigFont.fnt");
        if (m_overlayLabel) {
            m_overlayLabel->setScale(0.35f);
            m_overlayLabel->setAnchorPoint({1.f, 1.f});
            m_overlayLabel->setPosition({winSize.width - 12.f, winSize.height - 12.f});
            m_overlayLabel->setOpacity(210);
            m_overlayLabel->setID("overlay-starter-label");
            this->addChild(m_overlayLabel, 9999);

            this->schedule(schedule_selector(OverlayStarterPlayLayer::updateOverlay), 0.1f);
        }

        return true;
    }

    void updateOverlay(float) {
        if (!m_overlayLabel)
            return;

        auto percent = static_cast<int>(this->getCurrentPercent());
        auto text = fmt::format("OVERLAY  |  {}%", percent);
        m_overlayLabel->setString(text.c_str());
    }
};
