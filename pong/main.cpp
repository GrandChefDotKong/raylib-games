#include <iostream>
#include <raylib.h>

const Color Green = Color{38, 185, 154, 255};
const Color Dark_Green = Color{20, 160, 133, 255};
const Color Light_Green = Color{129, 204, 184, 255};
const Color Yellow = Color{243, 213, 91, 255};

const int screenWidth = 1200;
const int screenHeight = 800;

const int speed_choices[2] = {-1, 1};

enum Score{
 NONE, PLAYER, CPU   
};


class Ball {
  private:
    float x, y;
    int speed_x, speed_y;
    int radius;

  public:
    Ball(float x, float y, int speed_x, int speed_y, int radius): 
    x(x), y(y), speed_x(speed_x), speed_y(speed_y), radius(radius) {
        this->speed_x *= speed_choices[GetRandomValue(0, 1)];
        this->speed_y *= speed_choices[GetRandomValue(0, 1)];
    }

    const Vector2 getDimensions() {
        return Vector2{this->x, this->y};
    }

    const int getRadius() {
        return this->radius;
    }

    void Draw() {
        DrawCircle(this->x, this->y, this->radius, Yellow);
    }

    void Update() {
        this->x += this->speed_x;
        this->y += this->speed_y;

        if(this->y + this->radius >= GetScreenHeight() || 
        this-> y - this->radius <= 0) {
            this->speed_y *= -1;
        }
/*
        if(this->x + this->radius >= GetScreenWidth() || this->x - this->radius <= 0) {
            this->speed_x *= -1;
        }
*/
    }

    void ReverseSpeed() {
        this->speed_x *= -1;
    }

    void Reset() {
        this->x = screenWidth / 2;
        this->y = screenHeight / 2;

        this->speed_x *= speed_choices[GetRandomValue(0, 1)];
        this->speed_y *= speed_choices[GetRandomValue(0, 1)];
    } 

};

class Paddle {
  protected:
    float x, y;
    float width, height;
    int speed;
    
    void HandleCollision() {
        if(this->y <= 10) {
                this->y = 10;
        }

        if(this->y + this->height >= GetScreenHeight() - 10) {
            this->y = GetScreenHeight() - this->height - 10;
        } 
    }


  public:
    Paddle(float x, float y, float width, float height, int speed): 
    x(x), y(y), width(width), height(height), speed(speed) {

    }
    
    const Rectangle getDimensions() {
        return Rectangle{this->x, this->y, float(this->width), float(this->height)};
    }

    void Draw() {
        DrawRectangleRounded(Rectangle{this->x, this->y, this->width, this->height}, 0.8, 0, WHITE);
    }

    virtual void Update() {

        if(IsKeyDown(KEY_UP)) {
            this->y -= this->speed;            
        }

        if(IsKeyDown(KEY_DOWN)) {
            this->y += this->speed;            
        }

        this->HandleCollision();
    }     
};

class CPUPaddle: public Paddle {
    public:
        CPUPaddle(float x, float y, int width, int height, int speed): Paddle(x, y, width, height, speed) {
        
        }

        void Update(float ball_y) {
            if(ball_y < this->y + (this->height/2)) {
                this->y -= this->speed;
            } else if(ball_y > this->y+ (this->height/2)) {
                this->y += this->speed;
            }

            Paddle::HandleCollision();
        } 
};

Score checkScore(float ball_x) {
    if(ball_x <= 0) {
        return CPU;
    }

    if(ball_x >= 1200) {
        return PLAYER;
    }

    return NONE;
}


int main () {


    Ball ball = Ball(screenWidth /2, screenHeight /2, 7, 7, 20);
    Paddle player = Paddle(25, (screenHeight/2) - 60, 25, 120, 7);
    CPUPaddle cpu = CPUPaddle(screenWidth - 50, (screenHeight/2) - 60, 25, 120, 7);

    unsigned int player_score(0);
    unsigned int cpu_score(0);

    std::cout << "Starting the game" << std::endl;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){

        ball.Update();
        player.Update();
        cpu.Update(ball.getDimensions().y);

        if(CheckCollisionCircleRec(ball.getDimensions(), ball.getRadius(), player.getDimensions())) {
            ball.ReverseSpeed();
        } else if(CheckCollisionCircleRec(ball.getDimensions(), ball.getRadius(), cpu.getDimensions())) {
            ball.ReverseSpeed();
        }


        Score score = checkScore(ball.getDimensions().x);

        switch (score)
        {
        case NONE:
            break;
        case PLAYER:
            player_score++;
            ball.Reset();
            break;
        case CPU:
            cpu_score++;
            ball.Reset();
            break;
        }

        ClearBackground(Dark_Green);
        BeginDrawing();
        DrawRectangle(0, 0, screenWidth/2, screenHeight, Green);
        DrawCircle(screenWidth/2, screenHeight/2, 120, Light_Green);  
        ball.Draw();
        player.Draw();
        cpu.Draw();
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
        DrawText(TextFormat("%i", player_score), screenWidth/4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", cpu_score), (3*screenWidth/4) - 20, 20, 80, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}