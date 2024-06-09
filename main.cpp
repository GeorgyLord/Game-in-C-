#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1024, 576), L"Новый проект", Style::Default);
    window.setVerticalSyncEnabled(true);

    //CircleShape shape(100.f, 3);
    //shape.setPosition(100, 100);
    //shape.setFillColor(Color::Magenta);

    int x = 0, y = 0;
    float zoom = 1;
    int speed_maving = 5;
    const int map_x = 10, map_y = 10;
    const int map[map_x][map_y] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    //ship
    int ship_width = 200;
    int ship_height = 50;

    // ship
    RectangleShape ship(Vector2f(ship_width * zoom, ship_height * zoom));
    ship.setFillColor(Color(128, 128, 128));
    ship.setOutlineThickness(1);
    ship.setOutlineColor(Color(0, 0, 0));
    ship.setPosition(0, 0);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Обработка нажатий на клавиш
        if (Keyboard::isKeyPressed(Keyboard::W)) { y += speed_maving; }
        if (Keyboard::isKeyPressed(Keyboard::S)) { y += -speed_maving; }
        if (Keyboard::isKeyPressed(Keyboard::D)) { x += -speed_maving; }
        if (Keyboard::isKeyPressed(Keyboard::A)) { x += speed_maving; }
        if (Keyboard::isKeyPressed(Keyboard::Q) && zoom >= 0.2) { zoom += -0.1; }
        if (Keyboard::isKeyPressed(Keyboard::E) && zoom <= 10) { zoom += 0.1; }
        //shape.setPosition(shape.getPosition().x+x, shape.getPosition().y + y);

        window.clear(); // Очищаем экран и закрашиваем чёрным цветом
        for (int i = 0; i < map_x; i++)
        {
            for (int j = 0; j < map_y; j++)
            {
                /*if (i * 50 * zoom + x > 0 && i * 50 * zoom + x < window.getSize().x &&
                    j * 50 * zoom + y > 0 && j * 50 * zoom + y < window.getSize().y) {
                    RectangleShape rect(Vector2f(50 * zoom, 50 * zoom));
                    rect.setFillColor(Color(0, 0, 255));
                    rect.setOutlineThickness(1);
                    rect.setOutlineColor(Color(0, 0, 0));
                    rect.setPosition(i * 50 * zoom + x, j * 50 * zoom + y);
                    window.draw(rect);
                    std::cout << 0;
                }*/
                RectangleShape rect(Vector2f(50 * zoom, 50 * zoom));
                rect.setFillColor(Color(0, 0, 255));
                rect.setOutlineThickness(1);
                rect.setOutlineColor(Color(0, 0, 0));
                rect.setPosition(i * 50 * zoom + x, j * 50 * zoom + y);
                window.draw(rect);
            }
        }

        window.draw(ship);
        window.display();
    }
    return 0;
}