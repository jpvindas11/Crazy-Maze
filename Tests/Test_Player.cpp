#include <gtest/gtest.h>
#include "../src/player.h"
#include "../src/game_map.h"

// Test fixture para reutilizar objetos Player y Game_map en varios casos de prueba
class PlayerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Configurar objetos comunes o inicializar aquí si es necesario
        gameMap.reset_map();  // Limpiar el mapa antes de cada prueba
    }

    void TearDown() override {
        // Realizar limpieza después de cada prueba si es necesario
    }

    // Miembros compartidos por todas las pruebas
    Game_map gameMap{10, 10};  // Crear un mapa de 10x10
    Player player{10, 10};     // Crear un jugador en un mapa de 10x10
};

TEST_F(PlayerTest, InitialPosition) {
    // Verificar que el jugador esté inicialmente dentro de los límites del mapa
    EXPECT_GE(player.get_x(), 0);
    EXPECT_LT(player.get_x(), 10);
    EXPECT_GE(player.get_y(), 0);
    EXPECT_LT(player.get_y(), 10);
}

TEST_F(PlayerTest, Movement) {
    // Prueba de movimiento hacia arriba ('w')
    player.handle_movement('w', gameMap);
    EXPECT_EQ(player.get_y(), gameMap.get_height() - 1);  // Debería moverse a la fila superior

    // Añade más pruebas de movimiento para otros casos
}

TEST_F(PlayerTest, PowerUpCollection) {
    Cell& cell = gameMap.get_map_index(2, 2);
    cell.set_treasure(true);
    player.collect_powers(cell);

    // Verificar que el jugador haya recolectado el tesoro
    EXPECT_TRUE(player.get_treasure());

    // Añade más pruebas para otros tipos de poderes
}
