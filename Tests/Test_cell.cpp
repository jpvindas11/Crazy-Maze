#include <gtest/gtest.h>
#include "../src/cell.h"

TEST(CellTest, DefaultConstructor) {
    Cell cell;
    EXPECT_TRUE(cell.hasTopWall());
    EXPECT_TRUE(cell.hasBottomWall());
    EXPECT_TRUE(cell.hasRightWall());
    EXPECT_TRUE(cell.hasLeftWall());
    EXPECT_FALSE(cell.isVisited());
    EXPECT_FALSE(cell.getPortal());
    EXPECT_FALSE(cell.get_double_play());
    EXPECT_FALSE(cell.getControlEnemy());
    EXPECT_FALSE(cell.getJumpWall());
    EXPECT_FALSE(cell.get_treasure());
    EXPECT_TRUE(cell.isEmpty());
}

TEST(CellTest, SetAndGetMethods) {
    Cell cell;
    cell.setTopWall(false);
    cell.setBottomWall(false);
    cell.setRightWall(false);
    cell.setLeftWall(false);
    cell.setVisited(true);
    cell.setPortal(true);
    cell.set_double_play(true);
    cell.set_control_enemy(true);
    cell.set_jump_wall(true);
    cell.set_treasure(true);

    EXPECT_FALSE(cell.hasTopWall());
    EXPECT_FALSE(cell.hasBottomWall());
    EXPECT_FALSE(cell.hasRightWall());
    EXPECT_FALSE(cell.hasLeftWall());
    EXPECT_TRUE(cell.isVisited());
    EXPECT_TRUE(cell.getPortal());
    EXPECT_TRUE(cell.get_double_play());
    EXPECT_TRUE(cell.getControlEnemy());
    EXPECT_TRUE(cell.getJumpWall());
    EXPECT_TRUE(cell.get_treasure());
    EXPECT_FALSE(cell.isEmpty());
}

TEST(CellTest, CleanCell) {
    Cell cell;
    cell.setPortal(true);
    cell.set_double_play(true);
    cell.set_control_enemy(true);
    cell.set_jump_wall(true);
    cell.set_treasure(true);
    
    cell.clean_cell();
    
    EXPECT_FALSE(cell.getPortal());
    EXPECT_FALSE(cell.get_double_play());
    EXPECT_FALSE(cell.getControlEnemy());
    EXPECT_FALSE(cell.getJumpWall());
    EXPECT_FALSE(cell.get_treasure());
    EXPECT_TRUE(cell.isEmpty());
}

TEST(CellTest, UpdatePowers) {
    Cell cell;
    cell.update_Powers(10, 10);
    EXPECT_FALSE(cell.isEmpty()); // Podría fallar si no se establece ningún poder
}