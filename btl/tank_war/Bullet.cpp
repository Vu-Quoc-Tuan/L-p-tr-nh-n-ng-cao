#include "Bullet.h"

BulletObject::BulletObject()
{
  //  x_value=0;
  //  y_value=0;
    is_move=false;
    start_time = std::chrono::high_resolution_clock::now();
    angle_bullet=0;

    type_bullet=normal;
}

bool BulletObject::load_image_bullet(SDL_Renderer* screen)
{
    bool temp;
    if(type_bullet==rocket){
        temp=Graphics::Loadimage_base("Image/bullet/bullet1.png",screen);

    }else if(type_bullet==laser){
        temp=Graphics::Loadimage_base("Image/bullet/bullet1.png",screen);
    }else{
        temp=Graphics::Loadimage_base("Image/bullet/bullet1.png",screen);
    }
    return temp;
}

void BulletObject::control_bullet(const Map& map_data, int targetX, int targetY)
{
    if(type_bullet==laser)
    {
        through_wall();

    }else if(type_bullet==rocket)
    {
        find_anyone(map_data, targetX, targetY);

    }else {
        Bouncing_bullet(map_data);
    }
}

void BulletObject::through_wall()
{
    float radians=angle_bullet*PI/ 180.0f;
    rect_.x-=sin(radians)*BULLET_SPEED;
    rect_.y+=cos(radians)*BULLET_SPEED;
}



void BulletObject::find_anyone(const Map& map_data, int targetX, int targetY) {
    path.clear();

    bool visited[32][30] = {{false}};
    std::vector<std::vector<std::pair<int, int>>> parent(32, std::vector<std::pair<int, int>>(30));
    int tempX[4] = {0, 0, -1, 1};
    int tempY[4] = {-1, 1, 0, 0};
    std::queue<std::pair<int, int>> wait;
    wait.push({rect_.y / TILE_SIZE, rect_.x / TILE_SIZE});

    while (!wait.empty()) {
        std::pair<int, int> top = wait.front();
        wait.pop();
        visited[top.first][top.second] = true;

        if(top.first==targetY/TILE_SIZE && top.second==targetX/TILE_SIZE) break;

        for (int i = 0; i < 4; i++) {
            int i1 = top.first + tempY[i];
            int j1 = top.second + tempX[i];

            if (i1 >= 0 && i1 < 32 && j1 >= 0 && j1 < 30) {
                if (map_data.tile[i1][j1] == 0 &&!visited[i1][j1]) {
                    parent[i1][j1] = std::make_pair(top.first, top.second);
                    wait.push({i1, j1});
                }
            }
        }
    }


    std::pair<int, int> Newcurrent = {targetY/TILE_SIZE, targetX/TILE_SIZE};
    while (Newcurrent.first >= tile_startY && Newcurrent.first < tile_endY && Newcurrent.second >= tile_startX && Newcurrent.second < tile_endX && Newcurrent!= std::make_pair(rect_.y/TILE_SIZE, rect_.x/TILE_SIZE)) {
        path.push_back(Newcurrent);
        Newcurrent = parent[Newcurrent.first][Newcurrent.second];
    }
   // path.push_back({rect_.y/TILE_SIZE, rect_.x/TILE_SIZE});
    std::reverse(path.begin(), path.end()); // Lật ngược chuỗi để có thứ tự từ start đến end
//    while(!path.empty()){
//        movent(map_data, path);
//        path.erase(path.begin());
//    }

}
void BulletObject::movent(const Map& map_data)
{
     if (path.empty()) return;

    std::pair<int,int> nextPos = path.front();
    float dentaX=nextPos.first-rect_.y/TILE_SIZE;
    float dentaY=nextPos.second-rect_.x/TILE_SIZE;

//    rect_.x = rect_.x +y1*TILE_SIZE;
//    rect_.y = rect_.y +x1*TILE_SIZE;

    if(dentaX==1 && dentaY==0) {
            rect_.y+=BULLET_SPEED/2;
            rect_.x=rect_.x/TILE_SIZE*TILE_SIZE+TILE_SIZE/2;
    }
    if(dentaX==-1 && dentaY==0){
            rect_.y-=BULLET_SPEED/2;
            rect_.x=rect_.x/TILE_SIZE*TILE_SIZE+TILE_SIZE/2;
    }
    if(dentaX==0 && dentaY==1) {
            rect_.x+=BULLET_SPEED/2;
            rect_.y=rect_.y/TILE_SIZE*TILE_SIZE+TILE_SIZE/2;
    }
    if(dentaX==0 && dentaY==-1) {
            rect_.x-=BULLET_SPEED/2;
            rect_.y=rect_.y/TILE_SIZE*TILE_SIZE+TILE_SIZE/2;
    }

    path.erase(path.begin());
}


void BulletObject::Bouncing_bullet(const Map& map_data) {
  float radians = angle_bullet * PI / 180.0f;


  float newx = rect_.x - sin(radians) * BULLET_SPEED;
  float newy = rect_.y + cos(radians) * BULLET_SPEED;

//kiểm tra vc
  bool quit=false;//sửa lỗi dính tường

  bool collided_x = false;
  bool collided_y = false;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int map_x = (int)newx / TILE_SIZE + i;
      int map_y = (int)newy / TILE_SIZE + j;

      if (map_x >= tile_startX && map_x < tile_endX && map_y >= tile_startY && map_y < tile_endY) {
        if (map_data.tile[map_y][map_x] > 0) {
          SDL_Rect Wall = { map_x * TILE_SIZE, map_y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
          SDL_Rect bullet1={newx,rect_.y,rect_.w,rect_.h};
          SDL_Rect bullet2={rect_.x,newy,rect_.w,rect_.h};

          //trục y
          if (detail::check_insize(bullet1, Wall)) {
            collided_x = true;
            angle_bullet = (-angle_bullet + 360) - (i * (BULLET_SPEED / TILE_SIZE) * 90);
            angle_bullet = fmodf(angle_bullet, 360.0f);
            break;
          }

          //trục x
          if (detail::check_insize(bullet2, Wall)) {
            collided_y = true;
            if (angle_bullet < 180) {
              angle_bullet = abs(-angle_bullet + 180) - (j * (BULLET_SPEED / TILE_SIZE) * 90);
            } else {
              angle_bullet = abs(-angle_bullet + 540) - (j * (BULLET_SPEED / TILE_SIZE) * 90);
              quit=true;
            }
            angle_bullet = fmodf(angle_bullet, 360.0f);
            break;
          }
        }
      }
    }
    if(quit) break;
  }

//update
  if (!collided_x) {
    rect_.x = newx;
  }
  if (!collided_y) {
    rect_.y = newy;
  }
}


void BulletObject::time_bullet(const int count_time)
{
    auto current_time = std::chrono::high_resolution_clock::now();

    // Tính toán thời gian đã trôi qua
    std::chrono::duration<float> elapsed_time = current_time - start_time;

    if(elapsed_time.count()>=count_time) {
            is_move=false;
    }
}

void BulletObject::render_bullet(SDL_Renderer* screen)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(screen,texture,NULL,&renderquad);
}