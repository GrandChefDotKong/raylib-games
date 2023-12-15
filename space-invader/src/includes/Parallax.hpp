#include "params.hpp"

struct Background {
  std::string name;
  Vector2 position;
  Vector2 scrollingSpeed;
  const Texture2D* texture;
};

class Parallax {

  private:
    std::vector<Background> m_backgrounds;

  public:
    Parallax();
    void AddBackground(std::string name, Vector2 scrollingSpeed, const Texture2D* texture);
    void FixedUpdate();
    void Update();
    void Draw();

    ~Parallax();
};

