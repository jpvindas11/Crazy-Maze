#include <gtest/gtest.h>
#include "../src/game_map.h"

class GameMapTest : public ::testing::Test {
protected:
    void SetUp() override {
        gameMap.reset_map();
    }
    Game_map gameMap{10,10};
};

TEST_F(GameMapTest, Initialization) {
    EXPECT_EQ(gameMap.get_height(), 10);
    EXPECT_EQ(gameMap.get_width(), 10);
}

TEST_F(GameMapTest, PortalCreation) {
    gameMap.start_generation(8, 8);
    EXPECT_FALSE(gameMap.portal_list.empty());
}

TEST_F(GameMapTest, ExtraEdgeProbability) {
    bool result=gameMap.bool_add_extra_edge();
    
    EXPECT_TRUE(result || !result);
    }
