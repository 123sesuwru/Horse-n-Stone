#include <SFML/Graphics.hpp>
#include "player.h"
#include "map.h"
#include "view.h"
#include <ctime>
#include <cstdlib>
using namespace sf;


int main(){
    srand(time(NULL));
    Font font;
    font.loadFromFile("20016.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold | Text::Underlined);

    Text lives("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold | Text::Underlined);

    Image map_image;
    map_image.loadFromFile("map.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    
    Sprite map_sprite; 
    map_sprite.setTexture(map_texture);

    RenderWindow window(VideoMode(800,800), "Horse'n Stone game");

    view.reset(FloatRect(0,0,400,280));
    Player horse("stone.png", 100,100,90,90);


 Clock clock;


    while(window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
		time = time / 1000;	
		clock.restart();

        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
                window.close();
            }

            horse.control();
            horse.update(time);
            horse.run_animate(time);

            window.setView(view);
            window.clear(Color(108,235,235));
            for(int  h=0; h<HEIGHT_MAP;h++){
                for(int w=0; w<WIDTH_MAP; w++){
                    if(TileMap[h][w]=='h'){
                        map_sprite.setTextureRect(IntRect(64*0, 0, 64, 64));
                    }
                    if(TileMap[h][w]=='s'){
                        map_sprite.setTextureRect(IntRect(64*3, 0, 64, 64));
                    }
                    if(TileMap[h][w]=='l'){
                        map_sprite.setTextureRect(IntRect(64*2, 0, 64, 64));
                    }
                    if(TileMap[h][w]=='g'){
                        map_sprite.setTextureRect(IntRect(64*1, 0, 64, 64));
                    }
                    

                    map_sprite.setPosition(w*64, h*64);

                    window.draw(map_sprite);
                }
            }
            
            horse.map_touch();
            move_cam(horse.get_x(), horse.get_y());
            move_map(time);
            window.draw(horse.get_sprite());
            text.setString("Score : " + std::to_string(horse.get_score()));
            text.setPosition(view.getCenter().x+120, view.getCenter().y-120);
            window.draw(text);
            lives.setString("Lives : " + std::to_string(horse.get_lives()));
            lives.setPosition(view.getCenter().x+30, view.getCenter().y-120);
            window.draw(lives);
            window.display();

        
        }
    return 0;

}
