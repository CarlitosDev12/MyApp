#include <SFML/Graphics.hpp>

int main()
{
    // Crear la ventana
    sf::RenderWindow Screen(sf::VideoMode::getDesktopMode(), "Screen");
    Screen.setFramerateLimit(60);

    // Bucle ultra básico sin teclado virtual ni rutas externas
    while (Screen.isOpen())
    {
        while (const std::optional Event = Screen.pollEvent())
        {
            if (Event->is<sf::Event::Closed>())
            {
                Screen.close();
            }
        }

        // Si esto funciona, verás la pantalla de color Azul en tu celular
        Screen.clear(sf::Color::Blue);
        Screen.display();
    }

    return 0;
}
