#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player{
private:
    String file_name;
    Image image;
    Texture texture;
    float center_x, center_y;
    float width, height;
    int direction;
    float speed;
    float accel;
    float change_x, change_y;
    float current_rect;
    float time;
    int max_frame;
    Sprite sprite;
public:
    Sprite get_sprite(){
        return sprite;
    }
    void check_frame(int frame_number);
    void update(float time);
    void control();
    void run_animate(float time);
    void check_frame();

    
    Player(String user_file, float user_center_x, float user_center_y, float user_width, float user_height, int max_frame);

};

Player::Player(String user_file, float user_center_x, float user_center_y, float user_width, float user_height, int user_max_frame=4){
    file_name=user_file;
    center_x = user_center_x;
    center_y = user_center_y;
    width = user_width;
    height = user_height;
    max_frame=user_max_frame;

    direction = 0;
    speed = 0;
    change_x = 0;
    change_y = 0;
    current_rect = 0;

    image.loadFromFile(file_name);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0, width, height));
    sprite.setPosition(center_x, center_y);
}

void Player::control(){

    if(Keyboard::isKeyPressed(Keyboard::Right)){
        direction = 0;
        speed=0.1;

    }

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        direction = 1;
        speed = 0.1;   
    }

    if(Keyboard::isKeyPressed(Keyboard::Up)){
        direction = 3;
        speed = 0.1;        
    }

    if(Keyboard::isKeyPressed(Keyboard::Down)){
        direction = 2;
        speed = 0.1;        
    }

}

void Player::check_frame(){
    if(current_rect>max_frame){
        current_rect-=max_frame;
    }
}

void Player::run_animate(float time){
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        current_rect+=time*0.005;
        check_frame();
        sprite.setTextureRect(IntRect(width*int(current_rect), 2*height, width, height));
    }

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        current_rect+=time*0.005;
        check_frame();
        sprite.setTextureRect(IntRect(width*int(current_rect), 1*height,width, height));
    }

    if(Keyboard::isKeyPressed(Keyboard::Up)){
        current_rect+=time*0.005;
        check_frame();
        sprite.setTextureRect(IntRect(width*int(current_rect), 3*height,width, height));
    }

    if(Keyboard::isKeyPressed(Keyboard::Down)){
        current_rect+=time*0.005;
        check_frame();
        sprite.setTextureRect(IntRect(width*int(current_rect), 0*height,width, height));
    }
    


}

void Player::update(float time){
    if(direction==0){
        change_x = speed;
        change_y = 0;
    }

    if(direction==1){
        change_x = -speed;
        change_y = 0;
    }
     
    if(direction==3){
        change_x = 0;
        change_y = -speed;
    }

    if(direction==2){
        change_x = 0;
        change_y = speed;
    }

    center_x+= change_x*time;
    center_y+= change_y*time;
    speed = 0;
    sprite.setPosition(center_x,center_y);

}