#include <SFML/Graphics.hpp>
#include "player.h"
#include "map.h"
using namespace sf;

int main(){
    Image map_image;
    map_image.loadFromFile("map.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    
    Sprite map_sprite; 
    map_sprite.setTexture(map_texture);


    RenderWindow window(VideoMode(800,800), "Horse'n Stone game");

    Player horse("stone.png", 50,25,90,90);


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
            window.draw(horse.get_sprite());
            window.display();

        
        }
    return 0;

}
