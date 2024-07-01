#include <gtest/gtest.h>
#include "../src/game.h"

class GameTest : public ::testing::Test {
protected:
    void SetUp() override {
        game.initialize_game();
    }

    void TearDown() override {
        game.clean_game();
    }
    Game game{};
};

TEST_F(GameTest, Initialization) {
    EXPECT_EQ(game.get_turn(), 1);
    EXPECT_EQ(game.get_timer(), 0);
}
