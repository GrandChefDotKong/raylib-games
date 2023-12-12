#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

  #include <map>
  #include <string>
  #include <SFML/Graphics.hpp>

  class TextureManager {
    public:
      TextureManager(TextureManager& other) = delete;
      void operator=(const TextureManager&) = delete;
      static TextureManager* getInstance();
      void addTexture(std::string textureName, sf::Texture& texture);
      sf::Texture* getTexture(std::string textureName);

    private:
      TextureManager() {};
      static TextureManager* m_textureManager;
      std::map<std::string, sf::Texture*> m_textures; 

  };

  TextureManager* TextureManager::m_textureManager = nullptr;  

  TextureManager* TextureManager::getInstance() {

    if(m_textureManager == nullptr) {
      m_textureManager = new TextureManager();
    }

    return m_textureManager;
    
  }

  void TextureManager::addTexture(std:: string textureName, sf::Texture& texture) {
    this->m_textures[textureName] = &texture;
  }

  sf::Texture* TextureManager::getTexture(std::string textureName) {
    return m_textures[textureName];
  }


  #endif